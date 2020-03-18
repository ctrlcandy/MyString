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

MyString MyString::cat(const MyString& first) const {
	MyString result;
	result._size = this->_size + first._size;
	strcat(result._data, this->_data);
	strcat(result._data, first._data);

	return result;
}

MyString& MyString::mutableCat(const MyString& first) {
	char* buf = new char[this->_size + first._size + 1];
	if (this->_data) {
		strcpy(buf, this->_data);
		delete[] this->_data;
	}
	strcat(buf, first._data);
	this->_data = buf;
	this->_size = this->_size + first._size;

	return *this;
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
	/*
	MyString buf(string);
	_size = buf._size;
	swap(_data, buf._data); 
	*/

	delete[] _data;
	_size = strlen(string);
	_data = new char[_size + 1];
	strcpy(_data, string);

	return *this;
}

MyString MyString::operator+ (MyString& string) const {
	return this->cat(string);
}

MyString MyString::operator+ (const char* string) const { 
	MyString tmp(string);
	return this->cat(tmp);
} 

MyString& MyString::operator+= (const MyString& string)  {
	mutableCat(string);
	return *this;
} 

MyString& MyString::operator+= (const char* string) {
	MyString tmp(string);
	mutableCat(tmp);
	return *this;
} 

bool MyString::operator== (const MyString& string) const {
	return strcmp(this->_data, string._data) == 0;
} 

bool MyString::operator== (const char* string) const {
	return strcmp(this->_data, string) == 0;
} 

MyString MyString::reverse() {
	MyString tmp(*this);
	for (size_t i = 0; i < this->_size; i++) {
		this->_data[i] = tmp._data[this->_size - 1 - i];
	}

	return *this;
}

unsigned MyString::size() const {
	return _size;
}

bool MyString::isEmpty() const {
	return _size == 0;
}

//void MyString::print() const {
//	std::cout << this->_data << std::endl;
//}