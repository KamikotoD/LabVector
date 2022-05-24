#pragma once
#pragma once
#ifndef _IWritable_
#define _IWritable_
#include "charline.h"
class IWritable {
public:
	virtual char* WriteDataInFile() = 0;
};
#endif