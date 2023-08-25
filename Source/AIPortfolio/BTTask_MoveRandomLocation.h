// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/Tasks/BTTask_MoveTo.h"
#include "BTTask_MoveRandomLocation.generated.h"

/**
 * 
 */
UCLASS()
class AIPORTFOLIO_API UBTTask_MoveRandomLocation : public UBTTask_MoveTo
{
	GENERATED_BODY()
	private:
	FVector AiCurrentLocation;
	FVector RandomTargetLocation;

public:
	UBTTask_MoveRandomLocation();
	UPROPERTY(EditAnywhere)
	float SearchRadius = 500.f;


protected:
	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent &OwnerComp, uint8 *NodeMemory) override;
};
