// ConsoleApplication2.cpp: ���������� ����� ����� ��� ����������� ����������.
//
#include "stdafx.h"

#include <iostream>
#include <cstring>

int main()
{
	char str1[80];
	char str2[] = "I mister";
	char str3[] = "I doter";
	
	strcpy(str1, str2);                              // �������� ������ str1 � str2
	strcpy(str2, str3); 
	strcpy(str3, str1);
	std::cout << "str1: " << str1
		<< "\nstr2: " << str2
		<< "\nstr3: " << str3;
	system("pause");
}