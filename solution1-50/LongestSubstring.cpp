#include <iostream>
#include <algorithm>
#include <string>


using namespace std;



/* Given a string, find the length of the 
longest substring without repeating characters. */
class Solution {
public:
	int lengthOfLongestSubstring(string s) {
		int map[256];
		for (int i = 0; i < 255; i++) {
			map[i] = -1;
		}
		int result = 0;
		int lenghth = s.size();
		int left = 0, right = 0;
		while (right < lenghth) {
			if (map[s[right]] == -1 || map[s[right]] < left) {
				map[s[right]] = right;
				int temp = right - left + 1;
				result = max(temp, result);
				right++;
			}
			else {
				left = map[s[right]] + 1;
				map[s[right]] = right;
				right++;
			}
		}
		return result;
	}
};


//int main() 
//{
//	string s1 = "abcdefghababcdefghijkm";
//	string s2 = "abcabcbb";
//	string s3 = "bbbbb";
//	string s4 = "pwwkew";
//	string s5 = "aab";
//	string s6 = "tmmzuxt";
//	int map[256] = {0};
//
//	Solution sl;
//
//	int count = sl.lengthOfLongestSubstring(s1);
//	cout << "Anwser: " << count << endl;
//	system("pause");
//
//	return 0;
//}