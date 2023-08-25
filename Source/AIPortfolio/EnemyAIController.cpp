// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemyAIController.h"
#include "Kismet/GameplayStatics.h"
#include "Perception/AIPerceptionComponent.h"
#include "AIController.h"

void AEnemyAIController::BeginPlay()
{
    Super::BeginPlay();
    if(AIBehavior != nullptr)
    {
        RunBehaviorTree(AIBehavior);
    }
    //FString name = GetPerceptionComponent()->GetName();
    //UE_LOG(LogTemp, Warning, TEXT("Name: %s"), *FString(name));
    //UAIPerceptionComponent *perceptionComponent = GetPerceptionComponent();
    
    //perceptionComponent->ConfigureSense(UAISenseConfig)
}
void AEnemyAIController::Tick(float DeltaSeconds)
{
    Super::Tick(DeltaSeconds);
}


