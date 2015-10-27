#include <stdio.h>
int main()
{
	int n, t, first_dig, last_dig;
    scanf("%d", &t);
	while(t--)
    {
        scanf("%d", &n);
        
        last_dig = n % 10;
    	while(n)
        {
            if(n < 10)
                first_dig = n;
            n /= 10;
        }
        printf("%d\n", first_dig + last_dig);
    }
    return 0;
}