class Solution {
public:
    vector<vector<string>> ans;
    vector<string> arrangements;

    bool isValid(int r, int c) {
        if(r == arrangements.size()) return false;
        
        for(int check = r; check >= 0; check--) {
            if(arrangements[check][c] == 'Q') return false;
        }
        int startRow = r; int startCol = c;
        while(startRow >= 0 && startCol != arrangements.size()) {
            if(arrangements[startRow][startCol] == 'Q') return false;
            startRow--; startCol++;
        }
        startRow = r; startCol = c;
        while(startRow >= 0 && startCol >= 0) {
            if(arrangements[startRow][startCol] == 'Q') return false;
            startRow--; startCol--;
        }
        return true;
    }

    void placingQueens(int r, int c, int placed, int n) {
        if(placed == n) {
            ans.push_back(arrangements);
            return;
        }

        for(int currCol = c; currCol < n; currCol++) {
            if(isValid(r, currCol)) {
                arrangements[r][currCol] = 'Q';
                placingQueens(r + 1, 0, placed + 1, n);
                arrangements[r][currCol] = '.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        arrangements.resize(n, string(n, '.'));
        placingQueens(0, 0, 0, n);
        return ans;
    }
};