// Fill out your copyright notice in the Description page of Project Settings.


#include "AuraPlayerController.h"
#include "EnhancedInputSubsystems.h"
#include "EnhancedInputComponent.h"
#include "AuraDemo/Interaction/EnemyInterface.h"
#include "GameFramework/Character.h"

AAuraPlayerController::AAuraPlayerController()
{
	bReplicates = true;
}

void AAuraPlayerController::BeginPlay()
{
	Super::BeginPlay();
	check(AuraContext)
	UEnhancedInputLocalPlayerSubsystem* InputSubsystem = GetLocalPlayer()->GetSubsystem<UEnhancedInputLocalPlayerSubsystem>();
	check(InputSubsystem)
	InputSubsystem->AddMappingContext(AuraContext,0);
	bShowMouseCursor = true;
	DefaultMouseCursor = EMouseCursor::Default;

	FInputModeGameAndUI InputMode;
	InputMode.SetHideCursorDuringCapture(false);
	InputMode.SetLockMouseToViewportBehavior(EMouseLockMode::DoNotLock);
	SetInputMode(InputMode);
}

void AAuraPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();
	UEnhancedInputComponent* EnhancedInputComponent = CastChecked<UEnhancedInputComponent>(InputComponent);
	EnhancedInputComponent->BindAction(MoveAction, ETriggerEvent::Triggered, this, &AAuraPlayerController::Move);
}

void AAuraPlayerController::PlayerTick(float DeltaTime)
{
	Super::PlayerTick(DeltaTime);
	CursorTrace();
}

void AAuraPlayerController::Move(const FInputActionValue& InputActionValue)
{
	const FVector2D MovementValue = InputActionValue.Get<FVector2D>();
	const FRotator Rotation = GetControlRotation();
	const FRotator YawRotation(0, Rotation.Yaw, 0);
	const FVector FrontDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
	const FVector RightDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);
	if (ACharacter* ControlCharacter = Cast<ACharacter>(GetPawn()))
	{
		ControlCharacter->AddMovementInput(FrontDirection, MovementValue.Y);
		ControlCharacter->AddMovementInput(RightDirection, MovementValue.X);
	}
}

void AAuraPlayerController::CursorTrace()
{
	FHitResult HitResult;
	GetHitResultUnderCursor(ECC_Visibility, false, HitResult);
	if (!HitResult.bBlockingHit) return;

	LastEnemy = CurrentEnemy;
	CurrentEnemy = HitResult.GetActor();

	IEnemyInterface* LastEnemyInterface = IsValid(LastEnemy.Get()) ? Cast<IEnemyInterface>(LastEnemy.Get()) : nullptr;
	IEnemyInterface* CurrentEnemyInterface = IsValid(CurrentEnemy.Get()) ? Cast<IEnemyInterface>(CurrentEnemy.Get()) : nullptr;

	if (LastEnemyInterface == nullptr)
	{
		if (CurrentEnemyInterface != nullptr)
		{
			CurrentEnemyInterface->HighlightActor();
		}
	}
	else
	{
		if (CurrentEnemyInterface == nullptr)
		{
			LastEnemyInterface->UnHighlightActor();
		}
		else
		{
			if (LastEnemy.Get() != CurrentEnemy.Get())
			{
				LastEnemyInterface->UnHighlightActor();
				CurrentEnemyInterface->HighlightActor();
			}
		}
	}
}
