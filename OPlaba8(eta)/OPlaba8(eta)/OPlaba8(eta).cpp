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
void fileinmass(char*);
void sortuvannya(void);
char MASS[100][300]; //// 100 lines
int lines = 0;
int main()
{
	filecreate();
	fileout("Poch.txt");
	fileinmass("Poch.txt");
	
	sortuvannya();
	std::cout << "\n  MASS:\n";
	
	for (int i = 0;i < lines;i++) {
		std::cout << MASS[i];
	}
	
	std::cout << "\n" <<lines <<"\n";
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
	std::cout << "text file: \n";
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

void fileinmass(char* filest) {
	FILE* fp;
	fp = fopen(filest, "rt");
	
	
	if (fp == NULL) std::cout << "file not found";

	else
	{

		while (!feof(fp))
		{
			if (fgets(MASS[lines++], 300, fp)) {				
			}

		}
		fclose(fp);
	}
}

void sortuvannya() {
	char literal, literal1;
	int q = 1, r;
	char string[60];
	char *delimiter = "., ";
	char *p, *w;
	//for (int k = 0;k < lines;k++) {
		for (int i = 0;i < lines;i = i + 2) {
			if ((i + 2) > lines)break;
			literal = MASS[i][0]; literal1 = MASS[i + 2][0];
			while (int(literal) == int(literal1)) {
				literal = MASS[i][0 + q]; literal1 = MASS[i + 2][0 + q];
				q++;
			}
			q = 0;
			if (int(literal) > int(literal1)) {
				strcpy(string, MASS[i]);				
				strcpy(MASS[i], MASS[i + 2]);
				strcpy(MASS[i + 2], string);			
			}

		}
	//}
}
	/*for (int i = 1;i < lines;i = i + 2) {
		p = strtok(MASS[i], delimiter);
		w = strtok(NULL, delimiter);
		for (int k = 0;k < strlen(MASS[i]);k++) {			
			if (strlen(p) > strlen(w)) { r = strlen(p); }
			else r = strlen(w);
			do
			{
				for (int y = 0;y < r;y++) {
					if (int(p[y])>int(w[y]))
						strcpy(string, w);
					strcpy(w, p);
					strcpy(p, string);
				}
			p = strtok(NULL, delimiter);
			if (p == NULL)break;
			w = strtok(NULL, delimiter);
			
			} while (w != NULL);
		}
	}
	}*/



