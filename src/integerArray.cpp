#include "integerArray.h"

//#include <algorithm>
#include <cassert>
#include <iostream>

IntegerArray::IntegerArray(int length) : m_length(length)
{
	//assert(length >= 0);
	if (length < 0)
	{
		throw ArrayException("invalid length < 0 ");
	}
	if (length > 0)
	{
		m_data = new int [length];
	}
}

//IntegerArray::IntegerArray(const IntegerArray& arr)
//{
//	//��������� ������� ������ �������(setting the size of the new array)
//	reallocate(arr.getLength());
//	for (int i = 0; i < m_length; i++)
//	{
//		 m_data[i] = arr.m_data[i];
//	}
//}

IntegerArray::~IntegerArray()
{
	delete[] m_data;
	std::cout << "�������� ����������" << std::endl;
}
//�������� ������� � ��������� ��� ����� � 0
//erasing an array and setting its length to 0
void IntegerArray::erase() //�������
{
	delete[] m_data;
	m_data = nullptr;
	m_length = 0;
}

int& IntegerArray::operator[](int index)
{
	//assert(index >= 0 && index < m_length);
	if (index < 0 || index >= m_length)
	{
		throw ArrayException("Invalid index");
	}
	return m_data[index];
}

IntegerArray& IntegerArray::operator=(const IntegerArray& arr)
{
	//�������� �� ����������� �� �� � ���� ������
	if (&arr == this)
		return *this;
	//��������� ������� ������ �������(setting the size of the new array)
	reallocate(arr.getLength());
	//std::copy_n(arr.m_data, m_length, m_data);
	for (int i = 0; i < m_length; i++)
	{
		m_data[i] = arr.m_data[i];
	}
	return *this;
}

void IntegerArray::reallocate(int newLength)
{
	//�������� ������� � ��������� ��� ����� � 0
	erase();
	if (newLength <= 0)
		return;
	m_data = new int[newLength];
	m_length = newLength;
}

void IntegerArray::resize(int newLength)
{
	//�� ������
	if (newLength == m_length)
		return;
	//����� � 0
	if (newLength <= 0)
	{
		erase();
		return;
	}
	//�������� ������ ������� ��������������� �����(creating a new array of the appropriate length)
	int* data{ new int[newLength] };
	if (m_length > 0)
	{
		if (newLength > m_length)
		{
			for (int i = 0; i < m_length; i++)
			{
				data[i] = m_data[i];
			}
			data[m_length] = 0;
		}
		if (newLength < m_length)
		{
			for (int i = 0; i < newLength; i++)
			{
				data[i] = m_data[i];
			}
		}
	}
	delete[] m_data;//������� ������ ������
	m_data = data;//��������� �� ����� ������(point to a new array)
	m_length = newLength;//������������ ����� �����(set new length)
}
// ��������(insert)
void IntegerArray::insertBefore(int value, int index)
{
	//assert(index >= 0 && index <= m_length);
	if (index < 0 || index > m_length)
	{
		throw ArrayException("Invalid index");
	}
	//�������� ������ ������� �� ���� ������� ������(creating a new array with one more element)
	int* data = new int[m_length + 1];
	//�������� �������� �� �������(copy elements to index)
	for (int i = 0; i < index; i++)
	{
		data[i] = m_data[i];
	}
	//��������� ��������(insert value)
	data[index] = value;
	//�������� �������� ����� �������(copy the elements after the index)
	for (int i = index + 1; i <= m_length; i++)
	{
		data[i] = m_data[i -1];
	}
	delete[] m_data;
	m_data = data;
	++m_length;
}

void IntegerArray::remove(int index)
{
	//�������� �������� �������(checking index value)
	//assert(index >= 0 && index < m_length);
	if (index < 0 || index >= m_length)
	{
		throw ArrayException("Invalid index");
	}
	//���� � ������� 1 �������, ������ ������ �������(if there is 1 element in the array, make the array null)
	if (m_length == 1)
	{
		erase();
		return;
	}
	//�������� ������ ������� �� 1 ������� ������ �������(creating a new array with 1 element less than the old one)
	int* data{ new int[m_length - 1] };
	//����������� ��� �������� �� �������(copy all of the elements up to the index)
	for (int i = 0; i < index; i++)
	{
		data[i] = m_data[i];
	}
	//���������� ��� �������� ����� ���������� ��������(copy all of the values after the removed element)
	for (int i = index; i < m_length - 1; i++)
	{
		data[i] = m_data[i + 1];
	}
	//delete old array
	delete[] m_data;
	m_data = data;
	--m_length;
}
