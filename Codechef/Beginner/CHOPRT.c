#include <stdio.h>
int main()
{
    int t;
    long long a, b;
    scanf("%d", &t);
    while(t--)
    {
        scanf("%lld%lld", &a, &b);
        char ch = (a > b) ? ('>') : ((a < b) ? ('<') : ('='));
        printf("%c\n", ch);
    }
    return 0;
}