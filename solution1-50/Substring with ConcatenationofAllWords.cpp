#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>


using namespace std;

class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        auto len1 = s.size(), len2 = words.size();
        if (len1 == 0 || len2 == 0) return {};
        if ((words[0].size() * len2) > len1) return {};
        map <string, int> strMap;
        strMap[words[0]]++;
        for (decltype(len1) i = 1; i < len2; i++) {
            strMap[words[i]]++;
            if (words[i].size() != words[i - 1].size()) {
                return {};
            }
        }
        vector <int> res;
        auto eachLength = words[0].size();
        auto totalLenth = eachLength * len2;
        unsigned int left = 0;
        decltype(len1) count = 0;
        vector <string> calc;
        while (left <= len1 - totalLenth) {
            for (count = 0; count < len2; count++) {
                string tmp = s.substr(left + count * eachLength, eachLength);
                if (strMap.find(tmp) == strMap.end()) break;
                else {
                    if (strMap[tmp] != 0) {
                        strMap[tmp]--;
                        calc.push_back(tmp);
                    } else break;
                }
            }
            if (count == len2) res.push_back(left);
            for (string str : calc) {
                strMap[str]++;
            }
            left++;
            //important
            calc.clear();
        }

        return res;
    }
};



int main(int argc, char const *argv[])
{
    Solution sl;
    string input;
    vector <string> words;
    vector <int> res;
    string str;
    /* "wordgoodgoodgoodbestword"
["word","good","best","word"] */
    str = "wordgoodgoodgoodbestword";
    words.push_back("word");
    words.push_back("good");
    words.push_back("best");
    words.push_back("word");
    res = sl.findSubstring(str, words);
    for (int re: res) {
        cout << re << ' ';
    }
    cout << endl;
    return 0;
}




