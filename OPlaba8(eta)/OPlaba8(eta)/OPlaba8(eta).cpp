// OPlaba8(eta).cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <errno.h>
#include <ctype.h>
#include <string.h>
#include <cstdio>
#include <conio.h>

void filecreate(void);
void fileout(char*);
void fileinmass()

int main()
{
	filecreate();
	fileout("Poch.txt");
	fileinmass

	


	system("pause");
}

void filecreate() {
	FILE* fp = fopen("Poch.txt", "wt");
	if (fp == NULL) {
		std::cout << "error in creat";
	}
	char sumbol;

	do
	{
		sumbol = _getch();
		std::cout << sumbol;
		if (sumbol != 3) {
			if (sumbol == '\r') {
				sumbol = '\n';
				std::cout << "\n";
			}
			fputc(sumbol, fp);
		}

	} while (sumbol != 3);
	std::cout << "\n";
	fclose(fp);
	fseek(fp, 0L, SEEK_SET);
}
void fileout(char* filest) {
	FILE* fp;
	fp = fopen(filest, "rt");
	char strfile[100];
	char ch;
	int i = 0;
	if (fp == NULL) std::cout << "file not found";
	else
	{
		
		while (!feof(fp))	
		{
			if (fgets(strfile,100,fp)) {
				puts(strfile);
				
			}
			
		}
		fclose(fp);
	}
}


