#pragma once
#include "Vector.h"
#include "../IReadable.h"
class Vector3D : public IVector, public IReadable
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
	IVector* Type(charline chl)override;
	char* WriteDataInFile()override;
	void Print()override;
	static const char* static_prefix();
};

