#include <stdlib.h>
#include <stdio.h>
int st[100], v[100], m;
void afisare(int k)
{
	int i;
	for (i = 1; i <= k; i++)
		printf("%d", v[st[i]]);
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
		st[k] = i - 1;
		if (valid(k))
			if (k == 4)
				afisare(k);
			else
				back(k + 1);
	}
}
int main()
{
	int i;
	printf("Cate numere isi aminteste ");
	scanf("%d", &m);
	for (i = 0; i < m; i++)
	{
		printf("v[%d]= ", i);
		scanf("%d", &v[i]);
	}

	back(1);

	system("pause");
	return 0;
}