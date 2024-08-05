// Copyright TwinFaerie, for use on online course by Druid Mechanic only

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "AuraEffectActor.generated.h"

struct FActiveGameplayEffectHandle;
class UGameplayEffect;
class USphereComponent;

USTRUCT(BlueprintType, Blueprintable)
struct FGameplayEffectData
{
	GENERATED_BODY()

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	TSubclassOf<UGameplayEffect> GameplayEffectClass;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	float Level = 1.0f;
};

UCLASS()
class AURA_API AAuraEffectActor : public AActor
{
	GENERATED_BODY()
	
public:	
	AAuraEffectActor();
	
protected:
	virtual void BeginPlay() override;

	UFUNCTION(BlueprintCallable, Category="Aura Effects")
	void ApplyAllEffectToTarget(AActor* TargetActor);
	UFUNCTION(BlueprintCallable, Category="Aura Effects")
	void ApplySpecificEffectToTarget(AActor* TargetActor, FGameplayEffectData GameplayEffectData);
	UFUNCTION(BlueprintCallable, Category="Aura Effects")
	void RemoveAllAppliedInfiniteEffectFromTarget(AActor* TargetActor);
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Effects")
	TArray<FGameplayEffectData> GameplayEffects;

	UPROPERTY(BlueprintReadOnly)
	TArray<FActiveGameplayEffectHandle> AppliedGameplayEffects;
	
private:
};
