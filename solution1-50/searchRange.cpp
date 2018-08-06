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
    vector<int> searchRange(vector<int>& nums, int target) {
        vector <int> res;
        if (nums.empty()) {
            res.push_back(-1);
            res.push_back(-1);
            return res;
        }
        auto len = nums.size();
        if (len == 1 && nums[0] != target) {
            res.push_back(-1);
            res.push_back(-1);
            return res;
        } else if (len == 1 && nums[0] == target) {
            res.push_back(0);
            res.push_back(0);
            return res;
        }
        int left = 0, right = len - 1, middle;
        while (left <= right) {
            middle = (left + right) / 2;
            if (nums[middle] > target) {
                right = middle - 1;
            } else if (nums[middle] < target) {
                left = middle + 1;
            } else {
                //nums[middle] == target
                int tmpL = middle, tmpR = middle;
                while (tmpL - 1 >= 0 && nums[tmpL - 1] == target) {
                    tmpL--;
                }
                while (tmpR + 1 < len && nums[tmpR + 1] == target) {
                    tmpR++;
                }
                res.push_back(tmpL);
                res.push_back(tmpR);
                return res;
            }
        }
        res.push_back(-1);
        res.push_back(-1);
        return res;
    }
};

int main(int argc, char const *argv[])
{
    Solution sl;
    vector <int> nums = {2,2};
    /* [4,5,6,7,8,1,2,3]
8 */
    int target = 2;
    vector <int> res = sl.searchRange(nums, target);
    for (int r : res) {
        cout << r << " ";
    }
    cout << endl;
    


    return 0;
}
