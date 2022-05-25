#pragma once
#ifndef _IVector_
#define _IVector_
#include <math.h>
#define PI 3.14159265
#include"../IReadable.h"
#include "../IWritable.h"
#include <iostream>
using namespace std;
class IVector : public IReadable, public IWritable
{
public: 
	virtual double LongVectorAB() = 0;
	virtual void Print() = 0;
	virtual void operator*=(double value) = 0;
	virtual void DegreesBetweenAxis() = 0;
	virtual bool operator>(IVector* vec) = 0;
	virtual bool operator<(IVector* vec) = 0;
	virtual IVector* Value()=0;
	virtual double RountTo(double value, int roundTo) = 0;

	//virtual void VectorCollinearity(IVector value) = 0;
	//virtual double operator*(IVector vec) = 0;
	//virtual double DegreesBetweenVectors(IVector value) = 0;
};
#endif