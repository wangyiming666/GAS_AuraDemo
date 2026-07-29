// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "AuraUserWidget.generated.h"

/**
 * 
 */
UCLASS()
class AURADEMO_API UAuraUserWidget : public UUserWidget
{
	GENERATED_BODY()
public:

	UPROPERTY(BlueprintReadOnly)
	TObjectPtr<class UAuraWidgetController> WidgetController;
	
	UFUNCTION(BlueprintCallable)
	void SetWidgetController(class UAuraWidgetController* InWidgetController);

protected:
	UFUNCTION(BlueprintImplementableEvent, Category = "WidgetController")
	void WidgetControllerSet();
};
