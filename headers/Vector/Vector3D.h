#pragma once
#ifndef _Vector3D_
#define _Vector3D_
#include "Vector.h"
#include "../IReadable.h"
#include "../IWritable.h"
class Vector3D : public IVector
{
private:
	double _x;
	double _y;
	double _z;
public:
	Vector3D();
	Vector3D(double x, double y, double z);
	double LongVectorAB()override;
	const char* prefix()override;
	IReadable* Type(charline chl)override;
	char* WriteDataInFile()override;
	void Print()override;
	static const char* static_prefix();
};
#endif
