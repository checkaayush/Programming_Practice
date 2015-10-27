#include <stdio.h>
#include <stdlib.h>

int check_subsequence(int *seq, int l_seq, int *sub, int l_sub)
{
    int i, j, flag = 0;
    for (i = 0, j = 0; i < l_seq && j < l_sub; i++)
    {   
        if (seq[i] == sub[j])
        {
            flag++;
            j++;
            if (flag == l_sub)
                break;
        }
    }
    if (flag == l_sub)
        return 1;
    else
        return 0;
}

int main()
{
    int t, l_s, l_f, i;
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d", &l_s);
        int *s = (int*) malloc(l_s * sizeof(int));
        for (i = 0; i < l_s; i++)
            scanf("%d", &s[i]);

        scanf("%d", &l_f);
        int *f = (int*) malloc(l_f * sizeof(int));
        for (i = 0; i < l_f; i++)
            scanf("%d", &f[i]);

        int ans = check_subsequence(s, l_s, f, l_f);   
        
        if (ans == 1)
            printf("Yes\n");
        else
            printf("No\n");
    }
    return 0;
}