// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PersonStruct.generated.h"

USTRUCT(BlueprintType)
struct FPersonStruct
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Struct")
	FString Name;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Struct")
	int32 Age;

	FPersonStruct()
	{
		Name = "";
		Age = 0;
	}

	static FPersonStruct Build(FString Name, int32 Age);
};