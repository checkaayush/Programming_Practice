#include <stdio.h>

int main()
{
	int t, i, j, n, k, l, u;
	scanf("%d", &t);

	while(t--)
	{
		scanf("%d%d", &n, &k);
		char str[n];
		for (i = 0; i < n; i++)
			str[i] = '(';

		for (i = 0; i < k; i++)
		{
			scanf("%d%d", &l, &u);
			for (j = l; j < u; j += 2)
			{
				str[j] = '(';
				str[j + 1] = ')';
			}
		}
		str[n] = '\0';		
		printf("%s\n", str);
	}

	return 0;
}