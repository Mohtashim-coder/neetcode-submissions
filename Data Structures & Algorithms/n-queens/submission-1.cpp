class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> result;
        vector<string> board(n, string(n, '.'));
        vector<bool> col(n, false);
        vector<bool> diag1(2*n - 1, false);
        vector<bool> diag2(2*n - 1, false);
        backtrack(n, col, diag1, diag2, 0, board, result);
        return result;
    }

private:
    void backtrack(int &n, vector<bool> &col, vector<bool> &diag1, vector<bool> &diag2, int row, vector<string> &board, vector<vector<string>> &result)
    {
        if(row == n)
        {
            result.push_back(board);
            return;
        }

        // try placing queens on each col
        for(int c=0; c<n; c++)
        {
            int d1 = row - c + n - 1;
            int d2 = row + c;

            // check if position is safe
            if(col[c] || diag1[d1] || diag2[d2])
            {
                continue;
            }

            // place queen
            board[row][c] = 'Q';
            col[c] = true;
            diag1[d1] = true;
            diag2[d2] = true;

            backtrack(n, col, diag1, diag2, row + 1, board, result);

            board[row][c] = '.';
            col[c] = false;
            diag1[d1] = false;
            diag2[d2] = false;
        }
    }
};
