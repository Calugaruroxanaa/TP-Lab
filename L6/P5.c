#include <stdlib.h>
#include <stdio.h>
int n, st[100], a[100], sum;

void gaseste(int index, int sum)
{
	int i, prev, j;
	if (sum < 0)
		return;
	if (sum == 0)
	{
		for (i = 0; i < index; i++)
			printf("%d  ", a[st[i]]);
		printf("\n");
		return;
	}
	if (index == 0)
		prev = 0;
	else  prev = st[index - 1];

	for (i = prev; i < n; i++)
	{
		for (j = 0; j < index - 1; j++)
		{
			if (st[j] == i)
				return;
		}
		if (index > 0)
		{
			if ((st[index - 1] != i))
			{
				st[index] = i;

				gaseste(index + 1, sum - a[i]);
			}
		}
		else
		{
			st[index] = i;

			gaseste(index + 1, sum - a[i]);
		}
	}
}
int main()
{
	printf("S= ");
	scanf("%d", &sum);
	printf("n= ");
	scanf("%d", &n);
	int i;
	for (i = 0; i < n; i++)
	{
		printf("a[%d]=", i + 1);
		scanf("%d", &a[i]);

	}
	gaseste(0, sum);
	system("pause");
	return 0;
}