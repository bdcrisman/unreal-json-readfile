// Fill out your copyright notice in the Description page of Project Settings.

#include "DataReader.h"

FString UDataReader::LoadFileToString(FString path)
{
	FString dir = FPaths::ProjectContentDir();
	FString result;
	IPlatformFile &file = FPlatformFileManager::Get().GetPlatformFile();

	if (file.CreateDirectory(*dir))
	{
		FString f = dir + "/" + path;
		FFileHelper::LoadFileToString(result, *f);
		UE_LOG(LogTemp, Warning, TEXT("%s"), *result);
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("%s es no bueno"), *dir);
	}

	return result;
}

TArray<FString> UDataReader::LoadFileToStringArray(FString path)
{
	FString dir = FPaths::ProjectContentDir();
	TArray<FString> result;
	IPlatformFile &file = FPlatformFileManager::Get().GetPlatformFile();

	if (file.CreateDirectory(*dir))
	{
		FString f = dir + "/" + path;
		FFileHelper::LoadFileToStringArray(result, *f);
	}

	return result;
}