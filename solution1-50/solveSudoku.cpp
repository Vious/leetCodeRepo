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

/* 
bool findValuesForEmptyCells(){
    	// locate the remaining empty cells (unable to be determined by considering constraints), solve them with backtracking
        // Using lambda to compare empty cells based on its remaining possibilities.
    	auto myComp = [this](std::pair<int, int>& left, std::pair<int, int>& right) { return cells[left.first][left.second].possibilities > cells[right.first][right.second].possibilities;}; 
    	// using a priority queue to deal with all empty cells. The empty cell with smallest remaining possibilities will be at the top
    	std::priority_queue<std::pair<int, int>, std::vector< std::pair<int, int> >, decltype(myComp)> emptyCells(myComp);

    	// populate the priority_queue
    	for (int i = 0; i < 9; i++){
    		for (int j = 0; j < 9; j++){
    			if (!cells[i][j].value) // locate empty cells
    				emptyCells.push(std::make_pair(i, j));
    		}
    	}
    	return backtrack(emptyCells);

    }

    template<typename PQ_T> // use template to contain all the types needed for priority queue, so that the formal parameter won't get too long
    bool backtrack(PQ_T& emptyCells){
    	if (emptyCells.empty()) // all empty cells have been resolved
    		return true;

    	const std::pair<int, int>& targetEmpty = emptyCells.top(); // consider only the top of the priority queue
    	int i = targetEmpty.first;
    	int j = targetEmpty.second;
    	emptyCells.pop();
    	if (cells[i][j].value) // current empty cell has been filled sometime in the previous process, search the next empty cell
    		return backtrack(emptyCells);

    	std::array< std::array<Cell> > snapShot(cells); // preserve state of cells
    	for (int v = 1; v <= 9; v++){
    		if (!cells[i][j].constraints[v]){ // find each possible values to try
    			if (set(i, j, v) && backtrack(emptyCells)) // if current value can be set, back track the next empty cell
    				return true;
    			cells = snapShot; // current value fails, revert cells to snapshot state
    		}
    	}
    	return false; // all possible values tried but doesn't work. fail
    }
 */


class Solution {
    struct cell // encapsulates a single cell on a Sudoku board
	{
		uint8_t value; // cell value 1..9 or 0 if unset
		// number of possible (unconstrained) values for the cell
		uint8_t numPossibilities;
		// if bitset[v] is 1 then value can't be v
		bitset<10> constraints;
		cell() : value(0), numPossibilities(9),constraints() {};
	};
	array<array<cell,9>,9> cells;

	// sets the value of the cell to [v]
	// the function also propagates constraints to other cells and deduce new values where possible
	bool set(int i, int j, int v)
	{ 
		// updating state of the cell
		cell& c = cells[i][j];
		if (c.value == v)
			return true;
		if (c.constraints[v])
			return false;
		c.constraints = bitset<10>(0x3FE); // all 1s
		c.constraints.reset(v);
		c.numPossibilities = 1;
		c.value = v;

		// propagating constraints
		for (int k = 0; k<9; k++) {
			// to the row: 
			if (i != k && !updateConstraints(k, j, v))
				return false;
			// to the column:
			if (j != k && !updateConstraints(i, k, v))
				return false;
			// to the 3x3 square:
			int ix = (i / 3) * 3 + k / 3;
			int jx = (j / 3) * 3 + k % 3;
			if (ix != i && jx != j && !updateConstraints(ix, jx, v))
				return false;
		}
		return true;
	}
	// update constraints of the cell i,j by excluding possibility of 'excludedValue'
	// once there's one possibility left the function recurses back into set()
	bool updateConstraints(int i, int j, int excludedValue)
	{
		cell& c = cells[i][j];
		if (c.constraints[excludedValue]) {
			return true;
		}
		if (c.value == excludedValue) {
			return false;
		}
		c.constraints.set(excludedValue);
		if (--c.numPossibilities > 1)
			return true;
		for (int v = 1; v <= 9; v++) {
			if (!c.constraints[v]) {
				return set(i, j, v);
			}
		}
		assert(false);
	}

	// backtracking state - list of empty cells
	vector<pair<int, int>> bt;

	// find values for empty cells
	bool findValuesForEmptyCells()
	{
		// collecting all empty cells
		bt.clear();
		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++) {
				if (!cells[i][j].value)
					bt.push_back(make_pair(i, j));
			}
		}
		// making backtracking efficient by pre-sorting empty cells by numPossibilities
		sort(bt.begin(), bt.end(), [this](const pair<int, int>&a, const pair<int, int>&b) {
			return cells[a.first][a.second].numPossibilities < cells[b.first][b.second].numPossibilities; });
		return backtrack(0);
	}

	// Finds value for all empty cells with index >=k
	bool backtrack(int k)
	{
		if (k >= bt.size())
			return true;
		int i = bt[k].first;
		int j = bt[k].second;
		// fast path - only 1 possibility
		if (cells[i][j].value)
			return backtrack(k + 1);
		auto constraints = cells[i][j].constraints;
		// slow path >1 possibility.
		// making snapshot of the state
		array<array<cell,9>,9> snapshot(cells);
		for (int v = 1; v <= 9; v++) {
			if (!constraints[v]) {
				if (set(i, j, v)) {
					if (backtrack(k + 1))
						return true;
				}
				// restoring from snapshot,
				// note: computationally this is cheaper
				// than alternative implementation with undoing the changes
				cells = snapshot;
			}
		}
		return false;
	}
public:
	void solveSudoku(vector<vector<char>> &board) {
		cells = array<array<cell,9>,9>(); // clear array
		// Decoding input board into the internal cell matrix.
		// As we do it - constraints are propagated and even additional values are set as we go
		// (in the case if it is possible to unambiguously deduce them).
		for (int i = 0; i < 9; i++)
		{
			for (int j = 0; j < 9; j++) {
				if (board[i][j] != '.' && !set(i, j, board[i][j] - '0'))
					return; // sudoku is either incorrect or unsolvable
			}
		}
		// if we're lucky we've already got a solution,
		// however, if we have empty cells we need to use backtracking to fill them
		if (!findValuesForEmptyCells())
			return; // sudoku is unsolvable

		// copying the solution back to the board
		for (int i = 0; i < 9; i++)
		{
			for (int j = 0; j < 9; j++) {
				if (cells[i][j].value)
					board[i][j] = cells[i][j].value + '0';
			}
		}
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
    sl.solveSudoku(board);
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
	return 0;
}