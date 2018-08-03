#include <iostream>
#include <string>

using namespace std;


class Solution {
public:
    int strStr(string haystack, string needle) {
        auto len1 = haystack.size(), len2 = needle.size();
        if (len2 == 0) return 0;
        if (len1 < len2) return -1;
        if (len1 == len2) {
            if (haystack == needle) return 0;
            else return -1;
        }
        decltype(len1) left = 0;
        while (left <= len1 - len2) {
            string tmp = haystack.substr(left, len2);
            if (tmp == needle) return left;
            left++;
        }
        return -1;
    } 
};



int main()
{
    /* "mississippi"
    "pi" */
    Solution sl;
    string str, needle;
    cout << "Please input a haystack:";
    while (cin >> str) {
        cout << "Please input a needle:";
        cin >> needle;        
        cout << "Answer is :" << sl.strStr(str, needle) << '\n';
        cout << "Please input a haystack:";
    }


    return 0;
}