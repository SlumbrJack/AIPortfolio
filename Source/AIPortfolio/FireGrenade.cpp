// Fill out your copyright notice in the Description page of Project Settings.


#include "FireGrenade.h"
#include "Components/CapsuleComponent.h"
#include "Components/BoxComponent.h"
#include "FireField.h"
#include "ABC_Field.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "GameFramework/MovementComponent.h"
// Sets default values
AFireGrenade::AFireGrenade()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	BoxComponent = CreateDefaultSubobject<UBoxComponent>(TEXT("Box Collider"));
	RootComponent = BoxComponent;
	AirMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Air Mesh"));
	AirMesh->SetupAttachment(BoxComponent);

	BoxComponent->OnComponentHit.AddDynamic(this, &AFireGrenade::BeginOverlap);
	//MovementComponent->CreateDefaultSubobject<UMovementComponent>(TEXT("MovementComp"));
	
	ProjectileMovement =CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("Projectile Movement"));
	ProjectileMovement->Velocity = FVector(0,0,0);
	ProjectileMovement->bSimulationEnabled = false;
	ProjectileMovement->InitialSpeed = 0;
	ProjectileMovement->MaxSpeed = 1300;
	/*
	//ProjectileMovement->Velocity.X = ThrowDistance;
	//ProjectileMovement->Velocity.Z = 0;
	
	
	BoxComponent->SetEnableGravity(false);
	
*/
}

// Called when the game starts or when spawned
void AFireGrenade::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AFireGrenade::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AFireGrenade::ChangeThrowValues()
{
	BoxComponent->SetEnableGravity(true);
	//ProjectileMovement->bSimulationEnabled = true;
	//ProjectileMovement->Velocity = FVector(2, 0, 1);
	//ProjectileMovement->InitialSpeed = 1300;
	//ProjectileMovement->AddForce(FVector(1, 1, 1));

}

void AFireGrenade::BeginOverlap(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{
	UE_LOG(LogTemp, Warning, TEXT("Overlapped: %s"), *OtherActor->GetName());
	if(OtherActor->ActorHasTag(TEXT("Ground")) && !isGrounded)
	{
		isGrounded = true;
		
		
		//BoxComponent->SetBoxExtent(FVector(BoxComponent->GetPlacementExtent().BoxExtent.X, BoxComponent->GetPlacementExtent().BoxExtent.Y, 0.5));
		
		
		GetWorld()->SpawnActor<AABC_Field>(FieldClass, this->GetTransform());
		K2_DestroyActor();
	}
	
}
