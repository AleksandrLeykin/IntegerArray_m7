#pragma once

#include <exception>
#include <string>

class ArrayException : public std::exception
{
private:
	std::string m_error;
public:
	ArrayException(std::string error) : m_error(error)
	{
	}
	const char* what() const noexcept { return m_error.c_str(); }
};

class IntegerArray
{
public:
	//конструкторы constructors
	//IntegerArray() = default; //создание пустого массива(creating an empty array)
	IntegerArray() { m_data = nullptr; m_length = 0; }
	IntegerArray(int length); //создание массива определенной длины(creating an array of a specific length)
	//IntegerArray(const IntegerArray& arr);//копирование(copy) не знаю как использовать!!!!

	//destructor
	~IntegerArray();
	//стерание массива и установка его длины в 0
	void erase();

	//перегрузки операторов(operator overloads)
	int& operator[](int index);
	IntegerArray& operator=(const IntegerArray& arr);

	//возврат длины массива(return array length)
	int getLength() const { return m_length; }
	//изменение длины массива с потерей данных(changing array length with data loss)
	void reallocate(int newLength);
	//изменение длины массива с сохранением данных(changing the length of an array while saving data)
	void resize(int newLength);
	//вставка значения(insert)
	void insertBefore(int value, int index);
	//удаление элемента(deleting an element)
	void remove(int index);
	//вставка 1 элемента(insert)
	void insertAtBeginning(int value) { insertBefore(value, 0); }
	//вставка последнего элемента(insert)
	void insertAtEnd(int value) { insertBefore(value, m_length); }
private:
	int m_length; //размер(длина) массива(array size)
	int* m_data; //хранимые данные(stored data)
};