#pragma once
#include "Vector.h"
#include "../IReadable.h"
class Vector2D : public IVector, public IReadable
{
private:
	double _x;
	double _y;
public:
	Vector2D();
	Vector2D(double x, double y);
	double LongVectorAB()override;	
	const char* prefix()override;
	IVector* Type(charline chl)override;
	char* WriteDataInFile()override;
	void Print()override;
	static const char* static_prefix();



};

