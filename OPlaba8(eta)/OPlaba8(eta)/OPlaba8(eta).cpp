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
void fileinmass(char* ,char* );
void sortuvannya(int);
void massintext(char* , char* );
char MASS[100][300],nMASS[100][300],MASS1[200][300]; 
int lines = 0,nlines=0,l=1,N;

int main()
{
	setlocale(LC_ALL, "Ukrainian");
	filecreate();
	fileout("Poch.txt");
	writefiles("Poch.txt");	
	fileout("parnie.txt");
	fileout("neparnie.txt");
	fileinmass("parnie.txt","neparnie.txt");
	std::cout << "\nВведіть кількість кількість рядків для сортування:";std::cin >> N;std::cout<<"\n";
	std::cout << "\n  MASS:\n";

	for (int i = 0;i < lines;i++) {
		std::cout << i << ": " << MASS[i] << "\n";
	}
	std::cout << "\n  nMASS:\n";
	for (int i = 0;i < nlines;i++) {
		std::cout << i << ": " << nMASS[i] << "\n";
	}
	std::cout << "\n lines:" << lines << "\n";
	std::cout << "\n nlines:" << nlines << "\n";
	sortuvannya(N);
	std::cout << "\n  MASS:\n";
	for (int i = 0;i < lines;i++) {
		std::cout << i << ": " << MASS[i] << "\n";
	}
	std::cout << "\n  nMASS:\n";
	for (int i = 0;i < nlines;i++) {
		std::cout << i << ": " << nMASS[i] << "\n";
	}
	std::cout << "\n  MASS1:\n";
	for (int i = 0;i < 5;i++) {
		std::cout << i << ": " << MASS1[i] << "\n";
	}
	massintext("parnie.txt", "neparnie.txt");
	fileout("parnie.txt");
	fileout("neparnie.txt");
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
			if (sumbol == '\r') {
				sumbol = '\n';
				l++;
			}
			std::cout << sumbol;

			fputc(sumbol, fp);
		}

	} while (sumbol != 3);


	fclose(fp);
	std::cout << '\n';

}
void fileout(char* filest) {
	std::cout << "\ntext file: \n";
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
void fileinmass(char* parnie, char* neparnie) {
	char helpstring[300];
	FILE *fp = fopen(parnie, "rt");
	FILE *nfp = fopen(neparnie, "rt");
	if (fp == NULL) std::cout << "file not found";
	if (nfp == NULL) { std::cout << "file not found"; }
	else
	{

		while (!feof(fp))
		{
			fgets(helpstring, 301, fp);
			strncpy(MASS[lines], helpstring, strlen(helpstring) - 1);
			lines++;		
		}
		
		while (!feof(nfp))
		{
			fgets(helpstring, 301, nfp);
			strncpy(nMASS[nlines], helpstring, strlen(helpstring) - 1);
			nlines++;			
		}
		nlines = l / 2; lines = l - nlines;

	}
	fclose(fp);
	fclose(nfp);
}

void sortuvannya(int N) {
	char literal, literal1;
	int q = 1, r;
	char string[300];
	char *delimiter = " ",*p;
	for (int k = 0;k < lines;k++) {
		for (int i = 0;i < lines;i++) {
			if ((i + 1) == lines)break;
			literal = MASS[i][0]; literal1 = MASS[i + 1][0];
			while (int(literal) == int(literal1)) {
				literal = MASS[i][0 + q]; literal1 = MASS[i + 1][0 + q];
				q++;
			}
			q = 0;
			if (int(literal) > int(literal1)) {
				strcpy(string, MASS[i]);
				strcpy(MASS[i], MASS[i + 1]);
				strcpy(MASS[i + 1], string);
			}

		}
	}


for (int i = 0;i <N;i ++) {
	int m = 0;
p = strtok(nMASS[i], delimiter);

while (p != NULL) {
strcpy(MASS1[m], p);
p = strtok(NULL, delimiter);
m++;
}
std::cout << "\n  MASS1:\n";
for (int i = 0;i < 5;i++) {
	std::cout << i << ": " << MASS1[i] << "\n";
}
for (int b = 0;b < 40;b++){
for (int a = 0;a < m;a++){
	if (a + 1 == m) break;
if (strlen(MASS1[a]) < strlen(MASS1[a + 1])) { r = strlen(MASS1[a]); }
else { r = strlen(MASS1[a + 1]); }
for (int y = 0;y < 10;y++) {
if ( int (MASS1[a][y]) > int (MASS1[a + 1][y])) {
strcpy(string, MASS1[a]);
strcpy(MASS1[a], MASS1[a + 1]);
strcpy(MASS1[a + 1], string);
break;
}
}
}
}
std::cout << "\n  MASS1:\n";
for (int i = 0;i < 5;i++) {
	std::cout << i << ": " << MASS1[i] << "\n";
}
strcpy(nMASS[i], " ");
for (int a = 0;a < m;a++) {
	strcat(nMASS[i], MASS1[a]);
	strcat(nMASS[i], " ");
}
}
}

void massintext(char* parnie, char* neparnie) {
	FILE *fpp = fopen(parnie, "wt");
	FILE *nfpp = fopen(neparnie, "wt");
	/*for (int i = 0;i < nlines;i++) {
		strcat(nMASS[i], "\n");
	}
	for (int i = 0;i < lines;i++) {
		strcat(MASS[i], "\n");
	}*/
	char sumbol;
	for (int i = 0;i < nlines;i++) {
		for (int j = 0;j < strlen(nMASS[i]);j++) {
			sumbol = nMASS[i][j];
			fputc(sumbol, nfpp);
		}
		fputc('\n', nfpp);
	}
	for (int i = 0;i < lines;i++) {
		for (int j = 0;j < strlen(MASS[i]);j++) {
			sumbol = MASS[i][j];
			fputc(sumbol, fpp);
		}
		fputc('\n', fpp);
	}
	fclose(fpp);
	fclose(nfpp);
}