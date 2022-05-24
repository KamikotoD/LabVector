#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include "List.h"
#include "Vector/Vector.h"
#include "Vector/Vector2D.h"
#include "Vector/Vector3D.h"
#include "IReadable.h"
#include "charline.h"
using namespace std;
List<IVector*> Readable(List<IReadable*> vectors_read, const char* name_file = "DataFile.txt");
void Writable(List<IReadable*> vectors_read, List<IVector*> vector, const char* name_file = "DataFile.txt");
