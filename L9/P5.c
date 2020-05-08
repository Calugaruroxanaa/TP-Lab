#include <stdlib.h>
#include <stdio.h>
#include <string.h>
int nou, vechi, matrice[10][10],m;
void citire()
{
	FILE* f = fopen("matrice.txt", "r");
	int i, j;
	fscanf(f, "%d", &m);
	for (i = 1; i <= m; i++)
		for (j = 1; j <= m; j++)
			fscanf(f, "%d", &matrice[i][j]);
}
void fill(int linie,int coloana)
{
	if (matrice[linie][coloana] == vechi)
	{
		matrice[linie][coloana] = nou;

		fill(linie-1, coloana);

		fill(linie + 1, coloana);

		fill(linie, coloana + 1);

		fill(linie, coloana - 1);

		fill(linie - 1, coloana + 1);

		fill(linie - 1, coloana - 1);

		fill(linie + 1, coloana + 1);

		fill(linie + 1, coloana - 1);
	}
			
}
void afiseaza(int matrice[10][10])
{
	int linie, coloana;
	for (linie =1; linie <=m; linie++)
	{
		for (coloana = 1; coloana <=m; coloana++)
			printf("%d ", matrice[linie][coloana]);
		printf("\n");
	}
}
void afiseaza_legenda()
{
	printf("Legenda culori utilizate              Legenda culori ce pot fi inserate\n");
	printf("1- rosu                               1- rosu\n");
	printf("2- galben                             2- galben\n");
	printf("3- verde                              3- verde\n");
	printf("                                      4- mov\n");
	printf("                                      5- albastru\n");
	printf("                                      6- negru\n");
	printf("\n");
}

int main()
{
	int linie, coloana;
	citire();
	printf("Matrice initiala\n");
	afiseaza(matrice);
	afiseaza_legenda();
	printf("Alegeti o pozitie \n");
	printf("Introduceti linia ");
	scanf("%d", &linie);
	printf("Introduceti coloana ");
	scanf("%d", &coloana);
	printf("Introduceti codul unei culori noi\n");
	scanf("%d", &nou);
	vechi = matrice[linie][coloana];
	fill(linie, coloana);
	printf("Matricea dupa inserare\n");
	afiseaza(matrice);
	system("pause");
	return 0;
}