#include "../../headers/Vector/Vector3D.h"

Vector3D::Vector3D()
{
	_x = 0;
	_y = 0;
	_z = 0;
}

Vector3D::Vector3D(double x, double y, double z)
{
	_x = x;
	_y = y;
	_z = z;
}

double Vector3D::LongVectorAB()
{
	return sqrt(pow(_x, 2) + pow(_y, 2) + pow(_z,2));
}
const char* Vector3D::prefix()
{
	return static_prefix();
}

const char* Vector3D::static_prefix()
{
	return "3d";
}
IVector* Vector3D::Type(charline chl)
{
	double x = atof(chl.ClearForSign());
	double y = atof(chl.ClearForSign());
	double z = atof(chl.ClearForSign());
	return Vec(Vector3D(x,y,z));
}
void Vector3D::Print()
{
	cout << _x << " , " << _y << " , " << _z<< endl;
}
IVector* Vector3D::Vec(Vector3D vec)
{
	return &vec;
}