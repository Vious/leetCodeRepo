#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <bitset>
#include <array>
#include <cstdio>
#include <cstring>

using namespace std;

/* static int fast = []() {  
    ios_base::sync_with_stdio(0); 
    cin.tie(0); 
    cout.tie(0); 
    return 0; 
}(); */


class Solution {
public:

	bool isMatch(string s, string p) {
		auto lenStr = s.size(), lenPattern = p.size();
		if (lenStr == 0) return lenPattern == 0 || p == "*";
		bool dp[lenStr + 1][lenPattern + 1];
		memset(dp, false, sizeof(dp));
		dp[0][0] = true;

		for (int j = 1; j < lenPattern; j++) {
			if (p[j - 1] != '*') break;
			else dp[0][j] = true;
		}

		for (int i = 1; i <= lenStr; i++) {
			for (int j = 1; j <= lenPattern; j++) {
				bool ifCurrentMatch = s[i - 1] == p[j - 1] || p[j - 1] == '?';
				if (ifCurrentMatch) {
					dp[i][j] = dp[i - 1][j - 1];
				}
				else if (p[j - 1] == '*') {
					dp[i][j] = dp[i - 1][j] || dp[i][j - 1] || dp[i - 1][j - 1];
				} else {
					dp[i][j] = 0;
				}
			}
		}

		return dp[lenStr][lenPattern];
    }
	
};


int main()
{
	Solution sl;
	string str, pattern;
	getline(cin, str);
	getline(cin, pattern);
	cout << str << " " << pattern << endl;
	bool res = sl.isMatch(str, pattern);
	cout << "Answer is :" << res << endl;
	return 0;	
}