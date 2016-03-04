#include <cstdio>
#include <cstdlib>
#include <algorithm>

using namespace std;

typedef struct Unit {
	int a; // Element of First Array A
	int b; // Element of Second Array B
	long long product; // Product (a * b)
} Unit;

void printUnitArray(Unit* units, int n) {
	for(int i = 0; i < n; i++) {
		printf("%d %d %lld\n", units[i].a, units[i].b, units[i].product);
	}
}

bool cmpFunc(Unit u1, Unit u2) {
	return u1.product < u2.product;
}

long long getNewSum(Unit u, long long sum, long long k) {
	
	long long oldProduct = u.product, newProduct = oldProduct, newSum;

	if (oldProduct > 0) {
		if (u.a > 0) {
			newProduct = (u.a + k) * u.b;
		} else {
			newProduct = (u.a - k) * u.b;
		}
	} else if (oldProduct < 0) {
		if (u.a > 0) {
			newProduct = (u.a - k) * u.b;
		} else {
			newProduct = (u.a + k) * u.b;
		}
	} else {
		if (u.a == 0) {
			if (u.b > 0){
				newProduct = (u.a + k) * u.b;
			} else {
				newProduct = (u.a - k) * u.b;
			}
		}
	}

	newSum = sum - oldProduct + newProduct;
	return newSum;
}

long long solve(Unit* units, long long n, long long sum, long long k) {
	
	// Note: Allowed operations only on 'a'
	long long leftSum, rightSum;

	// Left interaction
	leftSum = getNewSum(units[0], sum, k);

	// Right interaction
	rightSum = getNewSum(units[n-1], sum, k);

	return (leftSum > rightSum) ? (leftSum) : (rightSum);

}

int main() {

	int t, temp;
	long long n, k, sum;
	scanf("%d", &t);

	while(t--) {
		
		scanf("%lld%lld", &n, &k);
	
		Unit* units = (Unit*) malloc(sizeof(Unit) * n);

		for (int i = 0; i < n; i++) {

			// Input values of first array
			scanf("%d", &units[i].a);	
		}

		sum = 0;
		for (int i = 0; i < n; i++) {
			
			// Input values of second array
			scanf("%d", &units[i].b);
			
			// Calculate product
			units[i].product = units[i].a * units[i].b;

			// Update sum
			sum += units[i].product;
		}

		// Sort array of structures in ascending order 
		sort(&units[0], &units[n], cmpFunc);

		// printUnitArray(units, n);

		long long ans = solve(units, n, sum, k);

		printf("%lld\n", ans);
	}

	return 0;
}