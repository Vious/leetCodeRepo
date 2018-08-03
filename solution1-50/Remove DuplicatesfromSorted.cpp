#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:

    // remove 
    /* int removeDuplicates(vector<int>& nums) {
        auto len = nums.size();
        if (len < 2) return len;
        for (decltype(len) i = 1; i < nums.size(); i++) {
            if (nums[i] == nums[i - 1]) {
                nums.erase(nums.begin() + (i));
                i--;
            }
        }
        return nums.size();
    } */

    // count, but do not erase
    /* int removeDuplicates(vector<int>& nums) {
        auto len = nums.size();
        if (len < 2) return len;
        unsigned int count = 0;
        for (decltype(len) i = 1; i < nums.size(); i++) {
            if (nums[i] == nums[i - 1]) {
                count++;
            }
        }

        return len - count;

    } */

    // count and change value
    int removeDuplicates(vector<int>& nums) {
        auto len = nums.size();
        if (len < 2) return len;
        unsigned int count = 1;
        for (decltype(len) i = 1; i < len; i++) {
            if (nums[i] != nums[i - 1]) {
                nums[count] = nums[i];
                count++;
            } 
        }
        return count;
    }

    // found c++ unique function
    /* int removeDuplicates(vector<int>& nums) {
        return unique(nums.begin(), nums.end()) - nums.begin();
    } */
};


int main(int argc, char const *argv[])
{
    vector <int> nums = {0,0,1,1,1,2,2,3,3,4, 4, 4, 5};
    vector <int> nums1 = {1, 1, 1, 2, 2};
    Solution sl;
    auto len = sl.removeDuplicates(nums);
    cout << "len:" << len << endl;
    for (decltype(nums1.size()) i = 0; i < len; i++) {
        cout << nums[i] << " " ;
    }
    cout << '\n';
    return 0;
}
