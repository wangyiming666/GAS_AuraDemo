// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "AuraWidgetController.generated.h"

/**
 * 
 */
USTRUCT(BlueprintType)
struct FWidgetControllerParams
{
	GENERATED_BODY()
	FWidgetControllerParams(){}
	FWidgetControllerParams(class APlayerController* InPlayerController,class APlayerState* InPlayerState,class UAbilitySystemComponent* InAbilitySystemComponent,class UAttributeSet* InAttributeSet):
	PlayerController(InPlayerController),
	PlayerState(InPlayerState),
	AbilitySystemComponent(InAbilitySystemComponent),
	AttributeSet(InAttributeSet)
	{}
	UPROPERTY(EditAnywhere,BlueprintReadWrite)
	TObjectPtr<class APlayerController> PlayerController = nullptr;
	
	UPROPERTY(EditAnywhere,BlueprintReadWrite)
	TObjectPtr<class APlayerState> PlayerState = nullptr;
	
	UPROPERTY(EditAnywhere,BlueprintReadWrite)
	TObjectPtr<class UAbilitySystemComponent> AbilitySystemComponent = nullptr;

	UPROPERTY(EditAnywhere,BlueprintReadWrite)
	TObjectPtr<class UAttributeSet> AttributeSet = nullptr;
};

UCLASS()
class AURADEMO_API UAuraWidgetController : public UObject
{
	GENERATED_BODY()
public:

	void SetWidgetControllerParams(const FWidgetControllerParams& WCParams);
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
