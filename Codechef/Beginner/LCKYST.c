#include <stdio.h>

int calc(int n)
{
	int cnt5 =0, cnt2 = 0;
	int temp = n, ans;

	while( (temp % 2) == 0)
	{
		cnt2++;
		temp /= 2;
	}

	temp = n;
	while( (temp % 5) == 0)
	{
		cnt5++;
		temp /= 5;
	}

	ans = n;
	while(cnt5 > cnt2)
	{
		 ans *= 4;
		 cnt2 += 2;
	}

	return ans;
}

int main()
{
	int ans, n, i, a[100001];
	scanf("%d",&n);

	for (i=0;i<n;i++) scanf("%d", &a[i]);
	
	for (i=0;i<n;i++)
	{
		ans = calc(a[i]);
		printf("%d\n", ans);
	}

	return 0;
}