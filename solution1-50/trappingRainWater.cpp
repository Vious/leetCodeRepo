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

	int trap(vector <int> &height) {
		auto len = height.size();
		if (len < 1) return 0;
		decltype(len) left = 0, right = len - 1;
		decltype(len) result = 0;
		decltype(len) leftMax = 0, rightMax = 0;
		while (left < right) {
			if (height[left] < height[right] ) {
				if (height[left] >= leftMax) leftMax = height[left];
				else result += leftMax - height[left];
				left++;
			} else {
				if (height[right] >= rightMax) rightMax = height[right];
				else result += rightMax - height[right];
				right--;
			}
		}

		return result;

	}
};


int main()
{
	Solution sl;
    vector <int> height;
	cout << "Input nums: ";
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int tmp;
		cin >> tmp;
		height.push_back(tmp);
	}
	int res = sl.trap(height);
	cout << "Answer is :" << res << endl;
	return 0;	
}