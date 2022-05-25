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
Vector3D::Vector3D(Vector3D& vec)
{
	_x = vec._x;
	_y = vec._y;
	_z = vec._z;
}

Vector3D::Vector3D(IVector* vec)
{
	vec->Value();
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
void Vector3D::operator=(Vector3D vec)
{
	_x = vec._x;
	_y = vec._y;
	_z = vec._z;
}
IReadable* Vector3D::Type(charline chl)
{
	double x = atof(chl.ClearForSign());
	double y = atof(chl.ClearForSign());
	double z = atof(chl.ClearForSign());
	return new Vector3D(x, y, z);
}
char* Vector3D::WriteDataInFile()
{
	string conv = "3d " + to_string((float)_x) + "," + to_string((float)_y) + "," + to_string((float)_z);
	charline value = conv;
	return value.GetArrayChar();
}
void Vector3D::Print()
{
	cout << _x << " , " << _y << " , " << _z<< endl;
}
istream& operator>>(istream& i, Vector3D& vec)
{
	return i >> vec._x >> vec._y >> vec._z;
}

ostream& operator<<(ostream& o, Vector3D vec)
{
	return o << vec._x << ',' << vec._y << ',' << vec._z;
}
void Vector3D::operator*=(double value)
{
	_x *= value;
	_y *= value;
	_z *= value;
}
void Vector3D::DegreesBetweenAxis() {
	printf("Degrees to x-axis : %f\nDegrees to y-axis : %f\nDegrees to z-axis : %f\n", acos(_x / LongVectorAB()) * 180.0 / PI, acos(_y / LongVectorAB()) * 180.0 / PI, acos(_z / LongVectorAB()) * 180.0 / PI);
}
bool Vector3D::operator>(IVector* vec)
{
	bool value = false;
	if (LongVectorAB() > vec->LongVectorAB())
		value = true;
	return value;
}
bool Vector3D::operator<(IVector* vec)
{
	bool value = false;
	if (LongVectorAB() < vec->LongVectorAB())
		value = true;
	return value;
}
double Vector3D::RountTo(double value, int roundTo)
{
	return (round(value * roundTo) / roundTo);
}
double Vector3D::operator*(Vector3D vec)
{
	return  _x * vec._x + _y * vec._y + _z * vec._z;
}
IVector* Vector3D::Value()
{
	return new Vector3D(_x,_y,_z);
}
double Vector3D::DegreesBetweenVectors(Vector3D value) {

	return acos(operator*(value) / RountTo(LongVectorAB() * value.LongVectorAB())) * 180.0 / PI;
}
void Vector3D::VectorCollinearity(Vector3D value) {
	bool collinearity;
	if (LongVectorAB() > 0 && value.LongVectorAB() > 0) {
		if (_x == 0 && value._x == 0)
			if (_y == 0 && value._y == 0)
				collinearity = true;
			else if (_z == 0 && value._z == 0)
				collinearity = true;
			else if ((_y == 0 && value._y == 0) && (_z == 0 && value._z == 0))
				collinearity = true;
		if ((_x == 0 && value._x == 0) || (_y == 0 && value._y == 0) || (_z == 0 && value._z == 0))
			collinearity = true;
		else if (_x / value._x == _y / value._y == _z / value._z)
			collinearity = true;
		else
			collinearity = false;
		if (collinearity)
			printf("Vector is collinear\n");
		else
			printf("Vector isn`t collinear\n");
	}
	else {
		printf("One of the vectors is zero,\nso the question of the collinearity of the vectors is incorrect\n");
	}
}