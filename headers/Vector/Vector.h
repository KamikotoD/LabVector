#pragma once
#include <math.h>
#define PI 3.14159265
#include <iostream>
using namespace std;
class IVector
{
public: 
	virtual char* WriteDataInFile() = 0;
	virtual double LongVectorAB() = 0;
	virtual void Print() = 0;
	//virtual void operator*=(double value) = 0;
	//virtual void operator=(IVector vec) = 0;
	//virtual void VectorCollinearity(IVector value) = 0;
	//virtual void DegreesBetweenAxis() = 0;
	/*virtual friend istream& operator>> (istream& i, IVector& vec);
	virtual friend ostream& operator<< (ostream& o, IVector vec);*/
	//virtual double operator*(IVector vec) = 0;
	//virtual double DegreesBetweenVectors(IVector value) = 0;
	/*virtual bool operator>(IVector vec);
	virtual bool operator<(IVector vec);*/
};