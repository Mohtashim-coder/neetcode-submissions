class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> result;
        vector<string> board(n, string(n, '.'));
        vector<bool> col(n, false);
        vector<bool> diag1(2*n - 1, false);
        vector<bool> diag2(2*n - 1, false);
        backtrack(n, result, board, 0, col, diag1, diag2);
        return result;
    }

private:
    void backtrack(int &n, vector<vector<string>> &result, vector<string> &board, int row, vector<bool> &col, vector<bool> &diag1, vector<bool> &diag2)
    {
        if(row == n)
        {
            result.push_back(board);
            return;
        }

        // try placing queen in each column
        for(int c=0; c<n; c++)
        {
            int d1 = row - c + n - 1;
            int d2 = row + c;
            
            // check if the queen is safe to place or not
            if(col[c] || diag1[d1] || diag2[d2])
            {
                continue;
            }

            // place queen
            board[row][c] = 'Q';
            col[c] = true;
            diag1[d1] = true;
            diag2[d2] = true;

            backtrack(n, result, board, row + 1, col, diag1, diag2);

            board[row][c] = '.';
            col[c] = false;
            diag1[d1] = false;
            diag2[d2] = false;

        }
    }
};
