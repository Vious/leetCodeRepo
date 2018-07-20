#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;



/* Given a string, find the length of the
longest substring without repeating characters. */
class Solution {
public:
	double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
		int size1 = nums1.size(), size2 = nums2.size();
		double result;
		if (size1 == 0 && size2 == 0 ) {
			return 0.0;
		}
		if (size1 == 0) {
			int remain = size2 % 2;
			if (remain == 0) {
				result = (nums2[size2 / 2] 
					+ nums2[size2 / 2 - 1]) / 2.0;
				return result;
			}
			else {
				return result = nums2[size2 / 2];
			}
		}
		if (size2 == 0) {
			int remain = size1 % 2;
			if (remain == 0) {
				result = (nums1[size1 / 2]
					+ nums1[size1 / 2 - 1]) / 2.0;
				return result;
			}
			else {
				return result = nums1[size1 / 2];
			}
		}

		//algorithm
		if (nums1[size1 - 1] <= nums2[0]) {
			int totalSize = size1 + size2;
			if (totalSize % 2 == 0) {
				int tmp = totalSize / 2;
				if (tmp < size1) {
					result = (nums1[tmp] + nums1[tmp - 1]) / 2.0;
					return result;
				}
				else if (tmp > size1) {
					result = (nums2[tmp - size1 - 1] 
						+ nums2[tmp - size1]) / 2.0;
					return result;
				}
				else {
					result = (nums1[size1 - 1] + nums2[0]) / 2.0;
					return result;
				}
			}
			else {
				int tmp = (totalSize + 1) / 2;
				if (tmp <= size1) {
					result = nums1[tmp - 1];
					return result;
				}
				else {
					result = nums2[tmp - size1 - 1];
					return result;
				}
			}
		}
		else if (nums1[0] >= nums2[size2 - 1]) {
			int totalSize = size1 + size2;
			if (totalSize % 2 == 0) {
				int tmp = totalSize / 2;
				if (tmp < size2) {
					result = (nums2[tmp] + nums2[tmp - 1]) / 2.0;
					return result;
				}
				else if (tmp > size2) {
					result = (nums1[tmp - size2 - 1]
						+ nums1[tmp - size2]) / 2.0;
					return result;
				}
				else {
					result = (nums2[size2 - 1] + nums1[0]) / 2.0;
					return result;
				}
			}
			else {
				int tmp = (totalSize + 1) / 2;
				if (tmp <= size2) {
					result = nums2[tmp - 1];
					return result;
				}
				else {
					result = nums1[tmp - size2 - 1];
					return result;
				}
			}
		}
		else {
			if (size2 > size1) {
				int imin = 0, imax = size1;
				while (imin <= imax) {
					int i = (imin + imax) / 2;
					int j = (size1 + size2 + 1) / 2 - i;
					if (i < imax && nums2[j - 1] >= nums1[i]) {
						// i is too small
						imin++;
					}
					else if (i > imin && nums1[i -1] >= nums2[j]){
						// i is too big
						imax--;
					}
					else {
						int left;
						if (i == 0) { left = nums2[j - 1]; }
						else if (j == 0) { left = nums1[i - 1]; }
						else { 
							left = max(nums1[i - 1], nums2[j - 1]); 
						}
						if ((size1 + size2) % 2 == 1) { return result = left; }

						int right;
						if (i == size1) { right = nums2[j]; }
						else if (j == size2) { right = nums1[i]; }
						else {
						right = min(nums1[i], nums2[j]);
						}
						result = (left + right) / 2.0;
						return result;
					}
				}
			}
			else {
				int imin = 0, imax = size2;
				while (imin <= imax) {
					int i = (imin + imax) / 2;
					int j = (size1 + size2 + 1) / 2 - i;
					if (i < imax && nums1[j - 1] >= nums2[i]) {
						// i is too small
						imin++;
					}
					else if (i > imin && nums2[i - 1] >= nums1[j]) {
						// i is too big
						imax--;
					}
					else {
						int left;
						if (i == 0) { left = nums1[j - 1]; }
						else if (j == 0) { left = nums2[i - 1]; }
						else left = max(nums2[i - 1], nums1[j - 1]);
						if ((size1 + size2) % 2 == 1) { return result = left; }

						int right;
						if (i == size2) { right = nums1[j]; }
						else if (j == size1) { right = nums2[i]; }
						else {
							right = min(nums2[i], nums1[j]);
						}
						result = (left + right) / 2.0;
						return result;
					}
				}
			}
		}
		
		return 0.0;
	}
};


//int main()
//{
//	Solution sl;
//
//	vector <int> nums1, nums2;
//
//	//for (int i = 1; i <= 3; i++) {
//		nums2.push_back(2);
//		nums1.push_back(1);
//		nums1.push_back(3);
//		nums1.push_back(4);
//	//}
//
//	//nums2.push_back(2);
//
//	double res = sl.findMedianSortedArrays(nums1, nums2);
//
//	cout << res << endl;
//
//
//
//	system("pause");
//
//	return 0;
//}