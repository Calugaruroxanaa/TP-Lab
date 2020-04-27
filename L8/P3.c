#include <stdio.h>
#include <stdlib.h>
int binarySearch(int a[], int inceput, int sfarsit, int x)
{
	if (inceput > sfarsit)
		return -1;
	int mijloc = (inceput + sfarsit) / 2;
	if (x == a[mijloc])
		return mijloc;
	else if (x < a[mijloc])
		return binarySearch(a, inceput, mijloc - 1, x);
	else
		return binarySearch(a, mijloc + 1, sfarsit, x);
}

int main()
{
	int i, n, a[100], k, li, lf, x;

	printf("Introduceti nr de elemente \n");
	scanf("%d", &n);
	for (i = 1; i <=n; i++)
	{
		printf("a[%d]= ", i );
		scanf("%d", &a[i]);
	}
	printf("Introduceti elementul cautat\n");
	scanf("%d", &x);

	int index = binarySearch(a, 1, n , x);

	if (index != -1)
		printf("Element %d s a gasit pe pozitia %d",x, index);
	else
		printf("Elementul nu a fost gasit");
	system("pause");
	return 0;
}