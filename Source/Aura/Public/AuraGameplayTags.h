// Copyright TwinFaerie, for use on online course by Druid Mechanic only

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"

/**
 * 
 */
struct FAuraGameplayTags
{
public:
 static const FAuraGameplayTags Get() { return GameplayTags; }
 static void InitializeNativeGameplayTags();
 
 FGameplayTag Attribute_Vital_Health;
 FGameplayTag Attribute_Vital_Mana;
 
 FGameplayTag Attribute_Primary_Strength;
 FGameplayTag Attribute_Primary_Intelligence;
 FGameplayTag Attribute_Primary_Resilience;
 FGameplayTag Attribute_Primary_Vigor;

 FGameplayTag Attribute_Secondary_Armor;
 FGameplayTag Attribute_Secondary_ArmorPenetration;
 FGameplayTag Attribute_Secondary_BlockChance;
 FGameplayTag Attribute_Secondary_CriticalChance;
 FGameplayTag Attribute_Secondary_CriticalDamage;
 FGameplayTag Attribute_Secondary_CriticalResistance;
 FGameplayTag Attribute_Secondary_HealthRegeneration;
 FGameplayTag Attribute_Secondary_ManaRegeneration;
 FGameplayTag Attribute_Secondary_MaxHealth;
 FGameplayTag Attribute_Secondary_MaxMana;

protected:

private:
 static FAuraGameplayTags GameplayTags;
 
};
