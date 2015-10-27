#include<stdio.h>

int main()
{
	int t;
	long long int n,k;

	scanf("%d",&t);
	while(t--)
	{
		//k: Total time
		//n: # kinds of stones
		scanf("%lld%lld",&n,&k);

		long long int i,A[100005],B;

		// Time per stone of a kind
		for(i=0;i<n;i++)
		{
			scanf("%lld",&A[i]);

			A[i] = k / A[i];// # stones of each kind 
		}

		//Profit per stone
		long long int max,temp;
		for(i=0;i<n;i++)
		{
			scanf("%lld",&B);

			temp = A[i] * B;

			if(i==0) max = A[0]*B;

			if(temp > max) max = temp;
		}

		printf("%lld\n",max);

	}
	return 0;
}