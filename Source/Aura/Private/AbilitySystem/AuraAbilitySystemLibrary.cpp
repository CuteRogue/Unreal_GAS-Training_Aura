// Copyright TwinFaerie, for use on online course by Druid Mechanic only


#include "AbilitySystem/AuraAbilitySystemLibrary.h"

#include "Hud/AuraHud.h"
#include "Kismet/GameplayStatics.h"
#include "Player/AuraPlayerState.h"
#include "UI/WidgetController/AuraWidgetController.h"

UOverlayWidgetController* UAuraAbilitySystemLibrary::GetOverlayWidgetController(const UObject* WorldContext)
{
	if (APlayerController* PlayerController = UGameplayStatics::GetPlayerController(WorldContext, 0))
	{
		if (AAuraHud* AuraHud = PlayerController->GetHUD<AAuraHud>())
		{
			AAuraPlayerState* PlayerState = PlayerController->GetPlayerState<AAuraPlayerState>();
			UAbilitySystemComponent* AbilitySystemComponent = PlayerState->GetAbilitySystemComponent();
			UAttributeSet* AttributeSet = PlayerState->GetAttributeSet();

			const FWidgetControllerParams WidgetControllerParams(PlayerController, PlayerState, AbilitySystemComponent, AttributeSet);
			
			return AuraHud->GetOverlayWidgetController(WidgetControllerParams);
		}
	}

	return nullptr;
}

UAttributeMenuWidgetController* UAuraAbilitySystemLibrary::GetAttributeMenuWidgetController(const UObject* WorldContext)
{
	if (APlayerController* PlayerController = UGameplayStatics::GetPlayerController(WorldContext, 0))
	{
		if (AAuraHud* AuraHud = PlayerController->GetHUD<AAuraHud>())
		{
			AAuraPlayerState* PlayerState = PlayerController->GetPlayerState<AAuraPlayerState>();
			UAbilitySystemComponent* AbilitySystemComponent = PlayerState->GetAbilitySystemComponent();
			UAttributeSet* AttributeSet = PlayerState->GetAttributeSet();

			const FWidgetControllerParams WidgetControllerParams(PlayerController, PlayerState, AbilitySystemComponent, AttributeSet);
			
			return AuraHud->GetAttributeMenuWidgetController(WidgetControllerParams);
		}
	}

	return nullptr;
}
