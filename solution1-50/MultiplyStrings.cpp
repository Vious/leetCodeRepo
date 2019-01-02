#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <bitset>
#include <array>
#include <assert.h>

using namespace std;

/* static int fast = []() {  
    ios_base::sync_with_stdio(0); 
    cin.tie(0); 
    cout.tie(0); 
    return 0; 
}(); */


class Solution {
public:

	string multiply(string num1, string num2) {
        string result(num1.size() + num2.size() + 1, '0');
		cout << result << endl;
		auto pos = result.size() - 1;
		auto mulPos = pos;
		for (int i = num1.size() - 1; i >=0; i--) {
			for(int j = num2.size() - 1 ; j >= 0; j--) {
				int tmp = ((num1[i] - '0') * (num2[j] - '0') + (result[pos] - '0'));
				result[pos] = (tmp % 10) + '0';
				result[pos - 1] = ( (tmp / 10) + (result[pos - 1] - '0')) + '0';
				pos--;
			}
			mulPos--;
			pos = mulPos;
		}
		while (result[0] == '0') {
			result.erase(result.begin());
		}
		return result.size() > 0 ? result : "0";
    }
	
};


int main()
{
	Solution sl;
    int num1, num2;
	cout << "Input num1 and num2: ";
	cin >> num1 >> num2;
	string res = sl.multiply(to_string(num1), to_string(num2));
	for (char &ch : res) {
		cout << ch - '0';
	}
	cout << "Answer is :" << res << endl;
	return 0;	
}