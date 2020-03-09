#ifndef MYSTRING_H
#define MYSTRING_H

#include <iostream>
#include <cstring>

using std::swap;

class MyString
{
public:
	MyString();										//конструктор по умолчанию
	MyString(const MyString &string);				//конструктор копирования [MyString copyString(string);]
	MyString(const char* string);					//конструктор копирования [MyString copyString(string);]

	MyString& operator= (const MyString &string);	//оператор присваивания копированием
	MyString& operator= (const char * string);		//оператор присваивания копированием

	MyString operator+ (MyString &string);			//сложение
	MyString operator+ (const char * string);		//сложение

	MyString& operator+= (MyString& string);		//сложение и присваивание
	MyString& operator+= (const char * string);		//сложение и присваивание

	bool	operator== (MyString& string);			//равенство строк
	bool	operator== (const char* string);		//равенство строк

	MyString	reverse();							//разворот строки
	unsigned	size();								//размер
	bool		isEmpty();							//проверка, пустая ли строка


	friend std::ostream& operator<< (std::ostream& stream, const MyString &string) {
		stream << string._data;
		return stream;
	}

	friend std::istream& operator >> (std::istream& stream, const MyString &string) {
		//дополнить код
		return stream;
	}

	~MyString();									

private:
	char*			_data;
	unsigned int	_size;
};

#endif //MYSTRING_H