#include <stdio.h>
int main()
{
    long long int c, h, e, f;
    c = h = e = f = 0;

    char ch;
    while(scanf("%c", &ch) && (ch != '\n'))
    {
        switch(ch)
        {
            case 'C': c++; break;
            case 'H': if (h < c) h++; break;
            case 'E': if (e < h) e++; break;
            case 'F': if (f < e) f++; break;
            default: break; 
        }
    }
    printf("%lld\n", f);
    return 0;
}