#include <stdio.h>

void solve(double h, double c, double t)
{
    int check[3] = {0};
    if (h > 50)
        check[0]++;
    if (c < 0.7)
        check[1]++;
    if (t > 5600)
        check[2]++;

    int sum = check[0] + check[1] + check[2];
    if (sum == 0)
        printf("5\n");
    else if (sum == 1)
        printf("6\n");
    else if (sum == 3)
        printf("10\n");
    else if (sum == 2)
    {
        if (check[0] && check[1])
            printf("9\n");
        if (check[0] && check[2])
            printf("7\n");
        if (check[1] && check[2])
            printf("8\n");
    }
}

int main()
{
    int T;
    double h, c, t;
    scanf("%d", &T);
    while(T--)
    {
        scanf("%lf%lf%lf", &h, &c, &t);
        solve(h, c, t);
    }
    return 0;
}