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
#define _CRT_SECURE_NO_WARNINGS
void filecreate(void);
void fileout(char*);
void writefiles(char*);
//void fileinmass(char*);
void sortuvannya(void);
char MASS[100][300]; //// 100 lines
int lines = 0;
int main()
{
	filecreate();
	fileout("Poch.txt");
	//fileinmass("Poch.txt");
	writefiles("Poch.txt");	
	fileout("parnie.txt");
	fileout("neparnie.txt");
	/*std::cout << "\n  MASS:\n";

	for (int i = 0;i < lines;i++) {
		std::cout << i << ": " << MASS[i];
	}
	
	std::cout << "\n";
	for (int i = 0;i < lines;i++) {
		std::cout << i << ": " << MASS[i];
	}
	std::cout << "\n" << lines << "\n";*/
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

		if (sumbol != 3) {
			if (sumbol == '\r')
				sumbol = '\n';
			std::cout << sumbol;

			fputc(sumbol, fp);
		}

	} while (sumbol != 3);


	fclose(fp);
	std::cout << '\n';

}
void fileout(char* filest) {
	std::cout << "text file: \n";
	FILE* fp;
	fp = fopen(filest, "r+t");
	char strfile[100];
	char ch;
	int i = 0;
	if (fp == NULL) std::cout << "file not found";
	else
	{

		while (!feof(fp))
		{
			if (fgets(strfile, 100, fp)) {
				std::cout << strfile;

			}

		}

	}
	fclose(fp);
	std::cout << "\n";

}
void writefiles(char* file) {
	FILE *fpfile = fopen(file, "r+t");
	FILE *parnie = fopen("parnie.txt", "wt");
	FILE *neparnie = fopen("neparnie.txt", "wt");
	int i = 0;
	char STR[100];
	if (fpfile == NULL) { std::cout << "file not found1"; }
	if (parnie == NULL) { std::cout << "file not found2"; }
	if (neparnie == NULL) { std::cout << "file not found3"; }
	
		while (!feof(fpfile))
		{
			if (i%2==0) {
				fgets(STR, sizeof(STR), fpfile);
				fputs(STR, parnie);
			}
			else {
				fgets(STR, sizeof(STR), fpfile);
				fputs(STR, neparnie);
			}

			i++;
		}

	
	fclose(fpfile);
	fclose(parnie);
	fclose(neparnie);
}
/*void fileinmass(char* filest) {

	FILE *fp = fopen(filest, "rt");

	if (fp == NULL) std::cout << "file not found";

	else
	{

		while (!feof(fp))
		{
			fgets(MASS[lines++], 301, fp);

			if (MASS[lines - 1][0] == NULL) lines--;


		}
		

	}
	fclose(fp);
}*/

/*void sortuvannya() {
	char literal, literal1;
	int q = 0, r;
	char string[300], MASS1[20][30];
	char *delimiter = " ";
	//char *p, *w, *s = "           ";
	for (int k = 0;k < lines;k++) {
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
	}
}

/*for (int i = 1;i < lines;i = i + 2) {
int l = 0;
p = strtok(MASS[i], delimiter);

while (p != NULL) {
strcpy(MASS1[l], p);
p = strtok(NULL, delimiter);
l++;
}
for (int b = 0;b < l;b++){
for (int a = 0;a < l;a++) {
if (strlen(MASS1[a]) > strlen(MASS1[a + 1])) { r = strlen(MASS1[a]); }
else r = strlen(MASS1[a + 1]);
for (int y = 0;y < r;y++) {
if (int(MASS1[a][y]) > int(MASS1[a + 1][y])) {
strcpy(string, MASS1[a]);
strcpy(MASS1[a], MASS1[a + 1]);
strcpy(MASS1[a + 1], string);
break;
}

}



}
}
std::cout << "MASS111: ";
for (int n = 0;n < l;n++) {
std::cout << n << ": " << MASS1[n] << "\n";
}
/*strcpy(MASS[i]," ");
for (int n = 0;n < l;n++) {
strcat(MASS[i], MASS1[n]);
}*/
//}
//}*/

