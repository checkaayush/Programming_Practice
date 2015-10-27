#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;
int main()
{
    int t, i, j;
    char ch[6], hc[6], temp;
    scanf("%d", &t);
    while(t--)
    {
        scanf("%s", ch);
        strcpy(hc, ch);
        int len = strlen(hc);
        reverse(&hc[0], &hc[len]);

        if(!strcmp(ch, hc))
            printf("wins\n");
        else
            printf("losses\n");
    }
    return 0;
}

// i = 0;
// j = strlen(hc) - 1;
// while (i < j)
// {
//     temp = hc[i];
//     hc[i] = hc[j];
//     hc[j] = temp;
//     i++;
//     j--;
// }
