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
	int firstMissingPositive(vector<int>& nums) {
        auto len = nums.size();
		int goes = 0;
		while(goes < len) {
			int i = goes;
			if (nums[i] != (i + 1) && nums[i] >= 1 && nums[i] <= len && nums[nums[i] - 1] != nums[i]) {
				swap(nums[i], nums[nums[i] - 1]);
			} else {
				goes ++;
			}
		}
		for (int i = 0; i < len; i++) {
			if (nums[i] != i + 1) {
				return i + 1;
			}
		}
		return len + 1;
    }
};


int main()
{
	Solution sl;
    vector <int> nums;
	cout << "Input nums: ";
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int tmp;
		cin >> tmp;
		nums.push_back(tmp);
	}
	int res = sl.firstMissingPositive(nums);
	cout << "Answer is :" << res << endl;
	return 0;	
}