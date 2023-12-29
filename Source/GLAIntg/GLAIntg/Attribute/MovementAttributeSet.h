// Copyright (C) 2023 owoDra

#pragma once

#include "GAEAttributeSet.h"

#include "AbilitySystemComponent.h"

#include "MovementAttributeSet.generated.h"

struct FGameplayEffectModCallbackData;


/**
 * Define attributes of the character's movement system
 */
UCLASS(BlueprintType)
class UMovementAttributeSet : public UGAEAttributeSet
{
	GENERATED_BODY()
public:
	UMovementAttributeSet();

	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

public:
	ATTRIBUTE_ACCESSORS(UMovementAttributeSet, GravityScale);
	ATTRIBUTE_ACCESSORS(UMovementAttributeSet, GroundFrictionScale);
	ATTRIBUTE_ACCESSORS(UMovementAttributeSet, MoveSpeedScale);
	ATTRIBUTE_ACCESSORS(UMovementAttributeSet, JumpPowerScale);
	ATTRIBUTE_ACCESSORS(UMovementAttributeSet, AirControlScale);

protected:
	UFUNCTION() void OnRep_GravityScale(const FGameplayAttributeData& OldValue);
	UFUNCTION() void OnRep_GroundFrictionScale(const FGameplayAttributeData& OldValue);
	UFUNCTION() void OnRep_MoveSpeedScale(const FGameplayAttributeData& OldValue);
	UFUNCTION() void OnRep_JumpPowerScale(const FGameplayAttributeData& OldValue);
	UFUNCTION() void OnRep_AirControlScale(const FGameplayAttributeData& OldValue);

private:
	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_GravityScale, Category = "Movement", Meta = (AllowPrivateAccess = true))
	FGameplayAttributeData GravityScale;

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_GroundFrictionScale, Category = "Movement", Meta = (AllowPrivateAccess = true))
	FGameplayAttributeData GroundFrictionScale;

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_MoveSpeedScale, Category = "Movement", Meta = (AllowPrivateAccess = true))
	FGameplayAttributeData MoveSpeedScale;

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_JumpPowerScale, Category = "Movement", Meta = (AllowPrivateAccess = true))
	FGameplayAttributeData JumpPowerScale;

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_AirControlScale, Category = "Movement", Meta = (AllowPrivateAccess = true))
	FGameplayAttributeData AirControlScale;

};
