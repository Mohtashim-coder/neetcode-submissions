class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        int maxArea = 1;

        for(int i=0; i<rows; i++)
        {
            for(int j=0; j<cols; j++)
            {
                if(grid[i][j] == 1)
                {
                    int area = dfs(grid, i, j);
                    maxArea = max(maxArea, area);
                }
            }
        }
        return maxArea;
    }

private:
    int dfs(vector<vector<int>> &grid, int i, int j)
    {
        // check for boundary conditions
        if(i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() || grid[i][j] == 0)
        {
            return 0;
        }

        // mark as visited
        grid[i][j] = 0;

        // explore all 4 directions
        int area = 1;
        area = area + dfs(grid, i+1, j);
        area = area + dfs(grid, i-1, j);
        area = area + dfs(grid, i, j+1);
        area = area + dfs(grid, i, j-1);

        return area;
    }
    
};
