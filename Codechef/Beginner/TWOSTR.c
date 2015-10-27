#include <stdio.h>
#include <stdlib.h>

int main()
{
	int t;
	scanf("%d", &t);
	
	char x[11], y[11];
	
	while(t--)
	{	
		scanf("%s%s", x, y);
		int i = 0, flag = 1;
		
		while (x[i] != '\0')
		{
			if (x[i] != '?' && y[i] != '?' && x[i] != y[i])
			{
				flag = 0;
				break;
			}

			i++;
		}

		if (flag)
			printf("Yes\n");
		else
			printf("No\n");
	}

	return 0;
}
