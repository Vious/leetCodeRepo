#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        /* next_permutation(nums.begin(), nums.end());
        return; */

        //my implementation
        auto len = nums.size();
        if (len < 2) return;
        decltype(len) traves = -1;
        for (decltype(len) i = len - 1; i >= 1; i--) {
            if (nums[i] > nums[i - 1]) {
                traves = i;
                break;
            }
        }
        if (traves == - 1) {
            sort(nums.begin(), nums.end());
            return;
        } else {
            decltype(len) index;
            for (decltype(len) i = traves; i >= 0; i--) {
                if (nums[i] < nums[traves]) {
                    index = i;
                    break;
                }
            }
            int tmp = nums[index];
            nums[index] = nums[traves];
            nums[traves] = tmp;
            return ;
        }
        return;
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
