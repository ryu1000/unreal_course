// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Escape_Room/Escape_RoomGameModeBase.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeEscape_RoomGameModeBase() {}
// Cross Module References
	ESCAPE_ROOM_API UClass* Z_Construct_UClass_AEscape_RoomGameModeBase_NoRegister();
	ESCAPE_ROOM_API UClass* Z_Construct_UClass_AEscape_RoomGameModeBase();
	ENGINE_API UClass* Z_Construct_UClass_AGameModeBase();
	UPackage* Z_Construct_UPackage__Script_Escape_Room();
// End Cross Module References
	void AEscape_RoomGameModeBase::StaticRegisterNativesAEscape_RoomGameModeBase()
	{
	}
	UClass* Z_Construct_UClass_AEscape_RoomGameModeBase_NoRegister()
	{
		return AEscape_RoomGameModeBase::StaticClass();
	}
	struct Z_Construct_UClass_AEscape_RoomGameModeBase_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AEscape_RoomGameModeBase_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AGameModeBase,
		(UObject* (*)())Z_Construct_UPackage__Script_Escape_Room,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AEscape_RoomGameModeBase_Statics::Class_MetaDataParams[] = {
		{ "HideCategories", "Info Rendering MovementReplication Replication Actor Input Movement Collision Rendering Utilities|Transformation" },
		{ "IncludePath", "Escape_RoomGameModeBase.h" },
		{ "ModuleRelativePath", "Escape_RoomGameModeBase.h" },
		{ "ShowCategories", "Input|MouseInput Input|TouchInput" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_AEscape_RoomGameModeBase_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AEscape_RoomGameModeBase>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_AEscape_RoomGameModeBase_Statics::ClassParams = {
		&AEscape_RoomGameModeBase::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		nullptr,
		nullptr,
		ARRAY_COUNT(DependentSingletons),
		0,
		0,
		0,
		0x009002A8u,
		METADATA_PARAMS(Z_Construct_UClass_AEscape_RoomGameModeBase_Statics::Class_MetaDataParams, ARRAY_COUNT(Z_Construct_UClass_AEscape_RoomGameModeBase_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_AEscape_RoomGameModeBase()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_AEscape_RoomGameModeBase_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(AEscape_RoomGameModeBase, 1633707219);
	template<> ESCAPE_ROOM_API UClass* StaticClass<AEscape_RoomGameModeBase>()
	{
		return AEscape_RoomGameModeBase::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_AEscape_RoomGameModeBase(Z_Construct_UClass_AEscape_RoomGameModeBase, &AEscape_RoomGameModeBase::StaticClass, TEXT("/Script/Escape_Room"), TEXT("AEscape_RoomGameModeBase"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(AEscape_RoomGameModeBase);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
