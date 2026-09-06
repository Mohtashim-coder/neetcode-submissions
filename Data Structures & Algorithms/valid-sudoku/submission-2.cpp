class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        
        // Hash-set for each rows, cols, and boxes
        vector<unordered_set<char>> rows(9);
        vector<unordered_set<char>> cols(9);
        vector<unordered_set<char>> boxes(9);

        for(int i=0; i<9; i++)
        {
            for(int j=0; j<9; j++)
            {
                char c = board[i][j];
                if(c == '.')
                {
                    continue;
                }

                // calculate box index
                int boxIndex = (i/3)*3 + j/3;
                if(rows[i].count(c) || cols[j].count(c) || boxes[boxIndex].count(c))
                {
                    return false;
                }

                // insert elements
                rows[i].insert(c);
                cols[j].insert(c);
                boxes[boxIndex].insert(c);
            }
        }
        return true;

    }
};
