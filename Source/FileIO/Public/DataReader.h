// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "DataReader.generated.h"

/**
 *
 */
UCLASS()
class FILEIO_API UDataReader : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category = "FileIO")
		static FString LoadFileToString(FString path);

	UFUNCTION(BlueprintCallable, Category = "FileIO")
		static TArray<FString> LoadFileToStringArray(FString path);
};
