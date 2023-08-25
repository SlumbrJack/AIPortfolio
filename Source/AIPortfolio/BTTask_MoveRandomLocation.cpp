// Fill out your copyright notice in the Description page of Project Settings.


#include "BTTask_MoveRandomLocation.h"
#include "NavigationSystem.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "AIController.h"
#include "BehaviorTree/Blackboard/BlackboardKeyType_Vector.h"
#include "Kismet/GameplayStatics.h"
UBTTask_MoveRandomLocation::UBTTask_MoveRandomLocation()
{
	NodeName = "Find Random Location";
}
EBTNodeResult::Type UBTTask_MoveRandomLocation::ExecuteTask(UBehaviorTreeComponent &OwnerComp, uint8 *NodeMemory)
{
  /*
    Super::ExecuteTask(OwnerComp, NodeMemory);
    if (GetWorld())
    {

        UNavigationSystemV1 *navSystem = UNavigationSystemV1::GetCurrent(GetWorld());
        if (navSystem)
        {
            FVector startPosition = OwnerComp.GetAIOwner()->GetPawn()->GetActorLocation();
            FNavLocation endPosition = FNavLocation(startPosition);
            if (navSystem->GetRandomReachablePointInRadius(startPosition, 1000, endPosition))
            {
                FBlackboard::FKey BlackboardKey_MoveToLocation = OwnerComp.GetBlackboardComponent()->GetKeyID("MoveToLocation");
                OwnerComp.GetBlackboardComponent()->SetValue<UBlackboardKeyType_Vector>(BlackboardKey_MoveToLocation, endPosition.Location);
                return EBTNodeResult::Succeeded;
            }
        }
    }
   
    return EBTNodeResult::Failed;


    //EBTNodeResult::Type resultFromSuperExecution = Super::ExecuteTask(OwnerComp, NodeMemory);
	// check that we successfully grabbed the BehaviorTreeComp, BlackboardComp, AIController, and BotCharacter
	if (true) {
		// check that we can get the World
		if (GetWorld()) {
            UE_LOG(LogTemp, Warning, TEXT("Invalid pos"));
			// get the current nav system from the world
			UNavigationSystemV1* navSystem = FNavigationSystem::GetCurrent<UNavigationSystemV1>(this);
			// check that we have a nav system
			if (navSystem) {
				// get our actors current location to pe used as our start position
				FVector startPosi = OwnerComp.GetAIOwner()->GetPawn()->GetActorLocation();
				// create a nav location to be used as our end position 
				// default will be set to our current position in case of failure to find a suitable end position
				FNavLocation endPosi = FNavLocation(startPosi);
				// attempt to get a random new position
				if (navSystem->GetRandomReachablePointInRadius(startPosi, 100.0f, endPosi)) {
                 navSystem->GetRandomReachablePointInRadius(this, startPosi, 100.0f);
					// if we were successfull in finding a new location get the MoveToLocation BlackboardKeyID
                    UBlackboardComponent* Blackboard = OwnerComp.GetBlackboardComponent();
					FBlackboard::FKey BlackboardKey_MoveToLocation = Blackboard->GetKeyID("MoveToLocation");
					// check that we got the key
                    
					if (Blackboard->IsValidKey( BlackboardKey_MoveToLocation)) {
						// set the MoveToLocation BlackboardKeyID to our new location
						Blackboard->SetValue<UBlackboardKeyType_Vector>(BlackboardKey_MoveToLocation, endPosi.Location);
						// return succeeded now that we have set up our new loacation
						return EBTNodeResult::Succeeded;
					}
					else {
						// return Aborted if we can't find the Key as it will never succeed without a proper Key
						return EBTNodeResult::Aborted;
					}
				}
                else
                {
                    UE_LOG(LogTemp, Warning, TEXT("Got Dogged"));
                }
				// return in progress if their are currently no valid locations
				
				return EBTNodeResult::InProgress;
			}
            else
                {
                    UE_LOG(LogTemp, Warning, TEXT("Invalid pos"));
                }
		}
		 
		
	}
    else
                {
                    UE_LOG(LogTemp, Warning, TEXT("Invalid pos"));
                }
	// we will only get here if execution fails so we will check if force success is on

	// we want to return Failed after the force success check
	return EBTNodeResult::Failed;
    */
   Super::ExecuteTask(OwnerComp, NodeMemory);

	AiCurrentLocation = OwnerComp.GetAIOwner()->GetPawn()->GetActorLocation();
	UNavigationSystemV1* NavArea = FNavigationSystem::GetCurrent<UNavigationSystemV1>(this);
	if (NavArea)
	{
        FVector startPosi = OwnerComp.GetAIOwner()->GetPawn()->GetActorLocation();
        APawn *PlayerPawn = UGameplayStatics::GetPlayerPawn(GetWorld(), 0);
        FNavLocation endPosi = FNavLocation(PlayerPawn->GetActorLocation());
        NavArea->GetRandomPoint(endPosi);
        UE_LOG(LogTemp, Warning, TEXT("Random Point: %s"), *endPosi.Location.ToString());
         OwnerComp.GetBlackboardComponent()->SetValueAsVector(GetSelectedBlackboardKey(), endPosi.Location);
        /*
        
        if(PlayerPawn)
        {
            
        
            //RandomTargetLocation = NavArea->GetRandomReachablePointInRadius(this, AiCurrentLocation, SearchRadius);
            
            
           
        }
        */
        
        
	}

	return EBTNodeResult::Succeeded;
}
