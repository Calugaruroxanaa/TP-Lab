#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
int BOMBE = 3;
char b[10][10];
void citire(char matrice[10][10])
{
	int i, j;
	FILE* f;
	f = fopen("matr.txt", "r");
	for (i = 0; i < 3; i++)
		for (j = 0; j < 3; j++)
			fscanf(f, "%c", &matrice[i][j]);
	fclose(f);
	for (i = 0; i < 10; i++)
		for (j = 0; j < 10; j++)
			b[i][j] = matrice[i][j];
}
int valid(int linie, int coloana)
{
	if ((linie >= 0) && (linie < 10) && (coloana >= 0) && (coloana < 10))
		return 1;
	else
		return 0;
}
void miscare(int* x, int* y)
{
	printf("Introduceti linie ");
	scanf("%d", x);
	printf("Introduceti coloana ");
	scanf("%d", y);
	return;
}
void afisare(char matrice2[10][10])
{
	printf("  ");
	for (int i = 0; i < 10; i++)
		printf("%d ", i);
	printf("\n\n");
	for (int i = 0; i < 10; i++)
	{
		printf("%d  ", i);
		for (int j = 0; j < 10; j++)
			printf("%c ", matrice2[i][j]);
		printf("\n");


	}
	return;
}
int Count(char matrice2[10][10], int linie, int coloana)
{
	int i, count = 0;
	if (valid(linie - 1, coloana) == 1)
	{
		if (matrice2[linie - 1][coloana] == '*')
			count++;

	}
	if (valid(linie + 1, coloana) == 1)
	{

		if (matrice2[linie + 1][coloana] == '*')

			count++;

	}
	if (valid(linie, coloana + 1) == 1)
	{

		if (matrice2[linie][coloana + 1] == '*')
			count++;

	}
	if (valid(linie, coloana - 1) == 1)
	{

		if (matrice2[linie][coloana - 1] == '*')

			count++;

	}
	if (valid(linie - 1, coloana + 1) == 1)
	{
		if (matrice2[linie - 1][coloana + 1] == '*')
			count++;
	}
	if (valid(linie - 1, coloana - 1) == 1)
	{
		if (matrice2[linie - 1][coloana - 1] == '*')
			count++;

	}
	if (valid(linie + 1, coloana + 1) == 1)
	{
		if (matrice2[linie + 1][coloana + 1] == '*')
			count++;

	}
	if (valid(linie + 1, coloana - 1) == 1)
	{
		if (matrice2[linie + 1][coloana - 1] == '*')
			count++;

	}
	return count;
}
int bomba(char matricee[10][10], int linie, int coloana)
{
	if (matricee[linie][coloana] == '*')
		return 1;
	else
		return 0;
}
int rezolvare(char matrice[10][10], char matrice2[10][10], int bombe[][2], int linie, int coloana, int* mutariramase)
{
	int count;
	if (matrice[linie][coloana] != '-')
		return 0;
	if (matrice[linie][coloana] == '*')
	{
		matrice2[linie][coloana] = '*';
		return 1;
	}
	else
	{
		count = Count(matrice2, linie, coloana);
		(*mutariramase)--;
		matrice[linie][coloana] = count+'0' ;
		if (count != 0)
		{
			if (valid(linie - 1, coloana) == 1)
			{
				if (matrice2[linie - 1][coloana] != '*')
					rezolvare(matrice, matrice2, bombe, linie - 1, coloana, mutariramase);

			}
			if (valid(linie + 1, coloana) == 1)
			{

				if (matrice2[linie + 1][coloana] != '*')

					rezolvare(matrice, matrice2, bombe, linie + 1, coloana, mutariramase);

			}
			if (valid(linie, coloana + 1) == 1)
			{

				if (matrice2[linie][coloana + 1] != '*')

					rezolvare(matrice, matrice2, bombe, linie, coloana + 1, mutariramase);

			}
			if (valid(linie, coloana - 1) == 1)
			{

				if (matrice2[linie][coloana - 1] != '*')

					rezolvare(matrice, matrice2, bombe, linie, coloana - 1, mutariramase);

			}
			if (valid(linie - 1, coloana + 1) == 1)
			{
				if (matrice2[linie - 1][coloana + 1] != '*')

					rezolvare(matrice, matrice2, bombe, linie - 1, coloana + 1, mutariramase);

			}
			if (valid(linie - 1, coloana - 1) == 1)
			{
				if (matrice2[linie - 1][coloana - 1] != '*')

					rezolvare(matrice, matrice2, bombe, linie - 1, coloana - 1, mutariramase);

			}
			if (valid(linie + 1, coloana + 1) == 1)
			{
				if (matrice2[linie + 1][coloana + 1] != '*')
					rezolvare(matrice, matrice2, bombe, linie + 1, coloana + 1, mutariramase);

			}
			if (valid(linie + 1, coloana - 1) == 1)
			{
				if (matrice2[linie + 1][coloana - 1] != '*')
					rezolvare(matrice, matrice2, bombe, linie + 1, coloana - 1, mutariramase);

			}
		}
		return 0;
	}
}
void initializare(char matrice[10][10], char matrice2[10][10])
{
	srand(time(NULL));
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			matrice[i][j] = matrice2[i][j] = '-';
		}
	}
	return;
}
void rezolva()
{
	int gameover = 0;
	char matrice[10][10], matrice2[10][10];
	int mutariramase = 9 - BOMBE, x, y;
	int bombe[10][10];
	initializare(matrice, matrice2);
	int miscarecurenta = 0;
	miscare(&x, &y);
    
	while (gameover == 0)
	{
		printf("tabla curenta:\n");
		afisare(matrice);
		if (miscarecurenta == 0)
		{
			if (bomba(matrice, x, y) == 1)
			miscare(&x, &y);	
		}
		miscarecurenta++;
		gameover = rezolvare(matrice, matrice2, bombe, x, y, &mutariramase);
		if ((gameover == 0) && (mutariramase == 0))
		{
			printf("Ai castigat!\n");
			gameover = 1;
		}
	}
	return;
}


int main()
{
	char matrice[10][10];

	citire(matrice);

	rezolva();
	system("pause");
	return 0;
}