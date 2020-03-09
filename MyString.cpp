#include "MyString.h"

MyString::MyString() :
	_size(0)
{
	_data = new char[1];
	_data[0] = '\0';
}

MyString::~MyString() {
	delete[] _data;
}

MyString::MyString(const MyString &string) {
	_size = string._size;
	_data = new char[_size + 1];
	strcpy(_data, string._data);
}

MyString::MyString(const char* string) {
	_size = strlen(string);
	_data = new char[_size + 1];
	strcpy(_data, string);
}

MyString& MyString::operator= (const MyString &string) {
	MyString buf(string);
	_size = buf._size;
	swap(_data, buf._data);

	/* Не реюзая код конструктора копирования */
	/* 
	delete[] _data;
	_size = string._size;
	_data = new char[_size + 1];
	strcpy(_data, string._data);
	*/

	return *this;
}

MyString& MyString::operator= (const char * string) {
	/* Добавить вариант с использованием конструктора копирования */

	std::cout << "Copy = operator for cstring" << std::endl;
	delete[] _data;
	_size = strlen(string);
	_data = new char[_size + 1];
	strcpy(_data, string);
	return *this;
}

MyString MyString::operator+ (MyString& string) {

}

MyString MyString::operator+ (const char* string) { 

} 
MyString& MyString::operator+= (MyString& string) {

} 

MyString& MyString::operator+= (const char* string) {

} 

bool MyString::operator== (MyString& string) {

} 

bool MyString::operator== (const char* string) {

} 

MyString MyString::reverse() {

}

unsigned MyString::size() {
	return _size;
}

bool MyString::isEmpty() {
	if (_size == 0)
		return true;
	else 
		return false;
}