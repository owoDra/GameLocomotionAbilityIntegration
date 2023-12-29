// Copyright (C) 2023 owoDra

#pragma once

#include "LocomotionCharacter.h"

#include "AbilityLocomotionCharacter.generated.h"


/**
 * Character classes with extended character movement related features with ability system
 */
UCLASS()
class GLAINTG_API AAbilityLocomotionCharacter : public ALocomotionCharacter
{
	GENERATED_BODY()
public:
	explicit AAbilityLocomotionCharacter(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

};
