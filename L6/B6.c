#include <stdlib.h>
#include <stdio.h>
int n, st[100], v[100],m;
void afisare(int k)
{
	int i;
	for (i = 1; i <= k; i++)
		printf("%d ", v[st[i]]);
	printf("\n");
}
int valid(int k)
{
	int i;
	for (i = 1; i <= k - 1; i++)
		if (st[k] == st[i])
		
			return 0;
	return 1;
}
void back(int k)
{
	int i;
	for (i = 1; i <= m; i++)
	{
		st[k] = i-1;
		if (valid(k))
			if (k == n)
				afisare(k);
			else
				back(k + 1);
	}
}
int main()
{
	printf("n= ");
	scanf("%d", &n);
	printf("m= ");
	scanf("%d", &m);
	int i,aux;
	for (i = 0; i < m; i++)
	{
		printf("v[%d]= ", i);
		scanf("%d", &v[i]);
	}
	
	back(1);

	system("pause");
	return 0;
}