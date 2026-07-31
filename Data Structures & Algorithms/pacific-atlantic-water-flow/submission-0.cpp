class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int rows = heights.size();
        int cols = heights[0].size();

        // visited arrays for pacific and Atlantic
        vector<vector<bool>> pacific(rows, vector<bool>(cols, false));
        vector<vector<bool>> atlantic(rows, vector<bool>(cols, false));

        // DFS from Pacific edges (top and left)
        for(int i=0; i<rows; i++)
        {
            dfs(heights, pacific, i, 0); // Left edge
        }

        for(int j=0; j<cols; j++)
        {
            dfs(heights, pacific, 0, j); // Top edge
        }

        // DFS from Atlantic edges (bottom and right)
        for(int i=0; i<rows; i++)
        {
            dfs(heights, atlantic, i, cols - 1);
        }

        for(int j=0; j<cols; j++)
        {
            dfs(heights, atlantic, rows - 1, j);
        }

        // find cells that can reach both oceans
        vector<vector<int>> result;
        for(int i=0; i<rows; i++)
        {
            for(int j=0; j<cols; j++)
            {
                if(pacific[i][j] && atlantic[i][j])
                {
                    result.push_back({i, j});
                }
            }
        }
        return result;
    }

private:
    void dfs(vector<vector<int>> &heights, vector<vector<bool>> &visited, int r, int c)
    {
        int rows = heights.size();
        int cols = heights[0].size();

        visited[r][c] = true;

        // Directions : Down, Up, Right, Left
        vector<pair<int, int>> dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

        for(auto[dr, dc] : dirs)
        {
            int nr = r + dr;
            int nc = c + dc;

            if(nr >= 0 && nr < rows && nc >= 0 && nc < cols && !visited[nr][nc])
            {
                if(heights[nr][nc] >= heights[r][c])
                {
                    dfs(heights, visited, nr, nc);
                }
            }
        }
    }
};
