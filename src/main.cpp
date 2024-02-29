#include <iostream>
#include "integerArray.h"

int main (int argc, char* argv)
{
	setlocale(LC_ALL, "ru");
	
	try
	{
		//IntegerArray m(-1); //предоставление неправильной длины массиву
		IntegerArray m1(3);//создание контейнера
		m1[0] = 1;
		m1[1] = 2;
		m1[2] = 3;
		m1.insertBefore(5, 2);
		std::cout << "m1: ";
		for (int i = 0; i < m1.getLength(); ++i)
		{
			std::cout << m1[i] << " ";
		}
		std::cout << "\n" << std::endl;

		IntegerArray m2;
		m2 = m1; //копирование контейнера
		std::cout << "m2: ";
		for (int i = 0; i < m2.getLength(); ++i)
		{
			std::cout << m2[i] << " ";
		}
		std::cout << "\n" << std::endl;

		std::cout << "m1[0] = " << m1[0] << std::endl;
		std::cout << "m1[1] = " << m1[1] << std::endl;
		std::cout << "m1[2] = " << m1[2] << std::endl;
		std::cout << "m1[3] = " << m1[3] << std::endl;
		//std::cout << "m1[4] = " << m1[4] << std::endl;//обращение по несуществующему индексу
		//m1[4] = 27; //обращение по несуществующему индексу (выход за пределы массива)
		std::cout << "\n" << std::endl;

		m1.resize(5);//изменить размер контейнера;
		std::cout << "m1: ";
		for (int i = 0; i < m1.getLength(); ++i)
		{
			std::cout << m1[i] << " ";
		}
		std::cout << "\n" << std::endl;

		m1.insertAtBeginning(7);//вставить 1 элемент в контейнер
		std::cout << "m1: ";
		for (int i = 0; i < m1.getLength(); ++i)
		{
			std::cout << m1[i] << " ";
		}
		std::cout << "\n" << std::endl;

		m1.insertAtEnd(12);//вставить последний элемент в контейнер
		std::cout << "m1: ";
		for (int i = 0; i < m1.getLength(); ++i)
		{
			std::cout << m1[i] << " ";
		}
		std::cout << "\n" << std::endl;

		m1.remove(1);//удалить элемент из контейнера.
		std::cout << "m1: ";
		for (int i = 0; i < m1.getLength(); ++i)
		{
			std::cout << m1[i] << " ";
		}
		std::cout << "\n" << std::endl;		
	}
	catch (ArrayException& ex)
	{
		std::cerr << "An array exception occurred: " << ex.what() << std::endl;
	}
	catch (const std::exception& ex)
	{
		std::cerr << "Some other std::exception occurred " << ex.what() << std::endl;
	}

	return 0;
}