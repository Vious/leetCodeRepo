#include <iostream>
#include <algorithm>
#include <string>


using namespace std;

class Solution {
public:
	//with the use of string
	bool isPalindrome(int x) {
		if (x < 0) {
			return false;
		}
		else if (x == 0) {
			return true;
		}
		else {
			string input = to_string(x);
			int len = input.size();
			if (len == 1) {
				return true;
			}
			else {
				int left = 0, right = len - 1;
				while (left <= right) {
					if (input[left] != input[right]) {
						return false;
					}
					left++;
					right--;
 				}
			}
		}

		return true;
	}
	
	//without using string, but slower than using string
	/*bool isPalindrome(int x) {
		if (x < 0) {
			return false;
		}
		else if (x <= 9) {
			return true;
		}
		else {
			int newX = 0, tmp = x;
			while (tmp > 0) {
				newX = newX * 10 + tmp % 10;
				tmp /= 10;
			}
			if (newX == x) return true;
		}
		return false;
	}*/

};


//int main()
//{
//	int input = 123321;
//	Solution sl;
//
//
//	cout << "Anwser is: " << sl.isPalindrome(input) << '\n';
//
//	system("pause");
//	return 0;
//}