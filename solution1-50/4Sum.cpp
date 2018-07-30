#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        auto len = nums.size();
        if (len < 4) return {};
        vector <vector<int> > results;
        sort(nums.begin(), nums.end());
        int left = 0, right = len - 1;
        for (decltype(nums.size()) i = 0; i < len - 3; i++) {
            int wanted = 
        }
        
        return results;
        
    }
};


int main()
{
    Solution sl;
    vector <int> nums;
    int target = 0;
    nums.push_back(1);
    nums.push_back(0);
    nums.push_back(-1);
    nums.push_back(0);
    nums.push_back(-2);
    nums.push_back(2);
    vector <vector<int>> results = sl.fourSum(nums, target);
    cout << "Answers are: " << endl;
    for (vector<int> v : results) {
        for (decltype(v.size()) i = 0; i < v.size(); i++) {
            cout << v[i];
        }
        cout << '\n';
    }


    return 0;
}


