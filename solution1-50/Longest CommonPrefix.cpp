#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
	string longestCommonPrefix(vector<string>& strs) {
		if (strs.empty()) return "";
		string standard = strs[0];
		int len = strs.size();
		int leastLen = strs[0].size();
		for (int i = 1; i < len; i++) {
			for (int j = 0; j < leastLen; j++) {
				if (strs[i].size() < leastLen) {
					leastLen = strs[i].size(); 
				}
				if (j == 0 && strs[i][j] != standard[j]) {
					return "";
				}
				else if (j != 0 && strs[i][j] != standard[j]) {
					leastLen = j;
					break;
				}
			}
		}
		string results = standard.substr(0, leastLen);
		return results;
	}
};



//int main()
//{
//	Solution sl;
//	vector <string> strs;
//	while (1) {
//		string input;
//		cout << "please input a string: ";
//		cin >> input;
//		if (input == "0") break;
//		strs.push_back(input);
//	}
//	cout << "Anwser is: " << sl.longestCommonPrefix(strs) << '\n';
//	system("pause");
//	return 0;
//}