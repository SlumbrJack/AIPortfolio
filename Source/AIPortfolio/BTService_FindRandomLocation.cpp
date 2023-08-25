// Fill out your copyright notice in the Description page of Project Settings.


#include "BTService_FindRandomLocation.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "AIController.h"
#include "NavigationSystem.h"
UBTService_FindRandomLocation::UBTService_FindRandomLocation()
{
    NodeName = "Find Random Location";
}

void UBTService_FindRandomLocation::TickNode(UBehaviorTreeComponent &OwnerComp, uint8 *NodeMemory, float DeltaSeconds)
{
    Super::TickNode(OwnerComp, NodeMemory, DeltaSeconds);
    AICurrentLocation = OwnerComp.GetAIOwner()->GetPawn()->GetActorLocation();
    UNavigationSystemV1* NavArea = FNavigationSystem::GetCurrent<UNavigationSystemV1>(this);
    if(NavArea)
    {
        FVector startPosition = AICurrentLocation;
        FNavLocation endPosition = FNavLocation(AICurrentLocation);
        NavArea->GetRandomReachablePointInRadius(startPosition, SearchRadius, endPosition);
        UE_LOG(LogTemp, Warning, TEXT("Random Point: %s"), *endPosition.Location.ToString());
        OwnerComp.GetBlackboardComponent()->SetValueAsVector(GetSelectedBlackboardKey(), endPosition);
    }
}
