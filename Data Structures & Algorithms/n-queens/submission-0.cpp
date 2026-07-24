class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> result;
        vector<string> board(n, string(n, '.'));
        vector<bool> col(n, false);
        vector<bool> diag1(2*n - 1, false);  // Main diagonal (r - c + n - 1)
        vector<bool> diag2(2*n - 1, false);  // Anti-diagonal (r + c)
        
        backtrack(result, board, col, diag1, diag2, 0, n);
        return result;
    }
    
private:
    void backtrack(vector<vector<string>>& result, vector<string>& board,
                   vector<bool>& col, vector<bool>& diag1, vector<bool>& diag2,
                   int row, int n) {
        // Base case: all rows filled
        if (row == n) {
            result.push_back(board);
            return;
        }
        
        // Try placing queen in each column of current row
        for (int c = 0; c < n; c++) {
            int d1 = row - c + n - 1;  // Main diagonal index
            int d2 = row + c;          // Anti-diagonal index
            
            // Check if position is safe
            if (col[c] || diag1[d1] || diag2[d2]) continue;
            
            // Place queen
            board[row][c] = 'Q';
            col[c] = true;
            diag1[d1] = true;
            diag2[d2] = true;
            
            // Recurse to next row
            backtrack(result, board, col, diag1, diag2, row + 1, n);
            
            // Backtrack: remove queen
            board[row][c] = '.';
            col[c] = false;
            diag1[d1] = false;
            diag2[d2] = false;
        }
    }
};
