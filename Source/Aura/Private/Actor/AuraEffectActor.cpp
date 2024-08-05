// Copyright TwinFaerie, for use on online course by Druid Mechanic only


#include "Actor/AuraEffectActor.h"

#include "AbilitySystemBlueprintLibrary.h"
#include "AbilitySystemComponent.h"

// Sets default values
AAuraEffectActor::AAuraEffectActor()
{
	PrimaryActorTick.bCanEverTick = false;

	SetRootComponent(CreateDefaultSubobject<USceneComponent>("SceneRoot"));
}

void AAuraEffectActor::BeginPlay()
{
	Super::BeginPlay();
}

void AAuraEffectActor::ApplyAllEffectToTarget(AActor* TargetActor)
{
	for (const auto Element : GameplayEffects)
	{
		ApplySpecificEffectToTarget(TargetActor, Element);
	}
}

void AAuraEffectActor::ApplySpecificEffectToTarget(AActor* TargetActor, const FGameplayEffectData GameplayEffectData)
{
	UAbilitySystemComponent* TargetASC = UAbilitySystemBlueprintLibrary::GetAbilitySystemComponent(TargetActor);
	if (TargetASC == nullptr) return;

	check(GameplayEffectData.GameplayEffectClass)
	FGameplayEffectContextHandle EffectContextHandle = TargetASC->MakeEffectContext();
	EffectContextHandle.AddSourceObject(this);

	const FGameplayEffectSpecHandle EffectSpecHandle = TargetASC->MakeOutgoingSpec(GameplayEffectData.GameplayEffectClass, GameplayEffectData.Level, EffectContextHandle);
	const FActiveGameplayEffectHandle ActiveGameplayEffectHandle = TargetASC->ApplyGameplayEffectSpecToSelf(*EffectSpecHandle.Data.Get());

	if (EffectSpecHandle.Data.Get()->Def.Get()->DurationPolicy == EGameplayEffectDurationType::Infinite)
	{
		AppliedGameplayEffects.Add(ActiveGameplayEffectHandle);
	}
}

void AAuraEffectActor::RemoveAllAppliedInfiniteEffectFromTarget(AActor* TargetActor)
{
	UAbilitySystemComponent* TargetASC = UAbilitySystemBlueprintLibrary::GetAbilitySystemComponent(TargetActor);
	if (TargetASC == nullptr) return;

	TArray<FActiveGameplayEffectHandle> ToRemove;
	for (auto Element : AppliedGameplayEffects)
	{
		if (TargetASC == Element.GetOwningAbilitySystemComponent())
		{
			TargetASC->RemoveActiveGameplayEffect(Element);
			ToRemove.Add(Element);
		}
	}

	for (auto Element : ToRemove)
	{
		AppliedGameplayEffects.Remove(Element);	
	}
}
