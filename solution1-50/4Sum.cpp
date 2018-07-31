#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        auto len = nums.size();
        vector <vector<int> > results;
        if (len < 4) return results;
        sort(nums.begin(), nums.end());
        decltype(nums.size()) left = 0, right = len - 1;
        for (decltype(nums.size()) i = 0; i < len - 3; i++) {
            int wanted0 = target - nums[i];
                for (decltype(i) j = i + 1; j < len - 2; j++) {
                    int wanted1 = wanted0 - nums[j];
                    left = j + 1;
                    right = len - 1;
                    while (left < right) {
                        int tmp = nums[left] + nums[right];
                        if (tmp == wanted1) {
                            results.push_back({nums[i], nums[j], nums[left], nums[right]});
                            left++;
                            while(nums[left] == nums[left - 1] && left < right) {
                                left++;
                            }
                            right--;
                            while (nums[right] == nums[right + 1] && right > left) {
                                right--;
                            }
                        } else if (tmp > wanted1) {
                            right--;
                        } else {
                            left++;
                        }
                    }
                    
               }
        }
        if (results.empty()) return results;
        auto lenOfRes = results.size();
        for (decltype(results.size()) i = 0; i < lenOfRes - 1; i++) {
            if (results[i] == results[i + 1]) {
                results.erase(results.begin() + i);
            }
        }
        return results;
        
    }
};


int main()
{
    Solution sl;
    vector <int> nums;
    vector <int> nums1;

    /* some test cases:
    [-1,0,1,2,-1,-4], -1 
    [-3,-2,-1,0,0,1,2,3], 0;
    [0,0,0,0], 1;
    [-4,-3,-2,-1,0,0,1,2,3,4], 0*/
    int target = 0;
    /* nums.push_back(-3);
    nums.push_back(-2);
    nums.push_back(-1);
    nums.push_back(0);
    nums.push_back(0);
    nums.push_back(1);
    nums.push_back(2);
    nums.push_back(3); 
    target = 0; */
    
    nums.push_back(0);
    nums.push_back(0);
    nums.push_back(0);
    nums.push_back(0);
    nums.push_back(0);
    //nums.push_back(-4); 
    target = -1;


    nums1.push_back(-4);
    nums1.push_back(-3);
    nums1.push_back(-2);
    nums1.push_back(-1);
    nums1.push_back(0);
    nums1.push_back(0);
    nums1.push_back(1);
    nums1.push_back(2);
    nums1.push_back(3);
    nums1.push_back(4);

    if (nums == nums1) {
        cout << "Yes" << '\n';
    }

    target = 0;
    

    vector <vector<int>> results = sl.fourSum(nums1, target);
    cout << "Answers are: " << endl;
    for (vector<int> v : results) {
        for (decltype(v.size()) i = 0; i < v.size(); i++) {
            cout << v[i] << ' ' ;
        }
        cout << '\n';
    }


    return 0;
}


