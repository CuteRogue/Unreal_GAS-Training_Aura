// Copyright TwinFaerie, for use on online course by Druid Mechanic only


#include "UI/WidgetController/AuraWidgetController.h"

void UAuraWidgetController::SetWidgetControllerParams(const FWidgetControllerParams WidgetControllerParams)
{
	PlayerController = WidgetControllerParams.PlayerController;
	PlayerState = WidgetControllerParams.PlayerState;
	AbilitySystemComponent = WidgetControllerParams.AbilitySystemComponent;
	AttributeSet = WidgetControllerParams.AttributeSet;
}

void UAuraWidgetController::BroadcastInitialValue()
{
}

void UAuraWidgetController::BindCallbacksToDependencies()
{
}
