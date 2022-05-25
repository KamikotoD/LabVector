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

Vector2D::Vector2D(Vector2D& vec)
{
	_x = vec._x;
	_y = vec._y;
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

void Vector2D::operator=(Vector2D vec)
{
	_x = vec._x;
	_y = vec._y;
}

IReadable* Vector2D::Type(charline chl)
{
	double x = atof(chl.ClearForSign());
	double y = atof(chl.ClearForSign());
	return new Vector2D(x, y);
}

char* Vector2D::WriteDataInFile()
{
	string conv = "2d " + to_string((float)_x) + "," + to_string((float)_y);
	charline value = conv;
	return value.GetArrayChar();
}

void Vector2D::Print()
{
	cout << _x << " , " << _y << endl;
}

istream& operator>>(istream& i, Vector2D& vec)
{
	return i >> vec._x >> vec._y;
}

ostream& operator<<(ostream& o, Vector2D vec)
{
	return o << vec._x << "," << vec._y;
}

void Vector2D::operator*=(double value)
{
	_x *= value;
	_y *= value;
}
void Vector2D::DegreesBetweenAxis() {
	printf("Degrees to x-axis : %f\nDegrees to y-axis : %f", acos(_x / LongVectorAB()) * 180.0 / PI, acos(_y / LongVectorAB()) * 180.0 / PI);
}

bool Vector2D::operator>(IVector* vec)
{
	bool value = false;
	if (LongVectorAB() > vec->LongVectorAB())
		value = true;
	return value;
}
bool Vector2D::operator<(IVector* vec)
{
	bool value = false;
	if (LongVectorAB() < vec->LongVectorAB())
		value = true;
	return value;
}
double Vector2D::operator*(Vector2D vec)
{
	return _x * vec._x + _y * vec._y;
}
void Vector2D::VectorCollinearity(Vector2D value) {
	bool collinearity;
	if (LongVectorAB() > 0 && value.LongVectorAB() > 0) {
		if ((_x == 0 && value._x == 0) || (_y == 0 && value._y == 0))
			collinearity = true;
		else if (_x / value._x == _y / value._y)
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
double Vector2D::DegreesBetweenVectors(Vector2D value) {

	return acos(this->operator*(value) / RountTo(LongVectorAB() * value.LongVectorAB())) * 180.0 / PI;
}
double Vector2D::RountTo(double value, int roundTo)
{
	return (round(value * roundTo) / roundTo);
}
IVector* Vector2D::Value()
{
	return new Vector2D(_x,_y);
}

