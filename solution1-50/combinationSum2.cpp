#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <bitset>
#include <array>
#include <assert.h>

using namespace std;

/* static int fast = []() {  
    ios_base::sync_with_stdio(0); 
    cin.tie(0); 
    cout.tie(0); 
    return 0; 
}(); */


class Solution {
public:
	void dfsCombSum(vector<int> &candidates, int target, int cumulate, vector<int> aSolu, 
					vector <vector <int>> &results) {
		if (target == 0) {
			results.push_back(aSolu);
			return;
		} else {
			for (int i = cumulate; i < candidates.size(); ) {
				int value = candidates[i];
				if (value <= target) {
					aSolu.push_back(value);
					dfsCombSum(candidates, target - value, i + 1, aSolu, results);
					i++;
					while ( i >= 1 && candidates[i] == candidates[i - 1]) i++;
					aSolu.pop_back();
				} else {
					aSolu.pop_back();
					break;
				}
			}
		}
	}

	vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
		sort(candidates.begin(), candidates.end());
        vector <vector <int>> results;
		vector<int> aSolu;
		dfsCombSum(candidates, target, 0, aSolu, results);
		return results;
    }
};


int main()
{
	Solution sl;
    vector <int> candidates;
	int target;
	int numOfCanndidates;
	cout << "Input target: ";
	cin >> target;
	cout << "Input numOf Candidates: ";
	cin >> numOfCanndidates;
	cout << "Input candidates: ";
	int tmp;
	for (int i = 0; i < numOfCanndidates; i++) {
		cin >> tmp;
		candidates.push_back(tmp);
	}
	/* for (auto a : candidates) cout << a << " ";
	cout << '\n'; */
	vector<vector <int>> results = sl.combinationSum2(candidates, target);
	for (auto &res : results) {
		for (int &v : res) {
			cout << v << " ";
		}
		cout << '\n';
	}
	return 0;
}