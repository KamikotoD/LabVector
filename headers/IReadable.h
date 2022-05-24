#pragma once
#ifndef _IReadable_
#define _IReadable_
#include "charline.h"
class IReadable {
public:
	virtual const char* prefix() = 0;
	virtual IReadable* Type(charline chl) = 0;
};
#endif