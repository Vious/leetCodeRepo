#include <iostream>
#include <vector>
#include <string>

using namespace std;


class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector <string> results;
        if (n < 1) return results;
        solver(n, n, "", results);
        return results;
    }

    void solver(int left, int right, string str, vector <string> & results) {
        if (left == 0) {
            for (int i = 0; i < right; i++) {
                str.push_back(')');
            }
            results.push_back(str);
            return;
        } 
        str.push_back('(');
        solver(left - 1, right, str, results);
        str.pop_back();
        if (right > left) {
            str.push_back(')');
            solver(left, right - 1, str, results);
        }

    }
};



int main(int argc, char const *argv[])
{
    int n;
    Solution sl;
    vector <string> res;
    while (cin >> n) {
        res = sl.generateParenthesis(n);
        for (string str : res) {
            cout << str << '\n';
        }
    }
    return 0;
}




