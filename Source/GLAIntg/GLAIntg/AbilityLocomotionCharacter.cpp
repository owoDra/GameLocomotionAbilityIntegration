// Copyright (C) 2024 owoDra

#include "AbilityLocomotionCharacter.h"

#include "AbilityLocomotionComponent.h"

#include UE_INLINE_GENERATED_CPP_BY_NAME(AbilityLocomotionCharacter)


AAbilityLocomotionCharacter::AAbilityLocomotionCharacter(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer.SetDefaultSubobjectClass<UAbilityLocomotionComponent>(ACharacter::CharacterMovementComponentName))
{
	
}
