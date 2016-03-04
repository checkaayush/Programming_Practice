#include <cstdio>
#include <cstdlib>
#include <algorithm>

using namespace std;

bool myfunction (int i, int j) { 
	return i > j; 
}

void printArray(int* a, int n) {
	for(int i = 0; i < n; i++)
		printf("%d ", a[i]);
	printf("\n");
}

int main() {

	long long n, i, ans = 0;
	
	scanf("%lld", &n);
	
	int* a = (int*) malloc(sizeof(int)*n);

	for(i = 0; i < n; i++){
		scanf("%d", &a[i]);
	}

	// Sort array (Descending order)
	sort(&a[0], &a[n], myfunction);

	// printArray(a, n);

	ans = a[0];
	for(i = 0; i < n; i++) {
		if (a[i] * (i+1) > ans)
			ans = a[i] * (i+1);
	}

	printf("%lld\n", ans);

	return 0;
}