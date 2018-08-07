#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

/* static int x = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();
 */

class Solution {
public:
    string countAndSay(int n) {
        if (n < 1) return "";
        string str = "1";
        if (n == 1) return str;
        n--;
        while(n) {
            string tmp;
            for (int i = 0; i < str.size(); i++) {
                int count = 1;
                while (i < str.size() - 1 && str[i] == str[i+1]) {
                    count++;
                    i++;
                }
                tmp += to_string(count) + str[i];
            }
            str = tmp;
            n--;
        }
        return str;
    }
};




int main(int argc, char const *argv[])
{
    Solution sl;
    int n;
    cout << "Please input number n:";
    while(cin >> n) {
        cout << "Answer is " << sl.countAndSay(n) << endl;
        cout << "Please input number n:";
    }
    return 0;
}
