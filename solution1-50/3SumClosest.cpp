#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
	int threeSumClosest(vector<int>& nums, int target) {
		int len = nums.size();
		if (len <= 2) return -1;
		sort(nums.begin(), nums.end());
		int result = nums[0]+nums[1]+nums[2];
		int left = 0, right = len - 1;
		for (int i = 0; i < len - 2; i++) {
			left = i + 1;
			right = len - 1;
			int wanted = target - nums[i];
			while (left < right) {
				int tmp = nums[left] + nums[right];
				if (tmp > wanted) {
					if (abs(tmp - wanted) < abs(result - target))
						result = tmp + nums[i];
					right--;
				}
				else if (tmp < wanted) {
					if (abs(tmp - wanted) < abs(result- target))
						result = tmp + nums[i];
					left++;
				} else{
					return nums[i]+nums[left]+nums[right];
				}
			}
		}


		return result;
	}
};




//int main()
//{
//	Solution sl;
//	vector <int> nums;
//	int target = -1;
//	nums.push_back(-3);
//	nums.push_back(-2);
//	nums.push_back(-5);
//	nums.push_back(3);
//	nums.push_back(-4);
//
//	cout << "Answer is: " << sl.threeSumClosest(nums, target) <<'\n';
//
//	system("pause");
//
//	return 0;
//}