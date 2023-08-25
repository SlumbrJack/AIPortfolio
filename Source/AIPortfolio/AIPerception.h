// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Perception/AIPerceptionComponent.h"
#include "AIPerception.generated.h"

/**
 * 
 */
UCLASS()
class AIPORTFOLIO_API UAIPerception : public UAIPerceptionComponent
{
	GENERATED_BODY()
public:
	DECLARE_EVENT(UAIPerception, OnTargetPerceptionUpdated)
	OnTargetPerceptionUpdated OnTargetPerceptionUpdate();
};
