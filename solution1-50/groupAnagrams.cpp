#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <bitset>
#include <array>
#include <cstdio>
#include <string>
#include <algorithm>
#include <unordered_map>

using namespace std;

/* static int fast = []() {  
    ios_base::sync_with_stdio(0); 
    cin.tie(0); 
    cout.tie(0); 
    return 0; 
}(); */


class Solution {
public:

	vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector <vector <string>> results;
		auto len = strs.size();
		if (len < 1) return results;
		else if (len == 1) {
			results.push_back(strs);
			return results;
		}
		unordered_map <string, vector<string>> map;
		for (string &s : strs) {
			string tmp(s);
			sort(tmp.begin(), tmp.end());
			map[tmp].push_back(s);
		}
		int k = 0;
		for (auto iter = map.begin(); iter != map.end(); iter++, k++) {
			results.push_back(iter->second);
			sort(results[k].begin(), results[k].end());
		}
		return results;
    }

};


int main()
{
	Solution sl;
	vector <string> strs;
	int n;
	cout << "Input num of strings: ";
	cin >> n;
	for (int i = 0; i < n + 1; i++) {
		string tmp;
		getline(cin, tmp);
		strs.push_back(tmp);
	}
	vector <vector <string>> res = sl.groupAnagrams(strs);
	for (vector <string> ss: res) {
		for (string s : ss) {
			cout << s << " ";
		}
		cout << "\n";
	}
	
	return 0;
}