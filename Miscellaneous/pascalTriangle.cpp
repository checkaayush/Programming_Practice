// Pascal's Triangles

#include <cstdio>

int pascal(int row, int col) {
	
	// Base conditions:
	// Invalid index
	if (row < col)
		return -1;

	// Boundary 1s
	if (col == 0 || row == col)
		return 1;

	return pascal(row - 1, col - 1) + pascal(row - 1, col);
}

int main() {

	int ans;

	ans = pascal(0, 0); // 1
	printf("Value at row %d and col %d is %d.\n", 0, 0, ans);
	ans = pascal(0, 1); // Should say invalid argument
	printf("Value at row %d and col %d is %d.\n", 0, 1, ans);
	ans = pascal(2, 1); // 2
	printf("Value at row %d and col %d is %d.\n", 2, 1, ans);
	ans = pascal(3, 2); // 3
	printf("Value at row %d and col %d is %d.\n", 3, 2, ans);

	return 0;
}