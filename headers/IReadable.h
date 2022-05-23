#pragma once
#include "charline.h"
class IReadable {
public:
	virtual const char* prefix() = 0;
	virtual IVector* Type(charline chl) = 0;
};