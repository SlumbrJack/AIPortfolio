// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/Services/BTService_BlackboardBase.h"
#include "BTService_FindRandomLocation.generated.h"

/**
 * 
 */
UCLASS()
class AIPORTFOLIO_API UBTService_FindRandomLocation : public UBTService_BlackboardBase
{
	GENERATED_BODY()
public:
	UBTService_FindRandomLocation();
	UPROPERTY(EditAnywhere)
	float SearchRadius = 500.f;
protected:
	virtual void TickNode(UBehaviorTreeComponent &OwnerComp, uint8 *NodeMemory, float DeltaSeconds);
private:
	FVector AICurrentLocation;
	FVector RandomTargetLocation;

};
