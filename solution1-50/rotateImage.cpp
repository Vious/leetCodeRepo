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

	void rotate(vector<vector<int>>& matrix) {
        auto n = matrix.size();
		if ( n <= 1) return;
		for (int i = 0; i < n; i++) {
			for (int j = i + 1; j < n; j++) {
				swap(matrix[i][j], matrix[j][i]);
			}
		}
		cout << "Rotating: \n"; 
		for (vector <int> &row : matrix) {
			for (int &v : row) {
				cout << v << " ";
			}
			cout << '\n';
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j <= n / 2 - 1; j++) {
				swap(matrix[i][j], matrix[i][n - 1 - j]);
			}
		}
		return;
    }

};


int main()
{
	Solution sl;
	vector <vector <int>> matrix;
	vector <int> row;
	int n;
	cout << "Input n: " ;
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j  = 0; j < n; j++) {
			int tmp;
			cin >> tmp;
			row.push_back(tmp);
		}
		matrix.push_back(row);
		row.clear();
	}
	sl.rotate(matrix);
	cout << "After rotate : " << endl;
	for (vector <int> &row : matrix) {
		for (int &v : row) {
			cout << v << " ";
		}
		cout << '\n';
	}
	return 0;	
}