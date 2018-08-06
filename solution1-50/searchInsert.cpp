#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;


/* static int x = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();
 */

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        if (nums.empty()) return 0;
        auto len = nums.size();
        if (len == 1 && nums[0] >= target) return 0;
        else if (len == 1 && nums[0] < target) return 1;
        int left =0, right = len - 1, middle;
        unsigned int insert  = 0;
        while(left <= right) {
            middle = (left + right) / 2;
            if(nums[middle] == target ) return middle;
            else if (nums[middle] > target) {
                if (middle >= 1 && target > nums[middle - 1]) {
                    return middle;
                } else if (middle == 0) {
                    return 0;
                } else {
                    right = middle - 1;
                }
            }
            else {
                if (middle < len - 1 && target < nums[middle + 1]) {
                    return middle + 1;
                } else if (middle == len - 1) {
                    return len;
                } else {
                    left = middle + 1;
                }
            }
        }
        return insert;
    }
};

int main(int argc, char const *argv[])
{
    Solution sl;
    vector <int> nums = {1, 3, 5,6};
    int target = 0;
    int res = sl.searchInsert(nums,target);
    cout << "Answer is :" << res;
    cout << endl;
    


    return 0;
}
