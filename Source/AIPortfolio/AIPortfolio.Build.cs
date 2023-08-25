// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class AIPortfolio : ModuleRules
{
	public AIPortfolio(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "HeadMountedDisplay", "EnhancedInput", "NavigationSystem", "GameplayTasks" });
	}
}
