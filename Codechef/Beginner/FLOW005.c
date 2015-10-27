#include <stdio.h>
int main()
{
    int t, n, num_100, num_50, num_10, num_5, num_2, num_1, total;
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d", &n);
        
        num_100 = n / 100;
        n -= (num_100 * 100);
        
        num_50 = n / 50;
        n -= (num_50 * 50);
        
        num_10 = n / 10;
        n -= (num_10 * 10);

        num_5 = n / 5;
        n -= (num_5 * 5);

        num_2 = n / 2;
        n -= (num_2 * 2);

        num_1 = n;
        n -= num_1;

        printf("%d\n", num_100+num_50+num_10+num_5+num_2+num_1);
    }

    return 0;
}