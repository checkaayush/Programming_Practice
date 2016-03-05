#include <cstdio>
#include <cstdlib>
#include <algorithm>

using namespace std;

typedef struct Unit {
	long long a; // Element of First Array A
	long long b; // Element of Second Array B
	long long product; // Product (a * b)
} Unit;

// void printUnitArray(Unit* units, long long n) {
// 	for(long long i = 0; i < n; i++) {
// 		printf("%d %d %lld\n", units[i].a, units[i].b, units[i].product);
// 	}
// }

// Compare function to sort descendingly
bool cmpFunc(Unit u1, Unit u2) {
	return u1.product > u2.product;
}

long long getNewSum(Unit u, long long sum, long long k) {
	
	long long oldProduct = u.product, newProduct = oldProduct, newSum, temp = k;

	if (oldProduct > 0) {
		
		if (u.a < 0)
			k = -k;

	} else if (oldProduct < 0) {
		
		if (u.a > 0)
			k = -k;

	} else {
		if (u.a == 0) {
			
			if (u.b < 0)
				k = -k;

		}
	}

	newProduct = (u.a + k) * u.b;
	newSum = sum - oldProduct + newProduct;
	if (newSum > sum)
		return newSum;
	else
		return sum;
}

long long solve(Unit* units, long long n, long long sum, long long k) {
	
	// Note: Allowed operations only on 'a'
	long long newSum = 0, maxSum = sum;

	for (long long i = 0; i < n; i++) {
		newSum = getNewSum(units[i], sum, k);
		if (newSum > maxSum)
			maxSum = newSum;
	}

	return maxSum;
}

int main() {

	int t, temp;
	long long n, k, sum;
	scanf("%d", &t);

	while(t--) {
		
		scanf("%lld%lld", &n, &k);
	
		Unit* units = (Unit*) malloc(sizeof(Unit) * n);

		for (long long i = 0; i < n; i++) {

			// Input values of first array
			scanf("%lld", &units[i].a);	
		}

		sum = 0;
		for (long long i = 0; i < n; i++) {
			
			// Input values of second array
			scanf("%lld", &units[i].b);
			
			// Calculate product
			units[i].product = units[i].a * units[i].b;

			// Update sum
			sum += units[i].product;
		}

		// Sort array of structures in descending order 
		sort(&units[0], &units[n], cmpFunc);

		// printUnitArray(units, n);

		long long ans = solve(units, n, sum, k);

		printf("%lld\n", ans);
	}

	return 0;
}