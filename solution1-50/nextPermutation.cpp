#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    void nextPermutation(vector<int> &nums) {
        /* next_permutation(nums.begin(), nums.end());
        return; */

        //my implementation
        auto len = nums.size();
		if (len <= 1) {
			return;
		}

		int index = nums.size() - 2;
		while (index >=0 && nums[index] >= nums[index + 1]) {
			index--;
		}
		if (index >= 0) {
			int count = index + 1;
			while (count < len && nums[count] > nums[index]) {
				++count;
			}
			swap(nums[count - 1], nums[index]);
		}
		reverse(nums.begin() + index + 1, nums.end());
    }
};


int main(int argc, char const *argv[])
{
    Solution sl;
    vector <int> nums = {1,3,2};
    sl.nextPermutation(nums);

    for (int a : nums) {
        cout << a << " ";
    }
    cout << endl;
    


    return 0;
}
