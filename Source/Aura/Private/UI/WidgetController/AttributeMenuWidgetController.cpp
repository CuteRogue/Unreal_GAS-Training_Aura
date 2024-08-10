// Copyright TwinFaerie, for use on online course by Druid Mechanic only


#include "UI/WidgetController/AttributeMenuWidgetController.h"

#include "AbilitySystem/AuraAttributeSet.h"

void UAttributeMenuWidgetController::BroadcastInitialValue()
{
	Super::BroadcastInitialValue();

	for (const auto& InfoList : AttributeInfo)
	{
		for (const auto& InfoData : InfoList->AttributeInfo)
		{
			BroadcastAttributeInfo(InfoData);
		}
	}
}

void UAttributeMenuWidgetController::BindCallbacksToDependencies()
{
	Super::BindCallbacksToDependencies();

	for (const auto& InfoList : AttributeInfo)
	{
		for (const auto& InfoData : InfoList->AttributeInfo)
		{
			AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(InfoData.Attribute)
				.AddLambda([this, InfoData] (const FOnAttributeChangeData&){ BroadcastAttributeInfo(InfoData); });
		}
	}
}

void UAttributeMenuWidgetController::BroadcastAttributeInfo(const FAuraAttributeInfo& InfoData) const
{
	FAuraAttributeInfo Info = InfoData;
	Info.Value = Info.Attribute.GetNumericValue(AttributeSet);

	OnAttributeChanged.Broadcast(Info);
}
