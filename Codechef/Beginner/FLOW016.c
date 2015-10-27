#include <stdio.h>

int gcd(int a, int b)
{
    if (b == 0)
        return a;
    else
        return gcd(b, a % b);
}   

int lcm(int a, int b)
{
    return (a*b)/gcd(a,b);    
}

int main()
{
    int t, a, b;
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d%d", &a, &b);
        printf("%d %d\n", gcd(a,b), lcm(a,b));
    }
    return 0;
}