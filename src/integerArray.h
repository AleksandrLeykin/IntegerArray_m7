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
	//������������ constructors
	//IntegerArray() = default; //�������� ������� �������(creating an empty array)
	IntegerArray() { m_data = nullptr; m_length = 0; }
	IntegerArray(int length); //�������� ������� ������������ �����(creating an array of a specific length)
	//IntegerArray(const IntegerArray& arr);//�����������(copy) �� ���� ��� ������������!!!!

	//destructor
	~IntegerArray();
	//�������� ������� � ��������� ��� ����� � 0
	void erase();

	//���������� ����������(operator overloads)
	int& operator[](int index);
	IntegerArray& operator=(const IntegerArray& arr);

	//������� ����� �������(return array length)
	int getLength() const { return m_length; }
	//��������� ����� ������� � ������� ������(changing array length with data loss)
	void reallocate(int newLength);
	//��������� ����� ������� � ����������� ������(changing the length of an array while saving data)
	void resize(int newLength);
	//������� ��������(insert)
	void insertBefore(int value, int index);
	//�������� ��������(deleting an element)
	void remove(int index);
	//������� 1 ��������(insert)
	void insertAtBeginning(int value) { insertBefore(value, 0); }
	//������� ���������� ��������(insert)
	void insertAtEnd(int value) { insertBefore(value, m_length); }
private:
	int m_length; //������(�����) �������(array size)
	int* m_data; //�������� ������(stored data)
};