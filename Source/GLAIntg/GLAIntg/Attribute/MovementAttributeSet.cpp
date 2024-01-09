// Copyright (C) 2024 owoDra

#include "MovementAttributeSet.h"

#include "Net/UnrealNetwork.h"

#include UE_INLINE_GENERATED_CPP_BY_NAME(MovementAttributeSet)


UMovementAttributeSet::UMovementAttributeSet()
	: GravityScale(1.0f)
	, GroundFrictionScale(1.0f)
	, MoveSpeedScale(1.0f)
	, JumpPowerScale(1.0f)
	, AirControlScale(1.0f)
{
}

void UMovementAttributeSet::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME_CONDITION_NOTIFY(UMovementAttributeSet, GravityScale			, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UMovementAttributeSet, GroundFrictionScale	, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UMovementAttributeSet, MoveSpeedScale		, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UMovementAttributeSet, JumpPowerScale		, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UMovementAttributeSet, AirControlScale		, COND_None, REPNOTIFY_Always);
}


void UMovementAttributeSet::OnRep_GravityScale(const FGameplayAttributeData& OldValue)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UMovementAttributeSet, GravityScale, OldValue);
}

void UMovementAttributeSet::OnRep_GroundFrictionScale(const FGameplayAttributeData& OldValue)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UMovementAttributeSet, GroundFrictionScale, OldValue);
}

void UMovementAttributeSet::OnRep_MoveSpeedScale(const FGameplayAttributeData& OldValue)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UMovementAttributeSet, MoveSpeedScale, OldValue);
}

void UMovementAttributeSet::OnRep_JumpPowerScale(const FGameplayAttributeData& OldValue)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UMovementAttributeSet, JumpPowerScale, OldValue);
}

void UMovementAttributeSet::OnRep_AirControlScale(const FGameplayAttributeData& OldValue)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UMovementAttributeSet, AirControlScale, OldValue);
}
