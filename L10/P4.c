#include <stdlib.h>
#include <stdio.h>
int w = 0;
void binarySearch(int matrice[100][100], int linie_inceput,int coloana_inceput,int linie_finala,int coloana_finala,int nr)
{
	int mijloc_linie = (linie_inceput + linie_finala) / 2;
	int mijloc_coloana = (coloana_inceput + coloana_finala) / 2;
	if (linie_inceput>linie_finala||coloana_inceput>coloana_finala)
	return ;

	
		if (nr == matrice[mijloc_linie][mijloc_coloana])
			w = 1;
		else if (nr < matrice[mijloc_linie][mijloc_coloana])
		{
			binarySearch(matrice, linie_inceput, coloana_inceput, mijloc_linie, mijloc_coloana - 1, nr);
			binarySearch(matrice, linie_inceput, coloana_inceput, mijloc_linie - 1, mijloc_coloana, nr);
		}
		else
		{
			binarySearch(matrice, mijloc_linie, mijloc_coloana + 1, linie_finala, coloana_finala, nr);
			binarySearch(matrice, mijloc_linie + 1, mijloc_coloana, linie_finala, coloana_finala, nr);
			binarySearch(matrice, mijloc_linie - 1, mijloc_coloana + 1, linie_finala, coloana_finala, nr);
	
		}
	
}


int main()
{
	int mat[100][100];
	int n = 5;
	FILE* f = fopen("matrice.txt", "r");
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
	fscanf(f, "%d", &mat[i][j]);
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <=n; j++)
			printf("%d ", mat[i][j]);
		printf("\n");
	}
	int nr;
	printf("nr ");
	scanf("%d", &nr);
			binarySearch(mat, 1,1,n,n,nr);
			if (w == 1)
				printf("DA");
			else
				printf("NU");
	return 0;
}