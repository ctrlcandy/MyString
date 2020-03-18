#ifndef MYSTRING_H
#define MYSTRING_H

#include <iostream>
#include <cstring>

using std::swap;

class MyString
{
public:
	MyString();						//конструктор по умолчанию
	MyString(const MyString &string);			//конструктор копирования [MyString copyString(string);]
	MyString(const char* string);					

	MyString cat(const MyString& first) const;
	MyString& mutableCat(const MyString& first);

	MyString& operator= (const MyString &string);		//оператор присваивания копированием
	MyString& operator= (const char* string);		//оператор присваивания копированием

	MyString operator+ (MyString &string) const;		//сложение
	MyString operator+ (const char* string) const;		//сложение

	MyString& operator+= (const MyString& string);		//сложение и присваивание
	MyString& operator+= (const char* string);		//сложение и присваивание

	bool	operator== (const MyString& string) const;	//равенство строк
	bool	operator== (const char* string) const;		//равенство строк

	MyString	reverse();				//разворот строки
	unsigned	size() const;				//размер
	bool		isEmpty() const;			//проверка, пустая ли строка


	friend std::ostream& operator<< (std::ostream& stream, const MyString &string) {
		stream << string._data;
		return stream;
	}

	friend std::istream& operator >> (std::istream& stream, MyString &string) {
		stream >> string._data;
		string._size = strlen(string._data);
		return stream;
	}

	~MyString();									

private:
	char*		_data;
	unsigned int	_size;
};

#endif //MYSTRING_H