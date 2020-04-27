#include <stdio.h>
#include <stdlib.h>
void bubblesort(int a[], int n)
{
	int i, aux;
	if (n == 1)
		return;
	for ( i = 0; i < n; i++)
		if (a[i] > a[i + 1])
		{
			aux= a[i];
			a[i] = a[i + 1];
			a[i + 1] = aux;
		}
	bubblesort(a, n-1);
}
int main()
{
	int a[10], n, i;
	printf("Introduceti nr de elemente \n");
	scanf("%d", &n);
	for (i = 1; i <= n; i++)
	{
		printf("a[%d]= ", i);
		scanf("%d", &a[i]);
	}
	bubblesort(a, n);
	printf("Vector sortat\n");
	for (i = 1; i <= n; i++)
		printf("%d ", a[i]);
	system("pause");
	return 0;
}