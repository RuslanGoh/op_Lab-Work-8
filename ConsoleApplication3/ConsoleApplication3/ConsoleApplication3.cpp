// ConsoleApplication3.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"


#include <iostream>
#include <cstring>

int main()
{
	char str1[3][20];
	strcpy(str1[0], "qwe");
	strcpy(str1[1], "asd");
	strcpy(str1[2], "zxc");
	char str2[20];
	

	strcpy(str2, str1[0]);                              // копируем строку str1 в str2
	strcpy(str1[0], str1[1]);
	strcpy(str1[1], str2);
	for (int i = 0;i < 3;i++)
		std::cout << "str1: " << str1[i];
		
	system("pause");
}

