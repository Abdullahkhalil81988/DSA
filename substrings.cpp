#include <iostream>
#include <string>
using namespace std;

int findFirstOccurrence(string text, string pattern) {
	if (pattern.empty()) {
		return 0; // Empty pattern found at index 0
	}
	
	for (int i = 0; i <= text.length() - pattern.length(); i++) {
		bool found = true;
		for (int j = 0; j < pattern.length(); j++) {
			if (text[i + j] != pattern[j]) {
				found = false;
				break;
			}
		}
		if (found) {
			return i;
		}
	}
	return -1; // Pattern not found
}

int main() {
   // test 1
	string text1 = "hello world";
	string pattern1 = "hello";
	cout << "Pattern at beginning: " << findFirstOccurrence(text1, pattern1) << endl;
	
   // Test 2
	string text2 = "hello world";
	string pattern2 = "world";
	cout << "Pattern at end: " << findFirstOccurrence(text2, pattern2) << endl;
	
   // Test3
	string text3 = "hello world";
	string pattern3 = "xyz";
	cout << "Pattern not present: " << findFirstOccurrence(text3, pattern3) << endl;
	
	// test4
	string text4 = "hello world";
	string pattern4 = "";
	cout << "Empty pattern: " << findFirstOccurrence(text4, pattern4) << endl;
	
	return 0;
}
