// Fill out your copyright notice in the Description page of Project Settings.


#include "AuraPlayerState.h"

#include "AuraDemo/AbilitySystem/AuraAttributeSet.h"
#include "AuraDemo/AbilitySystem/AuraAbilitySystemComponent.h"
#include "AbilitySystemComponent.h"


AAuraPlayerState::AAuraPlayerState()
{
	NetUpdateFrequency = 100.f;
	AbilitySystemComponent = CreateDefaultSubobject<UAuraAbilitySystemComponent>(TEXT("AbilitySystemComponent"));
	AbilitySystemComponent->SetIsReplicated(true);
	AbilitySystemComponent->SetReplicationMode(EGameplayEffectReplicationMode::Mixed);
	AuraAttributeSet = CreateDefaultSubobject<UAuraAttributeSet>(TEXT("AttributeSet"));
}

UAbilitySystemComponent* AAuraPlayerState::GetAbilitySystemComponent() const
{
	return Cast<UAbilitySystemComponent>(AbilitySystemComponent);
}
