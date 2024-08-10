// Copyright TwinFaerie, for use on online course by Druid Mechanic only

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystem/Data/AttributeInfo.h"
#include "UI/WidgetController/AuraWidgetController.h"
#include "AttributeMenuWidgetController.generated.h"

struct FAuraAttributeInfo;
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnAnyAttributeChangedSignature, const FAuraAttributeInfo&, AttributeInfo);

/**
 * 
 */
UCLASS(Blueprintable, BlueprintType)
class AURA_API UAttributeMenuWidgetController : public UAuraWidgetController
{
	GENERATED_BODY()
	
public:
	virtual void BroadcastInitialValue() override;
	virtual void BindCallbacksToDependencies() override;
	void BroadcastAttributeInfo(const FAuraAttributeInfo& InfoData) const;

	UPROPERTY(BlueprintAssignable, Category="GAS|Attribute")
	FOnAnyAttributeChangedSignature OnAttributeChanged;

protected:
	UPROPERTY(EditDefaultsOnly)
	TArray<TObjectPtr<UAttributeInfo>> AttributeInfo;
};
