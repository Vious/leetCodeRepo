#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <unordered_set>

using namespace std;

/* static int fast = []() {  
    ios_base::sync_with_stdio(0); 
    cin.tie(0); 
    cout.tie(0); 
    return 0; 
}(); */

class Solution {
public:

    bool checkRow(const vector<vector <char>> &board, int row) {
        int nums = 0;
        unordered_set <char> rowCount;
        for (int i = 0; i < 9; i++ ) {
            if (board[row][i] != '.') {
                ++nums;
                rowCount.emplace(board[row][i]);
            }
        }
        if (rowCount.size() == nums) return true;
        else return false;
    }

    bool checkCol(const vector<vector <char>> &board, int col) {
        int nums = 0;
        unordered_set <char> colCount;
        for (int i = 0; i < 9; i++) {
            if (board[i][col] != '.' ) {
                ++nums;
                colCount.emplace(board[i][col]);
            }
        }
        if (colCount.size() == nums) return true;
        else return false;
    }

    bool checkSquare3(const vector<vector <char>> &board, int width, int height) {
        int nums = 0;
        unordered_set <char> squareCount;
        for (int i = 3 * width; i < 3 * width + 3; i++) {
            for (int j = 3 * height; j < 3 * height + 3; j++) {
                if (board[i][j] != '.') {
                    ++nums;
                    squareCount.emplace(board[i][j]);
                }
            }
        }
        if (squareCount.size() == nums) return true;
        else return false;
    }

    bool isValidSudoku(vector<vector<char>>& board) {
		for (int i = 0; i < 9; i++) {
            if (checkRow(board, i) && checkCol(board, i) && checkSquare3(board, i / 3, i % 3)) {
                continue;
            } else return false;
        }
        
        return true;

    }

};


int main()
{
	Solution sl;
    vector <vector <char>> board(9);
    for (int i = 0 ; i < 9; i++) {
        board[i].resize(9);
    }
    for (int i = 0; i < 9; i++ ) {
        for (int j = 0; j < 9; j++) {
            cin >> board[i][j];
            
        }
    }
    bool isValid = sl.isValidSudoku(board);
    if (isValid) {
        cout << "true" << endl;
    } else {
        cout << "false" << endl;
    }
	return 0;
}