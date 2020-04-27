#include <stdio.h>
#include <stdlib.h>
int suma1(int n)
{
	if (n < 2)
		return 1;
	else
		return n + suma1(n - 1);
}
int suma2(int n)
{
	int i;
	int s = 0;
	for (i = 1; i <=n; i++)
		s = s + i;
	return s;
}
int suma3(int n)
{
	int s = 0;
	int i = 0;
	while (i <= n)
	{
		s = s + i;
		i++;
	}
	return s;
}
int suma4(int n)
{
	int s = 0;
	int i = 1;
	do
	{
		s = s + i;
		i++;
	
	} while (i <= n);
	return s;
}
int main()
{ 
	int n,v1,v2,v3,v4;
	printf("n=");
	scanf("%d", &n);
	v1 = suma1(n);
	v2 = suma2(n);
	v3 = suma3(n);
	v4 = suma4(n);
	printf("Suma este %d\n", v1);
	printf("Suma este %d\n", v2);
	printf("Suma este %d\n", v3);
	printf("Suma este %d\n", v4);
	system("pause");
	return 0;
}