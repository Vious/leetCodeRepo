#include <iostream>
#include <algorithm>
#include <string>


using namespace std;


class Solution {
public:
	string longestPalindrome(string s) {
		string results;
		int len = s.size();
		int longestS;
		int start = 0, end = 0;
		if (len <= 1) {
			return results = s;
		}
		else {
			for (int i = 0; i < len; i++) {
				int guess1 = lenthOfIsPalindrome(s, i, i);
				int guess2 = lenthOfIsPalindrome(s, i, i + 1);
				if (guess1 > guess2) {
					longestS = guess1;
					if (longestS > end - start) {
						start = i - longestS / 2;
						end = i + longestS / 2;
					}
				}
				else {
					longestS = guess2;
					if (longestS > end - start) {
						start = i - (longestS - 1) / 2;
						end = i + longestS / 2;
					}
				}
			}
		}

		return results = s.substr(start, end - start + 1);
	}

private:
	int lenthOfIsPalindrome(string str, int left, int right) {
		int i = left, j = right;
		int len = str.size();
		while (i >= 0 && j < len && str[i] == str[j]) {
			i--;
			j++;
		}
		return j - i - 1;
	}
};



//int main() 
//{
//	string s1 = "abcdefghababcdefghijkm";
//	string s2 = "asabccbaa";
//	string s3 = "bbbbb";
//	string s4 = "pwwkew";
//	string s5 = "cbbd";
//	string s6 = "tmmzuxt";
//	int map[256] = {0};
//
//	Solution sl;
//
//	cout << "Anwser: " << sl.longestPalindrome(s5) << endl;
//	system("pause");
//
//	return 0;
//}