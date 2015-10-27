#include<stdio.h>
int main()
{
	int t,i,n,b;
	long long sum,check,count;
	
	scanf("%d",&t);

	while(t--)
	{
		sum=0,count=0;
		scanf("%d",&n);

		for(i=0;i<n;i++)
		{
			scanf("%d",&b);

			if(b==0)
				count++;

			sum+=b;
		}

		n-=count;

		if( sum>=100 && (sum-n)<=99 )
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}