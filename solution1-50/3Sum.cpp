#include <iostream>
#include <algorithm>
#include <vector>


using namespace std;



class Solution {
public:
	vector<vector<int>> threeSum(vector<int>& nums) {
		int len = nums.size();
		if (len <= 2) return {};
		vector<vector<int>> result;
		sort(nums.begin(), nums.end());
		int left = 0, right = len - 1;
		for (int i = left; i < len - 2; i++) {
			left = i + 1;
			right = len - 1;
			int wanted = -nums[i];
			while (left < right) {
				if (i != 0 && nums[i] == nums[i - 1]) break;
				int tmp = nums[left] + nums[right];
				if (tmp == wanted) {
					result.push_back({ nums[i], nums[left], nums[right] });
					//make unique
					left++;
					while (nums[left] == nums[left - 1] && left < right) {
						left++;
					}
					right--;
					while (nums[right] == nums[right + 1] && right > left) {
						right--;
					}
				}
				else if (tmp > wanted) {
					right--;
				}
				else {
					left++;
				}

			}

		}

		return result;
	}
};


int main()
{
	Solution sl;
	vector <int> nums;
	/*{0,0,0}, {1, 1, -2}, {-2,0,0,2,2}
	[-1, 0, 1, 2, -1, -4]*/

	nums.push_back(-1);
	nums.push_back(0);
	nums.push_back(1);
	nums.push_back(2);
	nums.push_back(-1);
	nums.push_back(-4);

	vector <vector <int>> ret = sl.threeSum(nums);
	cout << "Answers are: ";
	for (vector<int> vec : ret){
		int len = vec.size();
		for (int i = 0; i < len; i++) {
			cout << vec[i];
		}
		cout << '\n';
	}

	system("pause");

	return 0;
}

