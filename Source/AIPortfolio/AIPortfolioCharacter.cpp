// Copyright Epic Games, Inc. All Rights Reserved.

#include "AIPortfolioCharacter.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "Components/InputComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/Controller.h"
#include "GameFramework/SpringArmComponent.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "FireGrenade.h"
#include "GameFramework/Actor.h"


//////////////////////////////////////////////////////////////////////////
// AAIPortfolioCharacter

AAIPortfolioCharacter::AAIPortfolioCharacter()
{
	// Set size for collision capsule
	GetCapsuleComponent()->InitCapsuleSize(42.f, 96.0f);
		
	// Don't rotate when the controller rotates. Let that just affect the camera.
	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;

	// Configure character movement
	GetCharacterMovement()->bOrientRotationToMovement = true; // Character moves in the direction of input...	
	GetCharacterMovement()->RotationRate = FRotator(0.0f, 500.0f, 0.0f); // ...at this rotation rate

	// Note: For faster iteration times these variables, and many more, can be tweaked in the Character Blueprint
	// instead of recompiling to adjust them
	GetCharacterMovement()->JumpZVelocity = 700.f;
	GetCharacterMovement()->AirControl = 0.35f;
	GetCharacterMovement()->MaxWalkSpeed = 500.f;
	GetCharacterMovement()->MinAnalogWalkSpeed = 20.f;
	GetCharacterMovement()->BrakingDecelerationWalking = 2000.f;

	// Create a camera boom (pulls in towards the player if there is a collision)
	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
	CameraBoom->SetupAttachment(RootComponent);
	CameraBoom->TargetArmLength = 400.0f; // The camera follows at this distance behind the character	
	CameraBoom->bUsePawnControlRotation = true; // Rotate the arm based on the controller

	// Create a follow camera
	FollowCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("FollowCamera"));
	FollowCamera->SetupAttachment(CameraBoom, USpringArmComponent::SocketName); // Attach the camera to the end of the boom and let the boom adjust to match the controller orientation
	FollowCamera->bUsePawnControlRotation = false; // Camera does not rotate relative to arm

	// Note: The skeletal mesh and anim blueprint references on the Mesh component (inherited from Character) 
	// are set in the derived blueprint asset named ThirdPersonCharacter (to avoid direct content references in C++)
}

void AAIPortfolioCharacter::BeginPlay()
{
	// Call the base class  
	Super::BeginPlay();

	//Add Input Mapping Context
	if (APlayerController* PlayerController = Cast<APlayerController>(Controller))
	{
		CurrentHP = MaxHP;
		if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(PlayerController->GetLocalPlayer()))
		{
			Subsystem->AddMappingContext(DefaultMappingContext, 0);
		}
	}

}



//////////////////////////////////////////////////////////////////////////
// Input

void AAIPortfolioCharacter::SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent)
{
	// Set up action bindings
	if (UEnhancedInputComponent* EnhancedInputComponent = CastChecked<UEnhancedInputComponent>(PlayerInputComponent)) {
		
		//Jumping
		EnhancedInputComponent->BindAction(JumpAction, ETriggerEvent::Triggered, this, &ACharacter::Jump);
		EnhancedInputComponent->BindAction(JumpAction, ETriggerEvent::Completed, this, &ACharacter::StopJumping);

		//Primary
		EnhancedInputComponent->BindAction(PrimaryAction, ETriggerEvent::Triggered, this, &AAIPortfolioCharacter::PrimaryAttack);

		//Secondary
		EnhancedInputComponent->BindAction(SecondaryAction, ETriggerEvent::Triggered, this, &AAIPortfolioCharacter::ChargeGrenade);
		EnhancedInputComponent->BindAction(SecondaryAction, ETriggerEvent::Completed, this, &AAIPortfolioCharacter::SecondaryAttack);
		//Moving
		EnhancedInputComponent->BindAction(MoveAction, ETriggerEvent::Triggered, this, &AAIPortfolioCharacter::Move);

		//Looking
		EnhancedInputComponent->BindAction(LookAction, ETriggerEvent::Triggered, this, &AAIPortfolioCharacter::Look);
	
	}

}

void AAIPortfolioCharacter::Move(const FInputActionValue& Value)
{
	// input is a Vector2D
	FVector2D MovementVector = Value.Get<FVector2D>();

	if (Controller != nullptr)
	{
		// find out which way is forward
		const FRotator Rotation = Controller->GetControlRotation();
		const FRotator YawRotation(0, Rotation.Yaw, 0);

		// get forward vector
		const FVector ForwardDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
	
		// get right vector 
		const FVector RightDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);

		// add movement 
		AddMovementInput(ForwardDirection, MovementVector.Y);
		AddMovementInput(RightDirection, MovementVector.X);
	}
}

void AAIPortfolioCharacter::Look(const FInputActionValue& Value)
{
	// input is a Vector2D
	FVector2D LookAxisVector = Value.Get<FVector2D>();

	if (Controller != nullptr)
	{
		// add yaw and pitch input to controller
		AddControllerYawInput(LookAxisVector.X);
		AddControllerPitchInput(LookAxisVector.Y);
	}
}

void AAIPortfolioCharacter::PrimaryAttack()
{
	UE_LOG(LogTemp, Warning, TEXT("Yo mama deez"));
}

void AAIPortfolioCharacter::SecondaryAttack()
{
		if(true)
		{
			FVector grenadelocation = this->GetTransform().GetLocation();
		grenadelocation.Z = grenadelocation.Z + 150;
			FakeGrenadeRef->Destroy();
			GrenadeRef = GetWorld()->SpawnActor<AFireGrenade>(GrenadeBP, grenadelocation, this->GetTransform().Rotator());
			UE_LOG(LogTemp, Warning, TEXT("Boom: %f"), GrenadeThrowStrength);

			GrenadeRef->ChangeThrowValues(GrenadeThrowStrength);
			GrenadeRef = nullptr;
			GetWorldTimerManager().SetTimer(GrenadeCooldownTimer, this, &AAIPortfolioCharacter::GrenadeCooldownToggle, GrenadeCooldown);
			GrenadeThrowStrength = 0;
		}
		
	
}

void AAIPortfolioCharacter::GrenadeCooldownToggle()
{
	bCanThrowGrenade = true;
}

void AAIPortfolioCharacter::ChargeGrenade()
{
	if(bCanThrowGrenade)
	{
		
		FVector grenadelocation = this->GetTransform().GetLocation();
		grenadelocation.Z = grenadelocation.Z + 150;
		/*
		GrenadeRef = GetWorld()->SpawnActor<AFireGrenade>(GrenadeBP, grenadelocation, this->GetTransform().Rotator());
		*/
		FakeGrenadeRef = GetWorld()->SpawnActor<AActor>(FakeGrenadeBP, grenadelocation, this->GetTransform().Rotator());
		bCanThrowGrenade = false;
	}
	if(GrenadeThrowStrength < 2)
	{
		GrenadeThrowStrength += 0.05;
		UE_LOG(LogTemp, Warning, TEXT(" %f"), GrenadeThrowStrength);
		//update grenade location to stay above player
	}
	
}
