#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    // dynamic programming
    // static int x = [](){ios::sync_with_stdio(false); cin.tie(nullptr); return 0; }();

    int longestValidParentheses(string s) {
        if (s.empty()) return 0;
        int count = 0;
        string::size_type len = s.size();
        vector <int> dnPr(s.size() + 1, 0);
        for (int i = 1; i < len; i++) {
            if (s[i] == ')') {
                if (s[i - 1 - dnPr[i - 1]] == '(') {
                    dnPr[i] = dnPr[i - 1] + 2;
                }
                dnPr[i] += dnPr[i - dnPr[i]];
            }
            count = max(count, dnPr[i]);
        }
        return count;
    }
};





int main()
{
    string s;
    Solution sl;
    cout << "Please input a parenthese: " << endl;
    while(cin >> s){
        cout << "Answer is :" << sl.longestValidParentheses(s) << endl;
        cout << "Please input a parenthese: " << endl;
    }



    return 0;
}