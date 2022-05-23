#pragma once
#include <iostream>
using namespace std;
template <typename T>
class List
{
private:
	int _size_array;
	int _additional_memory = 10;
	int _size_memory = _additional_memory;
	T* _array;
public:
	List() {
		_size_array = 0;
		_array = new T[_size_memory];
	}
	List(int size) {
		_size_array = size;
		_size_memory += size;
		_array = new T[_size_memory];
	}
	List(int size, T value) {
		_size_array = size;
		_size_memory += size;
		_array = new T[_size_memory];
		for (int i = 0; i < _size_array; i++)
		{
			_array[i] = value;
		}
	}
	T& operator[] (const int index)
	{
		if (index >= 0 && index < _size_array) {
			return _array[index];
		}
		else {
			throw invalid_argument("This array doesn`t have element with index " + index);
			return _array[0];
		}
	}
	const T& operator[] (const int index) const
	{
		if (index >= 0 && index < _size_array) {
			return _array[index];
		}
		else {
			throw invalid_argument("This array doesn`t have element with index " + index);
			return _array[0];
		}
	}
	int Count() {
		return _size_array;
	}
	void Add(T value) {
		if (_size_array + 1 < _size_memory) {
			_array[_size_array] = value;
			_size_array++;
		}
		else {
			_size_memory += _additional_memory;
			T* newArray = new T[_size_memory];
			for (int i = 0; i < _size_array; i++)
			{
				newArray[i] = _array[i];
			}
			newArray[_size_array] = value;
			_size_array++;
			delete[] _array;
			_array = newArray;
		}
	}
	void Remove(int index, int count = 1) {
		for (int i = index; i < _size_array - count; i++)
		{
			_array[i] = _array[i + count];
		}
		_size_array -= count;
	}
	void Print() {
		for (int i = 0; i < _size_array; i++)
		{
			cout << _array[i] << "\t";
		}
		cout << endl;
	}
	void Clear() {
		delete[]_array;
		_size_array = 0;
		_size_memory = _additional_memory;
	}
};

