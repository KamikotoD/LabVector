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
	Vector3D(Vector3D& vec);
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
	void operator=(Vector3D vec);
	friend istream& operator>> (istream& i, Vector3D& vec);
	friend ostream& operator<< (ostream& o, Vector3D vec);
	double RountTo(double value, int roundTo=100)override;
	double DegreesBetweenVectors(Vector3D value);
	void VectorCollinearity(Vector3D value);
	double operator*(Vector3D vec);
	IVector* Value()override;

};
#endif
