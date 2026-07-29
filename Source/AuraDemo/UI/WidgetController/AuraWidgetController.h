// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "AuraWidgetController.generated.h"

/**
 * 
 */
UCLASS()
class AURADEMO_API UAuraWidgetController : public UObject
{
	GENERATED_BODY()
protected:
	UPROPERTY(BLueprintReadOnly,Category="WidgetController")
	TObjectPtr<class APlayerController> PlayerController;
	
	UPROPERTY(BLueprintReadOnly,Category="WidgetController")
	TObjectPtr<class APlayerState> PlayerState;
	
	UPROPERTY(BLueprintReadOnly,Category="WidgetController")
	TObjectPtr<class UAbilitySystemComponent> AbilitySystemComponent;

	UPROPERTY(BLueprintReadOnly,Category="WidgetController")
	TObjectPtr<class UAttributeSet> AttributeSet;
};
