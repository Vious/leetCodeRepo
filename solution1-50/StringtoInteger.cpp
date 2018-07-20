#include <iostream>
#include <algorithm>
#include <string>
#include <cctype>

using namespace std;

class Solution {
public:
	int myAtoi(string str) {
		unsigned int len = str.size();
		if (len == 0) return 0;
		unsigned int start = 0;
		while (start < len && str[start] == ' ') {
			start++;
		}
		if (start == len) {
			return 0;
		}
		if ((!isdigit(str[start]) && str[start] != '-' && str[start] != '+')) {
			return 0;
		}
		int sigh;
	    long long result = 0;
		if (str[start] == '-') {
			sigh = -1;
			start++;
		} else if (str[start] == '+'){
			sigh = 1;
			start++;
		}
		else if (isdigit(str[start])) {
			sigh = 1;
		}
		if (isdigit(str[start])) {
			result = str[start] - 48;
			start++;
			while (isdigit(str[start]) && start < len) {
				result = result * 10 + str[start] - 48;
				if (result >= INT_MAX && sigh == 1) {
					return INT_MAX;
				}
				else if (result > INT_MAX && sigh == -1) {
					return INT_MIN;
				}
				start++;
			}
		}
		return sigh > 0 ? result : sigh * result;
	}
}; 


int main() 
{
	string s1 = "abcdefghababcdefghijkm";
	string s2 = "asabccbaa";
	string s3 = "bbbbb";
	string s4 = "pwwkew";
	string s5 = "cbbd";
	string s6 = "tmmzuxt";
	string s7 = "PAYPALISHIRING";
	string s8 = "   ";
	Solution sl;
	int a = 10;
	a >>= 1;
	a >>= 1;
	int b = a & 1;
	cout << '9' - 48 << endl;
	cout << "Anwser: " << sl.myAtoi("+") << endl;
	//cout << "Anwser: " << sl.myAtoi("1232") << endl;
	system("pause");

	return 0;
}