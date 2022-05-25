#include <iostream>
#include <fstream>
#include <string>
#include <stdio.h>
#include "headers/List.h"
#include "headers/charline.h"
#include "headers/IReadable.h"
#include "headers/IWritable.h"
#include "headers/Vector/Vector.h"
#include "headers/Vector/Vector2D.h"
#include "headers/Vector/Vector3D.h"
#include "headers/Readable.h"
#include "headers/Writable.h"
using namespace std;
void SortVectors(List<IVector*> vec, char sign);
int ChoiceOfVector();
void OperationOnVectors(List<IVector*> vector);
enum Menu {
    PrintArrayVectors = 1,
    AddVector,
    RemoveElemensArray,
    OperationsOnVectors,
    SortVector,
    SaveAndExit
};
enum ChoiseVector {
    Vector2d = 1,
    Vector3d
};
enum OpretionsOfVectors {
    VectorCollinearity = 1,
    LongVector,
    ScalarMultiplication,
    DegreesBetweenAxix,
    DegreesBetweenVectors,
    ComeBack
};
int main()
{
	//Инициализация переменых
    List<IReadable*> vectors_read;
    List<IWritable*> vectors_write;
    Readable DataFromFile;
    Writable DataInFile;
	bool working = true;
	int switch_on, count, numbers;
	char sign;
	Vector2D val2d;
	Vector3D val3d;
	IReadable* temp_val;
	List<Vector2D> vec2d;
	List<Vector3D> vec3d;
    List<IVector*> vector;
	//Типы векторов использующихся в проэкте
    vectors_read.Add(new Vector2D());
    vectors_read.Add(new Vector3D());
	//Считывание данных
    DataFromFile.ReadableDataFromFile(vectors_read);
    for (size_t i = 0; i < vectors_read.Count(); i++)
    {
        vector.Add((IVector*)vectors_read[i]);
    }
	//Интерфейс програмы
	while (working)
	{
		printf("\n1. Print array vectors\n2. Add vector\n3. Delete vectors\n4. Operations on vectors\n5. Sort Vector\n6. Save and Exit\nChoose one option : ");
		scanf_s("%d",&switch_on);
		switch ((Menu)switch_on)
		{

		case PrintArrayVectors:
			for (size_t i = 0; i < vector.Count(); i++)
			{
				cout << i + 1 << ") ";
				vector[i]->Print();
			}
			break;
		case AddVector:
			switch_on = ChoiceOfVector();
			printf("Enter value:");
			if (switch_on == 1){
				cin >> val2d;
				vector.Add(&val2d);
			}
			else{
				cin >> val3d;
				vector.Add(&val3d);
			}
			break;
		case RemoveElemensArray:
			printf("Enter the number of items to remove: ");
			scanf_s("%d", &count);
			printf("Enter from which element you want to remove :  ");
			scanf_s("%d", &numbers);
			vector.Remove(numbers, count);
		case OperationsOnVectors:
			OperationOnVectors(vector);
			break;
		case SortVector:
			printf("Enter the sign (max -> min{>} or min -> max{<} ): ");
			scanf_s(" %c", &sign);
			SortVectors(vector, sign);
			break;
		case SaveAndExit:
			for (size_t i = 0; i < vector.Count(); i++)
			{
				vectors_write.Add(vector[i]);
			}
			DataInFile.WritableDataInFile(vectors_write);
			working = false;
			break;
		default:
			printf("This option don`t exist\n");
			break;
		}
	}
}
int ChoiceOfVector() {
	int switch_on;
	bool working = true;
	while (working)
	{
		printf("\n1. Print Vector(x,y)\n2. Print Vector(x,y,z)\nChoose one option : ");
		scanf_s("%d", &switch_on);
		switch ((ChoiseVector)switch_on)
		{
		case Vector2d:
			working = false;
			break;
		case Vector3d:
			working = false;
			break;
		default:
			printf("This option don`t exist\n");
			break;
		}
	}
	return switch_on;
}
void OperationOnVectors(List<IVector*> vector) {
	List<Vector2D> vec2d;
	List<Vector2D> vec3d;
	Vector2D T2d;
	for (size_t i = 0; i < vector.Count(); i++)
	{
		if (vector[i]->prefix() == Vector2D::static_prefix()) {
			vec2d.Add((Vector2D)*vector[i]);
		}
		else {
			vec3d.Add(vector[i]);
		}
	}
	bool operationWorking = true;
	int switch_on, count, numbers;
	while (operationWorking)
	{
		printf("\n1. VectorCollinearity\n2. LongVector\n3. ScalarMultiplication\n4. DegreesBetweenAxix\n5. DegreesBetweenVectors\n6. Come back\nChoose one option : ");
		scanf_s("%d", &switch_on);
		switch ((OpretionsOfVectors)switch_on)
		{
		case VectorCollinearity:
			switch_on = ChoiceOfVector();
			printf("Enter the numbers of two vectors : ");
			scanf_s("%d", "%d", &count, &numbers);
			if (switch_on == 1)
				vec2d[count].VectorCollinearity(vec2d[numbers]);
			else
				vec3d[count].VectorCollinearity(vec3d[numbers]);
			break;
		case LongVector:
			switch_on = ChoiceOfVector();
			printf("Enter the number of vector : ");
			scanf_s("%d", &count);
			if (switch_on == 1)
				printf("Long vector[%d] = %lf", count, vec2d[count].LongVectorAB());
			else
				printf("Long vector[%d] = %lf", count, vec3d[count].LongVectorAB());
			break;
		case ScalarMultiplication:
			switch_on = ChoiceOfVector();
			printf("Enter the numbers of two vectors : ");
			scanf_s("%d", "%d", &count, &numbers);
			if (switch_on == 1)
				printf("Scalar multiplication : %lf", vec2d[count] * vec2d[numbers]);
			else
				printf("Scalar multiplication : %lf", vec3d[count] * vec3d[numbers]);
			break;
		case DegreesBetweenAxix:
			switch_on = ChoiceOfVector();
			printf("Enter the number of vector : ");
			scanf_s("%d", &count);
			if (switch_on == 1)
				vec2d[count].DegreesBetweenAxis();
			else
				vec3d[count].DegreesBetweenAxis();
			break;
		case DegreesBetweenVectors:
			switch_on = ChoiceOfVector();
			printf("Enter the numbers of two vectors : ");
			scanf_s("%d", "%d", &count, &numbers);
			if (switch_on == 1)
				printf("Degrees between vectors: %lf", vec2d[count].DegreesBetweenVectors(vec2d[numbers]));
			else
				printf("Degrees between vectors: %lf", vec3d[count].DegreesBetweenVectors(vec3d[numbers]));
			break;
		case ComeBack:
			operationWorking = false;
			break;
		default:
			printf("This option don`t exist\n");
			break;
		}
	}
}
void SortVectors(List<IVector*> vec, char sign) {
	IVector* temp;
	int num;
	for (size_t i = 0; i < vec.Count(); i++)
	{
		num = i;
		temp = vec[i];
		for (size_t j = i + 1; j < vec.Count(); j++)
		{
			if (vec[num]->LongVectorAB() < vec[j]->LongVectorAB() && sign == '>')
				num = j;
			else if (vec[num]->LongVectorAB() > vec[j]->LongVectorAB() && sign == '<')
				num = j;
		}
		vec[i] = vec[num];
		vec[num] = temp;
	}
}

