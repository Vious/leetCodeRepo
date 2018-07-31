#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;


class Solution {
public:
    //recursion
    /* vector<string> letterCombinations(string digits) {
        vector <string> results;
        if (digits.empty()) return results;

        string mapper[] = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        recursionDFS(digits, 0, mapper, results, "");

        return results;

    } */

    //
    vector<string> letterCombinations(string digits) {
        vector <string> results;
        if (digits.empty()) return results;
        string mapper[] = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        results.push_back("");
        vector <string> swapStr;
        for (decltype(digits.size()) i = 0; i < digits.size(); i++) {
            swapStr.clear();
            int index = digits[i] - '2';
            string getMap = mapper[index];
            for (decltype(i) j = 0; j < results.size(); j++) {
                for (decltype(i) k = 0; k < getMap.size(); k++) {
                    swapStr.push_back(results[j] + getMap[k]);
                }
            }
            results.swap(swapStr);
        }
        return results;
    }

private:
    void recursionDFS(string digits, string::size_type count, string mapper[], vector <string> &results, string tmp) {
        if (count == digits.size()) { 
            results.push_back(tmp);
        }
        else {
            cout << count << endl;
            unsigned int index = digits[count] - '2';
            string part = mapper[index];
            for (decltype(index) i = 0; i < part.size(); i++) {
                tmp.push_back(part[i]);
                recursionDFS(digits, count + 1, mapper, results, tmp);
                tmp.pop_back();
            }
        }
    }
};




int main()
{
    Solution sl;
    string s;
    cout << "Please input a digits(2-9): " << endl;
    while(cin >> s){
        vector <string> res = sl.letterCombinations(s);
        for (string str : res) {
            cout << str << " ";
        }
        cout << '\n';
        cout << "Please input a digits(2-9): " << endl;
    }



    return 0;
}