// Fill out your copyright notice in the Description page of Project Settings.


#include "AuraHUD.h"
#include "Blueprint/UserWidget.h"
#include "AuraDemo/UI/Widget/AuraUserWidget.h"
#include "AuraDemo/UI/WidgetController/OverlayWidgetController.h"
#include "AuraDemo/UI/WidgetController/AuraWidgetController.h"

UOverlayWidgetController* AAuraHUD::GetOverlayWidgetController(const FWidgetControllerParams& WCParams)
{
	if (OverlayWidgetController == nullptr)
	{
		OverlayWidgetController = NewObject<UOverlayWidgetController>(this, OverlayWidgetControllerClass);
		OverlayWidgetController->SetWidgetControllerParams(WCParams);
	}

	return OverlayWidgetController;
}

void AAuraHUD::BeginPlay()
{
	Super::BeginPlay();
	UAuraUserWidget* Widget = CreateWidget<UAuraUserWidget>(GetWorld(), OverlayWidgetClass);
	Widget->AddToViewport();
}


