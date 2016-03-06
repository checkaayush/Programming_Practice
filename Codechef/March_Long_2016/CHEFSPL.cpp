#include <cstdio>
#include <cstring>

using namespace std;

char oddChar;

bool isSpecialityPossible(char* str) {
	
	long long alpha[26] = {0};
	long long oddCount = 0;
	long long length = strlen(str);

	for (long long i = 0; i < length; ++i) {
		alpha[str[i]-97]++;
	}

	for (int i = 0; i < 26; ++i) {
		
		if (alpha[i] == length) {
			return true;
		}

		if (alpha[i] & 1) {
			oddCount++;
			oddChar = (char)(i + 97);
		}
		
		if (oddCount > 1) {
			return false;
		}
	}

	return true;
}

bool isDouble(char* str) {

	long long length = strlen(str);
	long long index = length / 2;

	for (long long i = 0, j = index; i < index && j < length; ++i, ++j) {
		if (str[i] != str[j]) {
			return false;
		}
	}

	return true;
}

bool isSpecial(char* str) {

	if (!isSpecialityPossible(str))
		return false;
	
	long long length = strlen(str);
	long long index = length / 2;

	if (length & 1) {

		char newStr[1000001];
		for (long long i = 0, k = 0; i < length; ++i) {
			if (str[i] != oddChar) {
				newStr[k] = str[i];
				k++;
			}
			if (i == length - 1) {
				newStr[k] = '\0';	
			}
		}

		return isDouble(newStr);

	} else {
		return isDouble(str);	
	}
	
}

int main() {
 
 	long long D;
	scanf("%lld", &D);
 
	char str[1000001];

	while(D--) {

		scanf("%s", str);
 
		if (isSpecial(str)) {
			printf("YES\n");
		} else {
			printf("NO\n");
		}
	}
 
	return 0;	
} 
