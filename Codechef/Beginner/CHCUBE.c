#include <stdio.h>
#include <string.h>

#define MAX_L 1000

char color[6][MAX_L];

int adj[8][3] = {
	{0, 2, 4},
	{0, 3, 4},
	{0, 2, 5},
	{0, 3, 5},
	{1, 2, 4},
	{1, 3, 4},
	{1, 2, 5},
	{1, 3, 5}
};

int main()
{
	int t, i;
	scanf("%d",&t);

	while (t--)
	{
		for (i = 0; i < 6; i++) scanf("%s", color[i]);

		for (i = 0; i < 8; i++) 
		{
			if (!strcmp(color[adj[i][0]], color[adj[i][1]]) && !strcmp(color[adj[i][1]], color[adj[i][2]]))
			{
				printf("YES\n");
				break;
			}
		}

		if (i == 8)
			printf("NO\n");
	}
	return 0;
}