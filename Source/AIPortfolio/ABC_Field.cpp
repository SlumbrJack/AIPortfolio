// Fill out your copyright notice in the Description page of Project Settings.


#include "ABC_Field.h"
#include "Components/CapsuleComponent.h"
#include "AIPortfolioCharacter.h"
#include "Particles/ParticleSystemComponent.h"
// Sets default values
AABC_Field::AABC_Field()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	CapsuleComponent = CreateDefaultSubobject<UCapsuleComponent>(TEXT("Capsule Collider"));
	RootComponent = CapsuleComponent;
	CapsuleComponent->OnComponentBeginOverlap.AddDynamic(this, &AABC_Field::BeginOverlap);
	CapsuleComponent->OnComponentEndOverlap.AddDynamic(this, &AABC_Field::EndOverlap);
	ElementParticles = CreateDefaultSubobject<UParticleSystemComponent>(TEXT("Element Particles"));
	ElementParticles->SetupAttachment(CapsuleComponent);
	Tags.Add("ElementField");
}

// Called when the game starts or when spawned
void AABC_Field::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AABC_Field::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}
void AABC_Field::BeginOverlap(UPrimitiveComponent *OverlappedComponent, AActor *OtherActor, UPrimitiveComponent *OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult &SweepResult)
{
	if(OtherActor->ActorHasTag("Player"))
	{
		PlayerRef = Cast<AAIPortfolioCharacter>(OtherActor);
	}
}

void AABC_Field::EndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	if(OtherActor->ActorHasTag("Player"))
	{
		UE_LOG(LogTemp, Warning, TEXT("Overlap End"));
		PlayerRef = nullptr;
	}
}

void AABC_Field::ElementEffect()
{
	UE_LOG(LogTemp,Warning, TEXT("ParentFunctionCalled"));
}
