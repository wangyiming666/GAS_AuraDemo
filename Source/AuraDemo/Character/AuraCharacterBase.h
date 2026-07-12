// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "AbilitySystemInterface.h"
#include "AuraDemo/AbilitySystem/AuraAttributeSet.h"
#include "AuraDemo/AbilitySystem/AuraAbilitySystemComponent.h"
#include "AuraCharacterBase.generated.h"

UCLASS(Abstract)
class AURADEMO_API AAuraCharacterBase : public ACharacter, public IAbilitySystemInterface
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AAuraCharacterBase();
	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override;
	UAuraAttributeSet* GetAuraAttributeSet() const { return AuraAttributeSet; }
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	UPROPERTY(EditAnywhere, Category = "Combat")
	TObjectPtr<class USkeletalMeshComponent> Weapon;

	UPROPERTY()
	TObjectPtr<class UAuraAbilitySystemComponent> AbilitySystemComponent;
	
	UPROPERTY()
	TObjectPtr<class UAuraAttributeSet> AuraAttributeSet;
};
