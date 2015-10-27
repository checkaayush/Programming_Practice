#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int main()
{
	long long int t, a, i, n, min, pos, cost = 0;
	scanf("%lld", &t);
	
	while(t--)
	{
		scanf("%lld", &n);
		min = INT_MAX;		

		for (i = 0; i < n; i++)
		{
			scanf("%lld", &a);

			if (a < min)
				min = a;
		}

		cost = (min * (n - 1));
		printf("%lld\n", cost);
	}

	return 0;
}