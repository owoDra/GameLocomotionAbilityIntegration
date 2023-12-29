// Copyright (C) 2023 owoDra

#include "AbilityLocomotionComponent.h"

#include "Attribute/MovementAttributeSet.h"
#include "GLAIntgLogs.h"

#include "GAEAbilitySystemComponent.h"

#include "InitState/InitStateTags.h"

#include "AbilitySystemGlobals.h"
#include "GameplayEffectTypes.h"
#include "GameFramework/Pawn.h"
#include "Components/GameFrameworkComponentManager.h"

#include UE_INLINE_GENERATED_CPP_BY_NAME(AbilityLocomotionComponent)


UAbilityLocomotionComponent::UAbilityLocomotionComponent(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}


#pragma region Initialize and Deinitialize

void UAbilityLocomotionComponent::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	UninitializeFromAbilitySystem();

	Super::EndPlay(EndPlayReason);
}


void UAbilityLocomotionComponent::OnActorInitStateChanged(const FActorInitStateChangedParams& Params)
{
	Super::OnActorInitStateChanged(Params);

	// Wait for initialization of AbilitySystemCompoenet

	if (Params.FeatureName == UGAEAbilitySystemComponent::NAME_ActorFeatureName)
	{
		if (Params.FeatureState == TAG_InitState_DataInitialized)
		{
			CheckDefaultInitialization();
		}
	}
}

bool UAbilityLocomotionComponent::CanChangeInitStateToDataInitialized(UGameFrameworkComponentManager* Manager) const
{
	return Manager->HasFeatureReachedInitState(GetOwner(), UGAEAbilitySystemComponent::NAME_ActorFeatureName, TAG_InitState_DataInitialized);
}

void UAbilityLocomotionComponent::HandleChangeInitStateToDataInitialized(UGameFrameworkComponentManager* Manager)
{
	InitializeWithAbilitySystem();
}

#pragma endregion


#pragma region Ability System

void UAbilityLocomotionComponent::InitializeWithAbilitySystem()
{
	auto* Owner{ GetOwner() };
	check(Owner);

	auto* NewASC{ UAbilitySystemGlobals::GetAbilitySystemComponentFromActor(Owner) };

	if (AbilitySystemComponent)
	{
		if (AbilitySystemComponent == NewASC)
		{
			return;
		}

		UninitializeFromAbilitySystem();
	}

	AbilitySystemComponent = NewASC;
	if (!AbilitySystemComponent)
	{
		UE_LOG(LogGLAI, Error, TEXT("AbilityLocomotionComponent: Cannot initialize health component for owner [%s] with NULL ability system."), *GetNameSafe(Owner));
		return;
	}

	MovementSet = Cast<UMovementAttributeSet>(AbilitySystemComponent->InitStats(UMovementAttributeSet::StaticClass(), nullptr));
	if (!MovementSet)
	{
		UE_LOG(LogGLAI, Error, TEXT("AbilityLocomotionComponent: Cannot initialize Character movement component for owner [%s] with NULL movement set on the ability system."), *GetNameSafe(Owner));
		return;
	}

	AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(UMovementAttributeSet::GetGravityScaleAttribute()).AddUObject(this, &ThisClass::HandleGravityScaleScaleChanged);
	AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(UMovementAttributeSet::GetGroundFrictionScaleAttribute()).AddUObject(this, &ThisClass::HandleGroundFrictionScaleChanged);
	AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(UMovementAttributeSet::GetMoveSpeedScaleAttribute()).AddUObject(this, &ThisClass::HandleMoveSpeedScaleChanged);
	AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(UMovementAttributeSet::GetJumpPowerScaleAttribute()).AddUObject(this, &ThisClass::HandleJumpPowerScaleChanged);
	AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(UMovementAttributeSet::GetAirControlScaleAttribute()).AddUObject(this, &ThisClass::HandleAirControlScaleChanged);
}

void UAbilityLocomotionComponent::UninitializeFromAbilitySystem()
{
	if (AbilitySystemComponent)
	{
		AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(UMovementAttributeSet::GetGravityScaleAttribute()).RemoveAll(this);
		AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(UMovementAttributeSet::GetGroundFrictionScaleAttribute()).RemoveAll(this);
		AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(UMovementAttributeSet::GetMoveSpeedScaleAttribute()).RemoveAll(this);
		AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(UMovementAttributeSet::GetJumpPowerScaleAttribute()).RemoveAll(this);
		AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(UMovementAttributeSet::GetAirControlScaleAttribute()).RemoveAll(this);
	}

	MovementSet = nullptr;
	AbilitySystemComponent = nullptr;
}

#pragma endregion


#pragma region Attributes

void UAbilityLocomotionComponent::HandleGravityScaleScaleChanged(const FOnAttributeChangeData& ChangeData)
{
	GravityScaleScale = ChangeData.NewValue;
}

void UAbilityLocomotionComponent::HandleGroundFrictionScaleChanged(const FOnAttributeChangeData& ChangeData)
{
	GroundFrictionScale = ChangeData.NewValue;
}

void UAbilityLocomotionComponent::HandleMoveSpeedScaleChanged(const FOnAttributeChangeData& ChangeData)
{
	MoveSpeedScale = ChangeData.NewValue;
}

void UAbilityLocomotionComponent::HandleJumpPowerScaleChanged(const FOnAttributeChangeData& ChangeData)
{
	JumpPowerScale = ChangeData.NewValue;
}

void UAbilityLocomotionComponent::HandleAirControlScaleChanged(const FOnAttributeChangeData& ChangeData)
{
	AirControlScale = ChangeData.NewValue;
}

#pragma endregion


float UAbilityLocomotionComponent::GetMaxSpeed() const
{
	return Super::GetMaxSpeed() * MoveSpeedScale;
}
