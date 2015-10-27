#include <cstdio>
#include <cstring>
#include <algorithm>

int main()
{
    int t, i, j;
    char *ch, *hc, temp;
    scanf("%d", &t);
    while(t--)
    {
        scanf("%s", ch);
        strcpy(hc, ch);
        printf("%s\n", hc);
        
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

        if(!strcmp(ch, hc))
            printf("wins\n");
        else
            printf("losses\n");
    }
    return 0;
}