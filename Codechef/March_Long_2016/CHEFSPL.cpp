#include <iostream>
#include <string>
 
using namespace std;
 
bool isSpecial(string str) {
	long long length = str.length(), newLength, index = length / 2;
	string leftSubstring, rightSubstring, newStr;
 
	int alpha[26] = {0};
 
	if (length % 2 == 0) {
		
		leftSubstring = str.substr(0, index);
		rightSubstring = str.substr(index);
		return (leftSubstring.compare(rightSubstring) == 0);	
 
	} else {
		
		for (int i = 0; i < length; i++) {
			alpha[str.at(i) - 97]++;
		}
 
		int oddCount = 0;
		char oddChar;
 
		for (int i = 0; i < 26; i++) {
			if (alpha[i] % 2 != 0) {
				oddCount++;
				oddChar = i + 97;
			}
			if (oddCount > 1)
				return false;
		}
 
		for (int i = 0; i < length; i++) {
			
			if (str.at(i) != oddChar)
				continue;
 
			newStr = str;
 
			newStr.erase(i, 1);
			newLength = newStr.length();
			index = newLength / 2;
 
			leftSubstring = newStr.substr(0, index);
			rightSubstring = newStr.substr(index);	
 
			if (leftSubstring.compare(rightSubstring) == 0) {
				return true;
			}
		}
		
	}
	
	return false;
	
}
 
int main() {
 
	long long D;
	cin >> D;
 
	string str;
	while(D--) {
		cin >> str;
 
		if (isSpecial(str)) {
			cout << "YES" << endl;
		} else {
			cout << "NO" << endl;
		}
	}
 
	return 0;	
} 
