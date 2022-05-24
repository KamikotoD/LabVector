#include "../../headers/Vector/Vector2D.h"

Vector2D::Vector2D()
{
	_x = 0;
	_y = 0;
}

Vector2D::Vector2D(double x, double y)
{
	_x = x;
	_y = y;
}

double Vector2D::LongVectorAB()
{
	return sqrt(pow(_x, 2) + pow(_y, 2));
}

const char* Vector2D::prefix()
{
	return static_prefix();
}

const char* Vector2D::static_prefix()
{
	return "2d";
}

IVector* Vector2D::Type(charline chl)
{
	double x = atof(chl.ClearForSign());
	double y = atof(chl.ClearForSign());
	return new Vector2D(x,y);
}

char* Vector2D::WriteDataInFile()
{
	string conv = "2d " + to_string((float)_x) + "," + to_string((float)_y) + "\n";
	char* str = const_cast<char*>(conv.c_str());
	return str;
}

void Vector2D::Print()
{
	cout << _x << " , " << _y << endl;
}

