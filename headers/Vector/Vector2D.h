#pragma once
#ifndef _Vector2D_
#define _Vector2D_
#include "Vector.h"
#include "../IReadable.h"
#include "../IWritable.h"
class Vector2D : public IVector
{
private:
	double _x;
	double _y;
public:
	Vector2D();
	Vector2D(double x, double y);
	double LongVectorAB()override;	
	const char* prefix()override;
	IReadable* Type(charline chl)override;
	char* WriteDataInFile()override;
	void Print()override;
	static const char* static_prefix();

};
#endif
