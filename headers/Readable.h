#pragma once
#ifndef _Readable_
#define _Readable_
#include <fstream>
#include <string>
#include "List.h"
#include "Vector/Vector.h"
#include "IReadable.h"
class Readable
{
public:
	void ReadFromFile(List<IReadable*> &vectors_read, const char* name_file = "DataFile.txt");
};
#endif

