// Fill out your copyright notice in the Description page of Project Settings.


#include "JsonComponent.h"

// Sets default values
UJsonComponent::UJsonComponent()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryComponentTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void UJsonComponent::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void UJsonComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction *ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

}

FString UJsonComponent::fPrintFPlayerStruct(FPlayerStruct p) {
	FString resp = "";

	resp += "name: " + p.name + "\r\n";
	resp += "HP: " + FString::FromInt(p.HP) + "\r\n";
	resp += "MP: " + FString::FromInt(p.MP) + "\r\n";
	resp += "AP: " + FString::SanitizeFloat(p.AP) + "\r\n";

	resp += "inventory: \r\n";

	for (int32 i = 0; i < p.aInventory.Num(); ++i) {
		resp += "id: " + FString::FromInt(p.aInventory[i].id) + "\r\n";
		resp += "name: " + p.aInventory[i].name + "\r\n";
		resp += "count: " + FString::FromInt(p.aInventory[i].count) + "\r\n";
	}

	return resp;
}

void UJsonComponent::fLoadJson() {
	bool bOk = true;

	FString filename = "player.json";
	FString fullPathContent = FPaths::ProjectContentDir() + filename;
	FString jsonStr;

	if (!FPlatformFileManager::Get().GetPlatformFile().FileExists(*fullPathContent)) {
		bOk = false;
	}

	if (bOk) {
		FFileHelper::LoadFileToString(jsonStr, *fullPathContent);
		
		TSharedRef<TJsonReader<TCHAR>> jsonReader = TJsonReaderFactory<TCHAR>::Create(jsonStr);
		TSharedPtr<FJsonObject> jsonObj = MakeShareable(new FJsonObject);

		FJsonSerializer::Deserialize(jsonReader, jsonObj);

		TSharedPtr<FJsonObject> player = jsonObj->GetObjectField("player");

		this->playerStruct.name = player->GetStringField("name");
		this->playerStruct.HP = player->GetIntegerField("HP");
		this->playerStruct.MP = player->GetIntegerField("MP");
		this->playerStruct.AP = player->GetIntegerField("AP");

		TArray<TSharedPtr<FJsonValue>> aInventory;
		aInventory = player->GetArrayField("inventory");

		FPlayerInventoryStruct item;
		for (int32 i = 0; i < aInventory.Num(); ++i) {
			item.id = aInventory[i]->AsObject()->GetIntegerField("id");
			item.count = aInventory[i]->AsObject()->GetIntegerField("count");
			item.name = aInventory[i]->AsObject()->GetStringField("name");
			this->playerStruct.aInventory.Add(item);
		}
	}
}