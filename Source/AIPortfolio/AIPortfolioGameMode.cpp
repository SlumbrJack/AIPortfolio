// Copyright Epic Games, Inc. All Rights Reserved.

#include "AIPortfolioGameMode.h"
#include "AIPortfolioCharacter.h"
#include "UObject/ConstructorHelpers.h"

AAIPortfolioGameMode::AAIPortfolioGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
