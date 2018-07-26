#include <iostream>
#include <algorithm>
#include <string>
#include <map>

using namespace std;

class Solution {
public:
	int romanToInt(string s) {
		if (s.empty()) return 0;
		int result = 0;
		map <char, int> romanIntMap;
		romanIntMap.insert({ 'I', 1 });
		romanIntMap.insert({ 'V', 5 });
		romanIntMap.insert({ 'X', 10 });
		romanIntMap.insert({ 'L', 50 });
		romanIntMap.insert({ 'C', 100 });
		romanIntMap.insert({ 'D', 500 });
		romanIntMap.insert({ 'M', 1000 });
		
		int len = s.size();
		if (len == 1) {
			return romanIntMap[s[0]];
		}
		for (int i = 0; i < len; i++) {
			if (i < len - 1 && romanIntMap[s[i]] >= romanIntMap[s[i + 1]]) {
				result += romanIntMap[s[i]];
			}
			else if (i < len - 1 && romanIntMap[s[i]] < romanIntMap[s[i + 1]]){
				result += romanIntMap[s[i + 1]] - romanIntMap[s[i]];
				i++;
			}
			else {
				result += romanIntMap[s[i]];
			}
		}

		return result;
	}
};



//int main()
//{
//	Solution sl;
//	while (1) {
//		string input;
//		cout << "please input a roman numeral: ";
//		cin >> input;
//		if (input == "0") break;
//		cout << "Anwser is: " << sl.romanToInt(input) << '\n';
//	}
//	system("pause");
//	return 0;
//}