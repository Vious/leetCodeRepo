#include <iostream>
#include <string>
#include <stack>
#include <map>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        if (s.empty()) return true;
        string::size_type len = s.size();
        if (len % 2 != 0) return false;
        stack <int> parentheses;
        map <char, char> parenthesesMap;
        parenthesesMap.insert({']', '['});
        parenthesesMap.insert({'}', '{'});
        parenthesesMap.insert({')', '('});
        parentheses.push(s[0]);
        for (string::size_type i = 1; i < len; i++) {
            if ( !parentheses.empty() && parenthesesMap[s[i]] == parentheses.top()) {
                parentheses.pop();
            } else {
                parentheses.push(s[i]);
            }
        }        
        return parentheses.empty();
    }
};





int main()
{
    string s = "{[]}[]";
    Solution sl;
    bool real = sl.isValid(s);
    cout << "Please input a parenthese: " << endl;
    while(cin >> s){
        cout << "Answer is :" << sl.isValid(s) << endl;
        cout << "Please input a parenthese: " << endl;
    }



    return 0;
}