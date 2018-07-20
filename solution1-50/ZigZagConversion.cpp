#include <iostream>
#include <algorithm>
#include <string>


using namespace std;

class Solution {
public:
	string convert(string s, int numRows) {
		int len = s.size();
		if (len <= 1 || numRows == 1) {
			return s;
		}
		string results;
		int countRows = 2 * numRows - 2;
		for (int i = 0; i < numRows; i++) {
			for (int j = 0; j + i < len; j += countRows) {
				results += s[i + j];
				if (i != 0 &&  i != numRows - 1 && j - i + countRows < len) {
					results += s[j - i + countRows];
				}
			}
		}


		return results;
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
//	string s7 = "PAYPALISHIRING";
//	int map[256] = {0};
//
//	Solution sl;
//	if (sl.convert(s7, 3) == "PAHNAPLSIIGYIR") {
//		cout << "Anwser: " << "PAHNAPLSIIGYIR == " << sl.convert(s7, 3) << endl;
//	}
//	if (sl.convert(s7, 4) == "PINALSIGYAHRPI") {
//		cout << "Anwser: " << "PINALSIGYAHRPI == "<< sl.convert(s7, 4) << endl;
//	}
//
//
//	cout << "Anwser: " << sl.convert(s5, 4) << endl;
//	system("pause");
//
//	return 0;
//}