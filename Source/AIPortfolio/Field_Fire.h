// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ABC_Field.h"
#include "Field_Fire.generated.h"

/**
 * 
 */
UCLASS()
class AIPORTFOLIO_API AField_Fire : public AABC_Field
{
	GENERATED_BODY()
public:
	AField_Fire();
	virtual void Tick(float DeltaTime) override;

protected: 
	virtual void BeginPlay() override;
	virtual void ElementEffect() override;
private:
	FTimerHandle DamageTimer;
	float DamageDelay = 1.0f;
	void DamageAgain();
	bool bCanTakeDamage = true;
	
};
