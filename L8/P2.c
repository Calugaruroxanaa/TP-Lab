#include <stdlib.h>
#include <stdio.h>
int tail_recursive(int n)
{
	if (n < 2)
		return 1;
	else
		return n * tail_recursive(n - 1);
}
int non_tail_recursive(int n)
{
	int p = 1;
	if (n < 2)
		return 1;
	else
		p= n * non_tail_recursive(n - 1);
	return p;
}
int indirect_recursive1(int n)
{
	if (n < 2)
		return 1;
	else
		return n * indirect_recursive2(n - 1);
}
int indirect_recursive2(int n)
{
	if (n < 2)
		return 1;
	else
		return n * indirect_recursive2(n - 1);
}
int main()
{
	int n;
	printf("n= ");
	scanf("%d", &n);
	int f1 = tail_recursive(n);
	int f2 =non_tail_recursive(n);
	int f3 = indirect_recursive1(n);
	printf("Factorialul este %d\n",f1);
	printf("Factorialul este %d\n", f2);
	printf("Factorialul este %d\n", f3);
	system("pause");
	return 0;
}