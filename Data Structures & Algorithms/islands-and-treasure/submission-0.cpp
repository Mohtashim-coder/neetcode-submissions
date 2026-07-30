class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        queue<pair<int, int>> q;

        // add all treasure cells to queue
        for(int i=0; i<rows; i++)
        {
            for(int j=0; j<cols; j++)
            {
                if(grid[i][j] == 0)
                {
                    q.push({i, j});
                }
            }
        }

        // Directions: Down, Up, Right, Left
        vector<pair<int, int>> dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        int distance = 0;

        // BFS from all treasure simiultaneously
        while(!q.empty())
        {
            int size = q.size();
            distance++;

            for(int i=0; i<size; i++)
            {
                auto[r, c] = q.front();
                q.pop();

                // Explore 4 directions
                for(auto[dr, dc] : dirs)
                {
                    int nr = r + dr;
                    int nc = c + dc;

                    // Check if valid land cell (INF)
                    if(nr >= 0 && nr < rows && nc >= 0 && nc < cols && grid[nr][nc] == INT_MAX)
                    {
                        grid[nr][nc] = distance;
                        q.push({nr, nc});
                    }
                }
            }

        }
    }
};
