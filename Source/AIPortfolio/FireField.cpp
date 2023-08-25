// Fill out your copyright notice in the Description page of Project Settings.


#include "FireField.h"
#include "Components/CapsuleComponent.h"
#include "AIPortfolioCharacter.h"
// Sets default values
AFireField::AFireField()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	CapsuleComponent = CreateDefaultSubobject<UCapsuleComponent>(TEXT("Capsule Collider"));
	RootComponent = CapsuleComponent;
	//BaseMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Air Mesh"));
	//BaseMesh->SetupAttachment(CapsuleComponent);
	CapsuleComponent->OnComponentBeginOverlap.AddDynamic(this, &AFireField::BeginOverlap);
	CapsuleComponent->OnComponentEndOverlap.AddDynamic(this, &AFireField::EndOverlap);

}

// Called when the game starts or when spawned
void AFireField::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AFireField::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if(PlayerRef != nullptr && bCanTakeDamage)
	{
		UE_LOG(LogTemp, Warning, TEXT("BURN2"));
		PlayerRef->CurrentHP -= 10.0f;
		bCanTakeDamage = false;
		GetWorldTimerManager().SetTimer(DamageTimer, this, &AFireField::DamageAgain, DamageDelay);
	}
}



void AFireField::BeginOverlap(UPrimitiveComponent *OverlappedComponent, AActor *OtherActor, UPrimitiveComponent *OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult &SweepResult)
{
	if(OtherActor->ActorHasTag("Player"))
	{
		PlayerRef = Cast<AAIPortfolioCharacter>(OtherActor);
	}
}

void AFireField::EndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	if(OtherActor->ActorHasTag("Player"))
	{
		UE_LOG(LogTemp, Warning, TEXT("Overlap End"));
		PlayerRef = nullptr;
	}
}

void AFireField::DamageAgain()
{
	bCanTakeDamage = true;
}
