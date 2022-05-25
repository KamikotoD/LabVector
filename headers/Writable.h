#pragma once
#ifndef _Writable_
#define _Writable_
#include <fstream>
#include <string>
#include "List.h"
#include "charline.h"
#include "Vector/Vector.h"
#include "IWritable.h"
class Writable
{
public:
    void WriteInFile(List<IWritable*> vector, const char* name_file = "DataFile.txt");
};
#endif

