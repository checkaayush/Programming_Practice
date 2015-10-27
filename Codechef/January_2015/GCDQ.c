#include<stdio.h>

long long int gcd(long long int a, long long int b)
{
	if(b==0)
		return a;
	else
		return gcd( b, a%b );
}

int main()
{
	long long int t,n,q,a[100005],b[100005],c[100005],i,l,r,temp_gcd=0;

	a[0]=b[0]=c[0]=0;
	
	scanf("%lld",&t);
	
	while(t--)
	{
		scanf("%lld%lld",&n,&q);
 
		// Initial Input and GCD preprocessing
		for(i=1;i<=n;i++)
		{
			scanf("%lld",&a[i]);
			if(i==1)
			{
				b[i] = a[i];
				temp_gcd = a[i];
			}
			else
			{
				temp_gcd = gcd(temp_gcd, a[i]);
				b[i] = temp_gcd;
			}
		}
		//a[n+1]=b[n+1]=0;

		temp_gcd = a[n];
		c[n]=a[n];
		c[n+1]=0;
		for(i=n-1;i>=1;i--)
		{
			temp_gcd = gcd(temp_gcd,a[i]);
			c[i]=temp_gcd;
		}

		// For each query
		for(i=0;i<q;i++)
		{
			scanf("%lld%lld",&l,&r);

			printf("%lld\n",gcd(b[l-1],c[r+1]));
		}
	}

	return 0;
}

