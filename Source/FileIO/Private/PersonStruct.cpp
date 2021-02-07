#include "PersonStruct.h"

FPersonStruct FPersonStruct::Build(FString Name, int32 Age) {
	FPersonStruct person;
	person.Name = Name;
	person.Age = Age;
	return person;
}