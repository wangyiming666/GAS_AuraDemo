// Fill out your copyright notice in the Description page of Project Settings.


#include "AuraHUD.h"
#include "Blueprint/UserWidget.h"
#include "AuraDemo/UI/Widget/AuraUserWidget.h"


void AAuraHUD::BeginPlay()
{
	Super::BeginPlay();
	UAuraUserWidget* Widget = CreateWidget<UAuraUserWidget>(GetWorld(), OverlayWidgetClass);
	Widget->AddToViewport();
}

