#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

void populateAlphabets(char A[], int alpha[]) {

	int length = strlen(A);

	for (int i = 0; i < length; i++) {
		alpha[A[i] - 97]++;
	}
}

int solve(int alpha1[], int alpha2[]) {
	for (int i = 0; i < 26; i++) {
		if (alpha1[i] > 0 && alpha2[i] > 0)
			return 1;
	}

	return 0;
}

int main() {
	
	char A[1001], B[1001];
	int t;

	scanf("%d", &t);

	while(t--) {

		int alpha1[27] = {0}, alpha2[27] = {0};
			
		scanf("%s", A);
		populateAlphabets(A, alpha1);

		scanf("%s", B);
		populateAlphabets(B, alpha2);

		int ans = solve(alpha1, alpha2);
		
		if (!ans) {
			printf("No\n");
		} else {
			printf("Yes\n");
		}
	}

	return 0;
}