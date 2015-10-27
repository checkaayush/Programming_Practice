#include <stdio.h>
int main()
{
    int t, sal;
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d", &sal);
        if (sal < 1500)
            printf("%g\n", (double)(sal << 1));
        else
            printf("%g\n", sal + 500 + 0.98*sal);
    }
    return 0;
}