#include <stdio.h>
int main()
{
    int t, i;
    scanf("%d", &t);
    char str[51];
    
    while(t--)
    {
        int alph[26] = {0}, sum = 0;
        scanf("%s", str);

        for (i = 0; str[i] != '\0'; i++)
        {
            alph[str[i] - 97]++;
            sum++;
        }

        for (i = 0; i < 26; i++)
        {
            if (2 * alph[i] == sum)
            {
                printf("YES\n"); 
                break;
            }
        }

        if (i == 26)
            printf("NO\n");
    }
    return 0;
}