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
	Vector2D(Vector2D& vec);
	//Vector2D(IVector* vec);
	double LongVectorAB()override;	
	const char* prefix()override;
	IReadable* Type(charline chl)override;
	char* WriteDataInFile()override;
	void Print()override;
	void operator*=(double value)override;
	void DegreesBetweenAxis()override;
	bool operator>(IVector* vec)override;
	bool operator<(IVector* vec)override;
	static const char* static_prefix();
	void operator=(Vector2D vec);
	friend istream& operator>> (istream& i, Vector2D& vec);
	friend ostream& operator<< (ostream& o, Vector2D vec);
	void VectorCollinearity(Vector2D value);
	double operator*(Vector2D vec);
	double DegreesBetweenVectors(Vector2D value);
	double RountTo(double value, int roundTo=100)override;
	IVector* Value()override;

};
#endif
