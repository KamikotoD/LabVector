#pragma once
#define _CRT_SECURE_NO_WARNINGS

#include "List.h"
#include <iostream>
#include <string>
#include <math.h>
using namespace std;
class charline
{
private:
	char* _char_line;
	size_t _size;
public:
    charline();
    charline(const charline& chl);
    charline(const char* chl);
    ~charline();
    size_t length() const { return _size; };
    void getvalue(istream& in, char sign = '\n');
    char* ClearForSign(char sign = ',');
    char& operator [](size_t index);
    char operator [](size_t index) const;
    bool operator ==(char* arr);
    bool operator ==(charline arr);
    char* operator=(charline chl);
    charline operator=(char* chl);
    friend istream& operator >>(istream& in, charline& chl);
    friend ostream& operator <<(ostream& out, const charline& chl);
};