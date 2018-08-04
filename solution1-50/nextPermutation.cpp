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
        
    }
};


int main(int argc, char const *argv[])
{
    Solution sl;
    vector <int> nums = {1, 2, 3};
    sl.nextPermutation(nums);

    for (int a : nums) {
        cout << a << " ";
    }
    cout << endl;
    


    return 0;
}
