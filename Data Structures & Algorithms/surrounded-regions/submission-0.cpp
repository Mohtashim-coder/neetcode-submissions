class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int rows = board.size();
        int cols = board[0].size();
        
        // Step 1: Mark all 'O's connected to border
        // Top and bottom edges
        for (int j = 0; j < cols; j++) {
            if (board[0][j] == 'O') dfs(board, 0, j);      // Top edge
            if (board[rows-1][j] == 'O') dfs(board, rows-1, j); // Bottom edge
        }
        
        // Left and right edges
        for (int i = 0; i < rows; i++) {
            if (board[i][0] == 'O') dfs(board, i, 0);      // Left edge
            if (board[i][cols-1] == 'O') dfs(board, i, cols-1); // Right edge
        }
        
        // Step 2: Convert remaining 'O's to 'X'
        // and convert marked 'S' back to 'O'
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (board[i][j] == 'O') {
                    board[i][j] = 'X';  // Surrounded! Turn to X
                } else if (board[i][j] == 'S') {
                    board[i][j] = 'O';  // Safe! Keep as O
                }
            }
        }
    }
    
private:
    void dfs(vector<vector<char>>& board, int i, int j) {
        int rows = board.size();
        int cols = board[0].size();
        
        // Check boundaries and if it's not 'O'
        if (i < 0 || i >= rows || j < 0 || j >= cols || board[i][j] != 'O') {
            return;
        }
        
        // Mark as safe (touches border or connected to border)
        board[i][j] = 'S';
        
        // Explore 4 directions
        dfs(board, i + 1, j);  // Down
        dfs(board, i - 1, j);  // Up
        dfs(board, i, j + 1);  // Right
        dfs(board, i, j - 1);  // Left
    }
};