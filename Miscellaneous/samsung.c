#include <stdio.h>
#include <limits.h>
#define N 20

int map[N][N];
int n;

int min2(int a, int b) {
  return (a < b) ? a : b;
}

int min4(int a, int b, int c, int d) {
  int minimum = min2(min2(a, b), min2(c, d));
  if (minimum == a) return 0;
  if (minimum == b) return 1;
  if (minimum == c) return 2;
  if (minimum == d) return 3;
}

int validatePosition(int i, int j) {
  if (i >=0 && i < n && j >= 0 && j < n)
    return 1;
  return 0;
}

int solve(int i, int j, int center) {

  int l = (!validatePosition(i, j-1)) ? INT_MAX : map[i][j-1];
  int u = (!validatePosition(i-1, j)) ? INT_MAX : map[i-1][j];
  int r = (!validatePosition(i, j+1)) ? INT_MAX : map[i][j+1];
  int d = (!validatePosition(i+1, j)) ? INT_MAX : map[i+1][j];

  if (l==INT_MAX && u==INT_MAX && r==INT_MAX && d==INT_MAX) return 0;

  int pos = min4(l, u, r, d);
  // printf("pos = %d\n", pos);

  switch(pos)
  {
    case 0: if (center > l) return 1 + solve(i, j-1, map[i][j-1]); else return 0;
    case 1: if (center > u) return 1 + solve(i-1, j, map[i-1][j]); else return 0;
    case 2: if (center > r) return 1 + solve(i, j+1, map[i][j+1]); else return 0;
    case 3: if (center > d) return 1 + solve(i+1, j, map[i+1][j]); else return 0;
  }
}

int main()
{
  int t, i, j, ans, max;
  scanf("%d", &t);
  
  while(t--) {
    ans = 0;
    max = 0;

    scanf("%d", &n);
    
    // Input
    for (i = 0; i < n; i++) {
      for (j = 0; j < n; j++) {
        scanf("%d", &map[i][j]);
      }
    }

    // Solve
    for (i = 0; i < n; i++) {
      for (j = 0; j < n; j++) {
        ans = solve(i, j, map[i][j]);
        // printf("(%d, %d) - %d\n", i, j, ans);
        if (ans > max)
          max = ans;
      }
    }

    // Print answer
    printf("%d\n", max + 1);
  }

  return 0;
}