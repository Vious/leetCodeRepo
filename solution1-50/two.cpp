#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

using std::vector;
using std::map;

class solution {
public:
	vector<int> twoSum(vector<int>& nums, int target) {
		//vector<int> returnValues;
		//int totalNumbers = nums.size();
		//// quick thought
		//for (int i = 0; i < totalNumbers; i++) {
		//	for (int j = i + 1; j < totalNumbers; j++) {
		//		if (nums[i] + nums[j] == target) {
		//			returnValues.push_back(i);
		//			returnValues.push_back(j);
		//		}
		//	}
		//}
		//return returnValues;

		//hash map
		std::map <int, int> numMaps;
		vector<int> results;
		int numOfSize = nums.size();
		for (int i = 0; i < numOfSize; i++) {
			int wanted = target - nums[i];
			if (numMaps.count(nums[i]) != 0) {
				results.push_back(numMaps[nums[i]]);
				results.push_back(i);
				return results;
			}
			numMaps[wanted] = i;
		}
		return results;
	}
};


//int main()
//{
//	solution sl;
//	vector<int> input = { 3, 7, 11, 15 };
//	int target = 14;
//
//	vector<int> results = sl.twoSum(input, target);
//	int numSize = results.size();
//	vector<int>::iterator it;
//	for (it = results.begin(); it != results.end(); it++)
//		std::cout << *it << std::endl;
//
//
//	system("pause");
//	return 0;
//}