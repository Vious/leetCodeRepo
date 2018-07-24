#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:

	// easy thoughts
	/*int maxArea(vector<int>& height) {
		int len = height.size();
		if (len == 0) return 0;
		int result = 0;
		for (int i = 0; i < len - 1; i++) {
			for (int j = i + 1; j < len; j++) {
				int tmp = min(height[i], height[j]) * (j - i);
				result = max(result, tmp);
			}
		}

		return result;
	}*/

	// 
	int maxArea(vector<int>& height) {
		int len = height.size();
		if (len == 0) return 0;
		int result = 0;
		int left = 0, right = len - 1;
		while (left < right) {
			int tmp = min(height[left], height[right]) 
				* (right - left);
			result = max(result, tmp);
			if (height[right] >= height[left]) {
				left++;
			}
			else {
				right--;
			}

		}

		return result;
	}
};

//int main()
//{
//	Solution sl;
//	vector<int> water;
//	water.push_back(1);
//	water.push_back(8);
//	water.push_back(6);
//	water.push_back(2);
//	water.push_back(5);
//	water.push_back(4);
//	water.push_back(8);
//	water.push_back(3);
//	water.push_back(7);
//
//
//	cout << "Anwser is: " << sl.maxArea(water) << '\n';
//
//	system("pause");
//	return 0;
//}