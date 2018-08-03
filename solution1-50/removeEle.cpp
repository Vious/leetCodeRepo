#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:

    //again, using erase
    int removeElement(vector<int>& nums, int val) {
        auto len = nums.size();
        if (len < 1) return len;
        for (decltype(len) i = 0; i < nums.size(); i++) {
            if (nums[i] == val) {
                nums.erase(nums.begin() + (i));
                i--;
            }
        }
        return nums.size();
    }

    //
    /* int removeElement(vector<int>& nums, int val) {
        auto len = nums.size();
        if (len < 1) return len;
        unsigned int count = 0;
        for (decltype(len) i = 0; i < len; i++) {
            if (nums[i] != val) {
                nums[count] = nums[i];
                count++;
            } 
        }
        return count;
    } */
};


int main(int argc, char const *argv[])
{
    vector <int> nums = {0,0,1,1,1,2,2,3,3,4, 4, 4, 5};
    vector <int> nums1 = {3, 2, 2, 3};
    Solution sl;
    int val = 3;
    auto len = sl.removeElement(nums1, val);
    cout << "len:" << len << endl;
    for (decltype(nums1.size()) i = 0; i < len; i++) {
        cout << nums1[i] << " " ;
    }
    cout << '\n';
    return 0;
}
