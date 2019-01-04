#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <bitset>
#include <array>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

/* static int fast = []() {  
    ios_base::sync_with_stdio(0); 
    cin.tie(0); 
    cout.tie(0); 
    return 0; 
}(); */


class Solution {
public:

	// greedy
	int jump(vector<int>& nums) {
		auto len = nums.size();
		if (len <= 1) return 0;
		if (len == 2) return 1;
		int current = 0, jumpTimes = 0, jumpStride = 0;
		for (int i = 0; i < len; i++) {
			jumpStride = max(jumpStride, i + nums[i]);
			if (jumpStride >= len - 1) return jumpTimes + 1;
			if (current <= i) {
				current = jumpStride;
				jumpTimes++;
			}
		}

		return jumpTimes;
    }
	
};


int main()
{
	Solution sl;
	vector <int> nums;
	int n;
	cout << "Input n: " ;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int tmp;
		cin >> tmp;
		nums.push_back(tmp);
	}
	int res = sl.jump(nums);
	cout << "Answer is :" << res <<endl;
	return 0;	
}