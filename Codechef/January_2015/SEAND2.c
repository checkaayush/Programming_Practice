#include<stdio.h>
int main()
{
	int t,n,i;
	long long b[105],j;

	scanf("%d",&t);
	char a[1005];

	while(t--)
	{
		scanf("%s",a);

		scanf("%d",&n);

		for(i=0;i<n;i++)
		{
			scanf("%lld",&b[i]);
		}

		printf("%s\n",a);
	}
	return 0;
}