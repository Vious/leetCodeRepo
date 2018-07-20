#include <iostream>
#include <algorithm>


using namespace std;

//#define MAX_INT_NUM 2147483647
//#define MIN_INT_NUM -2147483648


class Solution {
public:
	int reverse(int x) {
		if (x < 10 && x > -10) {
			return x;
		}
		int result = 0;
		while (x) {
			int digit = x % 10;
			if (result > INT_MAX / 10 || (result == INT_MAX && digit > 7)) {
				return 0;
			}
			else if (result < INT_MIN / 10 || (result == INT_MIN && digit < -8)) {
				return 0;
			}
			result = result * 10 + digit;
			x /= 10;
		}
		return result;
	}
};

//int main()
//{
//
//	Solution sl;
//
//
//	cout << "Anwser: " << sl.reverse(-123) << endl;
//	system("pause");
//
//	return 0;
//}