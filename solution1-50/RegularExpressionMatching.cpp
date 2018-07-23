#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:

	//recursion
	/*bool isMatch(string s, string p) {
		if (p.empty()) {
			return s.empty();
		}
		int len = p.size();
		bool match = ((p[0] == s[0] || p[0] == '.') 
			&& !s.empty());
		if (len >= 2 && p[1] == '*') {
			return (isMatch(s, p.substr(2)) ||
				(match && isMatch(s.substr(1), p)));
		}
		else {
			return match && (isMatch(s.substr(1), p.substr(1)));
		}

		return false;
	}*/

	// Dynamic programming
	bool isMatch(string s, string p) {
		if (p.empty()) {
			return s.empty();
		}
		int lenS = s.size(), lenP = p.size();
		bool **match;
		match = new bool*[lenS + 1]();
		for (int i = 0; i < lenS + 1; i++) {
			match[i] = new bool[lenP + 1]();
		}
		match[lenS][lenP] = true;
		for (int i = lenS; i >= 0; i--) {
			for (int j = lenP - 1; j >= 0; j--) {
				bool ifMatch = (i < lenS
					&& (p[j] == s[i] || p[j] == '.'));
				if (j < lenP - 1 && p[j + 1] == '*') {
					match[i][j] = match[i][j+2] || 
						(ifMatch && match[i+1][j]);
				}
				else {
					match[i][j] = ifMatch && match[i + 1][j + 1];
				}
			}
		}
		bool result = match[0][0];
		for (int i = 0; i < lenS + 1; i++) {
			delete[] match[i];
		}
		delete[] match;
		return result;
	}
};

int main()
{
	int input = 123321;
	Solution sl;
	string a = "123456789";
	cout << "Anwser is: " << sl.isMatch("aab", "c*a*b") << '\n';

	system("pause");
	return 0;
}