// Copyright Coffee Stain Studios. All Rights Reserved.

#pragma once

#include "FactoryGame.h"
#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "Settings/FGUserSetting.h"
#include "Settings/FGUserSettingCategory.h"
#include "FGOptionsLibrary.generated.h"

/**
 * @todok2 do we even need this library anymore?
 */
UCLASS()
class FACTORYGAME_API UFGOptionsLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
	
public:

	/** Returns all user settings available in the game that belongs in the given manager type. The settings are sorted by MenuPriority
	 * Triggers a scan of user settings directory from PrimaryAssetTypesToScan to make sure we loaded all assets
	 * @param manager The manager that will manage the found user settings
	 * @param managerType The type of the manager @todok2 this could be fetched from the manager to avoid this extra variable.
	 * @param out_userSettings Will be populated with the found settings
	 */
	static void GatherUserSettings( UObject* manager, EUserSettingManagers managerType, TMap< FString, class UFGUserSettingApplyType* >& out_userSettings );

	/** Returns categorized option row widgets as well as setting up suboption for these widgets
	 * @param worldContext Needed so we can check if each setting should be shown in the current config 
	 * @param owningWidget The widget that will be the owner of the new option row widgets
	 * @param optionInterface The interface that manages the user settings
	 * @param userSettings The setting to create the option row from
	 */
	static TArray<FUserSettingCategoryMapping> GetCategorizedUserSettingsWidgets( UObject* worldContext, UUserWidget* owningWidget, TScriptInterface<class IFGOptionInterface> optionInterface, TMap< FString, class UFGUserSettingApplyType* > userSettings );

	/** Creates a option row widget for the given user setting
	 * @param owningWidget The widget that will be the owner of the new option row widget 
	 * @param userSetting The setting to create the option row from
	 * @param optionInterface The interface that manages the user setting
	 */
	static UFGDynamicOptionsRow* SetupUserSetting( UUserWidget* owningWidget, class UFGUserSetting* userSetting, TScriptInterface< class IFGOptionInterface > optionInterface );

};
