#include <stdio.h>

int t[100005];

void initialize_t()
{
    int i = 0;
    for (i=0;i<100005;i++)
        t[i] = 0;
}

int main()
{
    int T, i, n, temp;
    scanf("%d", &T);
    while(T--)
    {
        scanf("%d", &n);
        initialize_t();
        
        for (i = 0; i < n; i++)
        {
            scanf("%d", &temp);
            t[temp]++;
        }

        for (i = 0; i < 100005; i++)
        {
            if ((t[i] % 2) != 0)
            {
                printf("%d\n", i);
                break;
            }
        }
    }
    return 0;
}