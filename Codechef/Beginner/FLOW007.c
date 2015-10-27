#include <stdio.h> 
int main()
{
	int t, n, i;
	scanf("%d", &t);

	while(t--)
	{
		scanf("%d", &n);
		int rev_n = 0;
		while(n)
		{
			rev_n *= 10;
			rev_n += (n % 10);
			n /= 10;
		}
		printf("%d\n", rev_n);
	}
	return 0;
}