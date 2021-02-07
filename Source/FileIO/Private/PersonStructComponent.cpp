// Fill out your copyright notice in the Description page of Project Settings.


#include "PersonStructComponent.h"

// Sets default values for this component's properties
UPersonStructComponent::UPersonStructComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UPersonStructComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UPersonStructComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

TArray<FPersonStruct> UPersonStructComponent::GenerateStructsFromJson(FString Path) {
	TSharedRef<TJsonReader<TCHAR>> jsonReader = TJsonReaderFactory<TCHAR>::Create(JsonFullPath(Path));
	TSharedPtr<FJsonObject> jsonObj = MakeShareable(new FJsonObject);
	TArray<FPersonStruct> people;

	if (FJsonSerializer::Deserialize(jsonReader, jsonObj) && jsonObj.IsValid()) {
		if (GEngine) {
			GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Yellow, TEXT("Deserialize"));
		}
		GenerateStructsFromJson(people, jsonObj);
	}
	else {
		if (GEngine) {
			GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Yellow, TEXT("not deserialized"));
		}
	}

	return people;
}

void UPersonStructComponent::GenerateStructsFromJson(TArray<FPersonStruct> &people, TSharedPtr<FJsonObject> jsonObj) {
	TArray<TSharedPtr<FJsonValue>> objArr = jsonObj->GetArrayField(TEXT("people"));

	for (int32 i = 0; i < 5/*objArr.Num()*/; ++i) {
		TSharedPtr<FJsonValue> value = objArr[i];
		TSharedPtr<FJsonObject> json = value->AsObject();

		FString name = json->GetStringField("name");
		int32 age = json->GetNumberField("age");

		FPersonStruct person = FPersonStruct::Build(name, age);
		people.Push(person);
	}
}

FString UPersonStructComponent::JsonFullPath(FString path) {
	FString fullpath = FPaths::ProjectContentDir() + path;
	FString json;
	FFileHelper::LoadFileToString(json, *fullpath);
	return json;
}

