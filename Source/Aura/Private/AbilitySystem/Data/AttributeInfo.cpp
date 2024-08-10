// Copyright TwinFaerie, for use on online course by Druid Mechanic only


#include "AbilitySystem/Data/AttributeInfo.h"

FAuraAttributeInfo UAttributeInfo::FindAttributeInfoByTag(const FGameplayTag& AttributeTag, bool bLogNotFound) const
{
	for (const auto Element : AttributeInfo)
	{
		if (Element.Tag.MatchesTagExact(AttributeTag))
		{
			return Element;
		}
	}

	if (bLogNotFound)
	{
		UE_LOG(LogTemp, Error, TEXT("Can't find Info for AttributeTag [%s] on Attribute[%s}."), *AttributeTag.ToString(), *GetNameSafe(this))
	}

	return FAuraAttributeInfo();
}
