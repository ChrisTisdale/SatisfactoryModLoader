// Copyright Coffee Stain Studios. All Rights Reserved.

#pragma once

#include "FactoryGame.h"
#include "UObject/Object.h"
#include "FGGlobalSettings.generated.h"


UCLASS( config = Game, defaultconfig, meta = ( DisplayName = "Settings Classes" ) )
class FACTORYGAME_API UFGGlobalSettings : public UDeveloperSettings
{
	GENERATED_BODY()
	
public:
	static const UFGGlobalSettings* Get() { return GetDefault<UFGGlobalSettings>(); };

	UFUNCTION( BlueprintPure, Category = "Settings" )
	static class UFGFactorySettings* GetFactorySettingsCDO();

	UFUNCTION( BlueprintPure, Category = "Settings" )
	static class UFGDropPodSettings* GetDropPodSettingsCDO();

	UFUNCTION( BlueprintPure, Category = "Settings" )
	static class UFGHardDriveSettings* GetHardDriveSettingsCDO();

	UFUNCTION( BlueprintPure, Category = "Settings" )
	static class UFGEnvironmentSettings* GetEnvironmentSettingsCDO();

	UFUNCTION( BlueprintPure, Category = "Settings" )
	static class UFGIconLibrary* GetIconLibraryCDO();

	UFUNCTION( BlueprintPure, Category = "Settings" )
	static class UFGServerManagerSettings* GetServerManagerSettingsCDO();

	/** Settings for resources */
	UPROPERTY( Config, EditDefaultsOnly, Category = "Settings" )
	TSoftClassPtr< class UFGFactorySettings > mFactorySettings;
	
	/** Settings for drop pods */
	UPROPERTY( Config, EditDefaultsOnly, Category = "Settings" )
	TSoftClassPtr< class UFGDropPodSettings > mDropPodSettings;

	/** Settings for Hard Drive Research */
	UPROPERTY( Config, EditDefaultsOnly, Category = "Settings" )
	TSoftClassPtr< class UFGHardDriveSettings > mHardDriveSettings;

	/** Settings for drop pods */
	UPROPERTY( Config, EditDefaultsOnly, Category = "Settings" )
	TSoftClassPtr< class UFGEnvironmentSettings > mEnvironmentSettings;

	UPROPERTY( Config, EditDefaultsOnly, Category = "Settings" )
	TSoftClassPtr< class UFGIconLibrary > mIconLibrary;

	/** Settings for the server manager, which lives on the client */
	UPROPERTY( Config, EditDefaultsOnly, Category = "Settings" )
	TSoftClassPtr< class UFGServerManagerSettings > mServerManagerSettings;
};
