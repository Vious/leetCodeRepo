#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        if (nums.empty()) return -1;
        auto len = nums.size();
        if (len == 1 && nums[0] != target) return -1;
        int left = 0, right = len - 1, middle;
        if (target > nums[right] && target < nums[left]) return -1;
        while (left <= right) {
            middle = (left + right) / 2;
            if (nums[middle] == target) return middle;
            else if (nums[middle] > target) {
                if (nums[middle] > nums[right]) {
                    if (target > nums[right]) {
                        right = middle - 1;
                    } else {
                        left = middle + 1;
                    }
                } 
                else {
                    right = middle - 1;
                }
            }
            else if (nums[middle] < target) {
                if (nums[middle] > nums[right]) {
                    left = middle + 1;
                }
                else {
                    if (target > nums[right]) {
                        right = middle - 1;
                    } else {
                        left = middle + 1;
                    }
                }
            }
        }
        return -1;
    }
};

int main(int argc, char const *argv[])
{
    Solution sl;
    vector <int> nums = {4,5,6,7,8,1,2,3};
    /* [4,5,6,7,8,1,2,3]
8 */
    int target = 8;
    int res = sl.search(nums, target);
    cout << "Anwser is :" << res;
    cout << endl;
    


    return 0;
}
