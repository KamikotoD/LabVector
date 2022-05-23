#include "../headers/charline.h"
charline::charline()
{
	_size = 0;
	_char_line = nullptr;
}

charline::charline(const charline& chl)
{
	_size = chl._size;
	_char_line = new char[_size];
	strcpy(_char_line, chl._char_line);
}

charline::charline(const char* chl)
{
	_size = strlen(chl);
	_char_line = new char[_size];
	strcpy(_char_line, chl);
}

charline::~charline()
{
	_char_line = nullptr;
}


void charline::getvalue(istream& in, char sign)
{
	
	char* buf = new char[10000];
	in.getline(buf, 10000, sign);
	_size = strlen(buf);
	_char_line = new char[_size];
	strcpy(_char_line, buf);
	delete[] buf;
}

char* charline::ClearForSign(char sign)
{
	const charline element = ".-0123456789";
	bool working;
	size_t count = 0;
	for (size_t i = 0; i < _size; i++)
	{
		working = false;
		for (size_t j = 0; j < element._size; j++)
		{
			if (_char_line[i] == element._char_line[j]) {
				working = true;
				count++;
				break;
			}
		}
		if (!working) {
			break;
		}
	}
	if (count == 0) {
		throw invalid_argument("This charlist don`t has values for conversion\n");
	}
	char* out_data = new char[_size - count - 1];
	char* temp = new char[count];
	for (size_t i = 0; i < count; i++)
	{
		temp[i] = _char_line[i];
	}
	for (size_t i = 0; i < _size - count -1; i++)
	{
		out_data[i] = _char_line[i + count + 1];
	}
	_char_line = out_data;
	return temp;
}

char& charline::operator[](size_t index)
{
	if (index < _size)
	{
		return _char_line[index];
	}
	else {
		throw invalid_argument("This array doesn`t have element with index " + index);
		return _char_line[0];
	}
}

char charline::operator[](size_t index) const
{
	if (index < _size)
	{
		return _char_line[index];
	}
	else {
		throw invalid_argument("This array doesn`t have element with index " + index);
		return _char_line[0];
	}
}

istream& operator>>(istream& in, charline& chl)
{
	char* buf = new char[10000];
	in.getline(buf, 10000,' ');
	chl._size = strlen(buf);
	chl._char_line = new char[chl._size];
	strcpy(chl._char_line, buf);
	delete[] buf;
	return in;
}

ostream& operator<<(ostream& out, const charline& chl)
{
	return out << chl._char_line;
}
bool charline::operator ==(char* arr) {
	if (arr == _char_line)
		return true;
	else 
		return false;
}
bool charline::operator ==(charline arr) {
	if (!(_size == arr._size)) {
		return false;
	}
	else {
		for (size_t i = 0; i < _size; i++)
		{
			if (arr._char_line[i] != _char_line[i]) {
				return false;
			}
		}
		return true;
	}
}
char* charline::operator=(charline chl) {
	char* temp = new char[chl._size];
	strcpy(temp, chl._char_line);
	return temp;
}
charline charline::operator=(char* chl) {
	delete[]_char_line;
	_size = strlen(chl);
	_char_line = new char[_size];
	return _char_line;
}
