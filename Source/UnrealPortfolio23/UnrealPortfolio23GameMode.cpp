// Copyright Epic Games, Inc. All Rights Reserved.

#include "UnrealPortfolio23GameMode.h"
#include "UnrealPortfolio23Character.h"
#include "UObject/ConstructorHelpers.h"

AUnrealPortfolio23GameMode::AUnrealPortfolio23GameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
