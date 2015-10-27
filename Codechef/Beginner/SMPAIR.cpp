#include <cstdio>
#include <cstdlib>
#include <algorithm>

using namespace std;

int main()
{
    int t, i, n;
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d", &n);
        int *arr = (int*) malloc(n * sizeof(int));
        for (i = 0; i < n; i++)
            scanf("%d", &arr[i]);

        sort(arr, arr + n);

        // printf("\nSorted:\n");
        // for (i = 0; i < n; i++)
        //     printf("%d ", arr[i]);
        // printf("\n");

        printf("%d\n", (arr[0] + arr[1]));
    }
    return 0;
}