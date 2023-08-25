// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "UnrealPortfolio23/UnrealPortfolio23GameMode.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeUnrealPortfolio23GameMode() {}
// Cross Module References
	ENGINE_API UClass* Z_Construct_UClass_AGameModeBase();
	UNREALPORTFOLIO23_API UClass* Z_Construct_UClass_AUnrealPortfolio23GameMode();
	UNREALPORTFOLIO23_API UClass* Z_Construct_UClass_AUnrealPortfolio23GameMode_NoRegister();
	UPackage* Z_Construct_UPackage__Script_UnrealPortfolio23();
// End Cross Module References
	void AUnrealPortfolio23GameMode::StaticRegisterNativesAUnrealPortfolio23GameMode()
	{
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(AUnrealPortfolio23GameMode);
	UClass* Z_Construct_UClass_AUnrealPortfolio23GameMode_NoRegister()
	{
		return AUnrealPortfolio23GameMode::StaticClass();
	}
	struct Z_Construct_UClass_AUnrealPortfolio23GameMode_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AUnrealPortfolio23GameMode_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AGameModeBase,
		(UObject* (*)())Z_Construct_UPackage__Script_UnrealPortfolio23,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AUnrealPortfolio23GameMode_Statics::Class_MetaDataParams[] = {
		{ "HideCategories", "Info Rendering MovementReplication Replication Actor Input Movement Collision Rendering HLOD WorldPartition DataLayers Transformation" },
		{ "IncludePath", "UnrealPortfolio23GameMode.h" },
		{ "ModuleRelativePath", "UnrealPortfolio23GameMode.h" },
		{ "ShowCategories", "Input|MouseInput Input|TouchInput" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_AUnrealPortfolio23GameMode_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AUnrealPortfolio23GameMode>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_AUnrealPortfolio23GameMode_Statics::ClassParams = {
		&AUnrealPortfolio23GameMode::StaticClass,
		"Game",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		nullptr,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		0,
		0,
		0x008802ACu,
		METADATA_PARAMS(Z_Construct_UClass_AUnrealPortfolio23GameMode_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_AUnrealPortfolio23GameMode_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_AUnrealPortfolio23GameMode()
	{
		if (!Z_Registration_Info_UClass_AUnrealPortfolio23GameMode.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_AUnrealPortfolio23GameMode.OuterSingleton, Z_Construct_UClass_AUnrealPortfolio23GameMode_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_AUnrealPortfolio23GameMode.OuterSingleton;
	}
	template<> UNREALPORTFOLIO23_API UClass* StaticClass<AUnrealPortfolio23GameMode>()
	{
		return AUnrealPortfolio23GameMode::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(AUnrealPortfolio23GameMode);
	AUnrealPortfolio23GameMode::~AUnrealPortfolio23GameMode() {}
	struct Z_CompiledInDeferFile_FID_Users_thega_Documents_Unreal_Projects_UnrealPortfolio23_Source_UnrealPortfolio23_UnrealPortfolio23GameMode_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_thega_Documents_Unreal_Projects_UnrealPortfolio23_Source_UnrealPortfolio23_UnrealPortfolio23GameMode_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_AUnrealPortfolio23GameMode, AUnrealPortfolio23GameMode::StaticClass, TEXT("AUnrealPortfolio23GameMode"), &Z_Registration_Info_UClass_AUnrealPortfolio23GameMode, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(AUnrealPortfolio23GameMode), 1670429973U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_thega_Documents_Unreal_Projects_UnrealPortfolio23_Source_UnrealPortfolio23_UnrealPortfolio23GameMode_h_1877035113(TEXT("/Script/UnrealPortfolio23"),
		Z_CompiledInDeferFile_FID_Users_thega_Documents_Unreal_Projects_UnrealPortfolio23_Source_UnrealPortfolio23_UnrealPortfolio23GameMode_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Users_thega_Documents_Unreal_Projects_UnrealPortfolio23_Source_UnrealPortfolio23_UnrealPortfolio23GameMode_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
