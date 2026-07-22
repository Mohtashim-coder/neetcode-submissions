class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();
        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(dfs(board, word, i, j, 0))
                {
                    return true;
                }
            }
        }
        return false;
    }

private:
    bool dfs(vector<vector<char>> &board, string &word, int i, int j, int index)
    {
        // edge case: if the size of required word is zero
        if(index == word.length())
        {
            return true;
        }

        // all the parameters lies within the range
        if(i < 0 || i >= board.size() || j < 0 || j >= board[0].size() || board[i][j] != word[index])
        {
            return false;
        }

        // marked cell as visited
        char temp = board[i][j];
        board[i][j] = '#';

        bool found = dfs(board, word, i+1, j, index+1) || // move down
                     dfs(board, word, i-1, j, index+1) || // move up
                     dfs(board, word, i, j+1, index+1) || // move right
                     dfs(board, word, i, j-1, index+1); // move left

        // backtrack
        board[i][j] = temp;
        return found;
    }
};
