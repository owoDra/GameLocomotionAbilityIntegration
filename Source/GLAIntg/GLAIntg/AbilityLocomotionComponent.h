// Copyright (C) 2024 owoDra

#pragma once

#include "LocomotionComponent.h"

#include "AbilityLocomotionComponent.generated.h"

class UAbilitySystemComponent;
class UMovementAttributeSet;
struct FOnAttributeChangeData;


/**
 * Components that extend the processing of character movement relationships with ability system
 */
UCLASS()
class GLAINTG_API UAbilityLocomotionComponent : public ULocomotionComponent
{
	GENERATED_BODY()
public:
	UAbilityLocomotionComponent(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());


	////////////////////////////////////////////////
	// Initialize and Deinitialize
#pragma region Initialize and Deinitialize
protected:
	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;

public:
	virtual void OnActorInitStateChanged(const FActorInitStateChangedParams& Params) override;

protected:
	virtual bool CanChangeInitStateToDataInitialized(UGameFrameworkComponentManager* Manager) const;
	virtual void HandleChangeInitStateToDataInitialized(UGameFrameworkComponentManager* Manager);

#pragma endregion


	////////////////////////////////////////////////
	// Ability System
#pragma region Ability System
protected:
	UPROPERTY(Transient)
	TObjectPtr<UAbilitySystemComponent> AbilitySystemComponent{ nullptr };

	UPROPERTY(Transient)
	TObjectPtr<const UMovementAttributeSet> MovementSet{ nullptr };

protected:
	void InitializeWithAbilitySystem();
	void UninitializeFromAbilitySystem();

#pragma endregion


	////////////////////////////////////////////////
	// Attribute
#pragma region Attribute
protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Attaribute", Transient)
	float GravityScaleScale{ 1.0f };

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Attaribute", Transient)
	float GroundFrictionScale{ 1.0f };

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Attaribute", Transient)
	float MoveSpeedScale{ 1.0f };

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Attaribute", Transient)
	float JumpPowerScale{ 1.0f };

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Attaribute", Transient)
	float AirControlScale{ 1.0f };

protected:
	virtual void HandleGravityScaleScaleChanged(const FOnAttributeChangeData& ChangeData);
	virtual void HandleGroundFrictionScaleChanged(const FOnAttributeChangeData& ChangeData);
	virtual void HandleMoveSpeedScaleChanged(const FOnAttributeChangeData& ChangeData);
	virtual void HandleJumpPowerScaleChanged(const FOnAttributeChangeData& ChangeData);
	virtual void HandleAirControlScaleChanged(const FOnAttributeChangeData& ChangeData);

#pragma endregion


	////////////////////////////////////////////////
	// Other
public:
	virtual float GetMaxSpeed() const override;

};
