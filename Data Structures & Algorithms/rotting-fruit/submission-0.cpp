class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        queue<pair<int, int>> q; // store rotten fruits in a queue
        int freshFruits = 0;

        for(int i=0; i<rows; i++)
        {
            for(int j=0; j<cols; j++)
            {
                if(grid[i][j] == 2)
                {
                    q.push({i, j});
                }

                else if(grid[i][j] == 1)
                {
                    freshFruits++;
                }
            }
        }

        // if no fresh fruits already done
        if(freshFruits == 0)
        {
            return 0;
        }

        // Directions: Down, Up, Right, Left
        vector<pair<int, int>> dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        int minutes = 0;

        while(!q.empty() && freshFruits > 0)
        {
            int size = q.size();
            minutes++;

            for(int i=0; i<size; i++)
            {
                auto[r, c] = q.front();
                q.pop();

                for(auto[dr, dc] : dirs)
                {
                    int nr = r + dr;
                    int nc = c + dc;

                    if(nr >= 0 && nr < rows && nc >= 0 && nc < cols && grid[nr][nc] == 1)
                    {
                        grid[nr][nc] = 2; // rotten it
                        freshFruits--;
                        q.push({nr, nc});
                    }
                }
            }
        }
        return freshFruits == 0 ? minutes : -1; 
    }
};
