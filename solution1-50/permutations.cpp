#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <bitset>
#include <array>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

/* static int fast = []() {  
    ios_base::sync_with_stdio(0); 
    cin.tie(0); 
    cout.tie(0); 
    return 0; 
}(); */


class Solution {
public:

	vector<vector<int>> permute(vector<int>& nums) {
		auto len = nums.size();
		vector <vector <int>> results;
		if (len < 1) return results;

		bool visited[len];
		memset(visited, false, sizeof(visited));
		vector <int> aSolu;
		DFSpermute(nums, 0, visited, aSolu, results);
		return results;

    }

	void DFSpermute(vector <int> &nums, int level, bool visited[], vector <int> aSolu, vector <vector<int>> &results) {
		if ( level == nums.size() ) results.push_back(aSolu);
		else {
			for (int i = 0; i < nums.size(); i++) {
				if ( !visited[i]) {
					visited[i] = true;
					aSolu.push_back(nums[i]);
					DFSpermute(nums, level + 1, visited, aSolu, results);
					aSolu.pop_back();
					visited[i] = false;
				}
			}
		}
	}

};


int main()
{
	Solution sl;
	vector <int> nums;
	int n;
	cout << "Input n: " ;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int tmp;
		cin >> tmp;
		nums.push_back(tmp);
	}
	int count = 0;
	vector < vector<int>> res = sl.permute(nums);
	for ( vector <int> vec : res) {
		for (int value : vec) {
			cout << value << " ";
		}
		count++;
		cout << "\n";
	}
	cout << "Total :" << count << " permuatations." << endl;
	return 0;	
}