// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Runtime/JsonUtilities/Public/JsonObjectConverter.h"

#include "FPlayerStruct.h"
#include "FPlayerInventoryStruct.h"

#include "JsonComponent.generated.h"

UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class FILEIO_API UJsonComponent : public UActorComponent
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	UJsonComponent();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction *ThisTickFunction) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="AA")
	FPlayerStruct playerStruct;

	UFUNCTION(BlueprintCallable, Category="AA")
	void fLoadJson();

	UFUNCTION(BlueprintCallable, Category="AA")
	FString fPrintFPlayerStruct(FPlayerStruct p);
};
