#include<stdio.h>
#include <stdlib.h>
void quicksort(int* a, int inceput, int sfarsit)
{
	int pivot, i, j, aux;
	if (inceput < sfarsit)
	{
		pivot =inceput; 
		i = inceput;
		j = sfarsit;
		while (i < j) 
		{
			while (a[i] <= a[pivot] && i <=sfarsit)
				i++;
			while (a[j] > a[pivot] && j >=inceput)
				j--;
			if (i < j) 
			{
				aux = a[i];
				a[i] = a[j];
				a[j] = aux;
			}
		}
		aux=a[j];
		a[j] = a[pivot];
		a[pivot] =aux;
		quicksort(a, inceput, j - 1);
		quicksort(a, j + 1,sfarsit);
	}
}
int main()
{
	int a[20], n, i;
	printf("Introduceti numarul de elemente\n");
	scanf("%d", &n);
	for (i = 0; i < n; i++)
	{
		printf("a[%d]= ",i+1);
		scanf("%d", &a[i]);
	}
	quicksort(a, 0, n - 1);

	printf("Vector sortat\n");
	for (i = 0; i < n; i++)
		printf("%d ", a[i]);
	system("pause");
	return 0;
}
