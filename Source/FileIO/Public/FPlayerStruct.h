#pragma once

#include "CoreMinimal.h"

#include "FPlayerInventoryStruct.h"

#include "FPlayerStruct.generated.h"

USTRUCT(BlueprintType)
struct FPlayerStruct
{
  GENERATED_BODY()

  public: 

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="AA")
    FString name = "";

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="AA")
    int32 HP = 50;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="AA")
    int32 MP = 10;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="AA")
    float AP = 5.5;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="AA")
    TArray<FPlayerInventoryStruct> aInventory;
};
