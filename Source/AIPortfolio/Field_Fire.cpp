// Fill out your copyright notice in the Description page of Project Settings.


#include "Field_Fire.h"
#include "AIPortfolioCharacter.h"
AField_Fire::AField_Fire()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;


}

// Called when the game starts or when spawned
void AField_Fire::BeginPlay()
{
	Super::BeginPlay();
	
}
// Called every frame
void AField_Fire::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	ElementEffect();
}
void AField_Fire::ElementEffect()
{
    if(PlayerRef != nullptr && bCanTakeDamage)
	{
        UE_LOG(LogTemp, Warning, TEXT("BURN2"));
		PlayerRef->CurrentHP -= 10.0f;
		bCanTakeDamage = false;
		GetWorldTimerManager().SetTimer(DamageTimer, this, &AField_Fire::DamageAgain, DamageDelay);
	}
}

void AField_Fire::DamageAgain()
{
    bCanTakeDamage = true;
}


