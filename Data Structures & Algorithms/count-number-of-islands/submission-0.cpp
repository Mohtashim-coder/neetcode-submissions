class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        int island = 0;

        for(int i=0; i<rows; i++)
        {
            for(int j=0; j<cols; j++)
            {
                if(grid[i][j] == '1')
                {
                    island++;
                    dfs(grid, i, j); // explore and mark all connected land
                }
            }
        }
        return island;
    }

private:
    void dfs(vector<vector<char>> &grid, int i, int j)
    {
        // check boundary conditions
        if(i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() || grid[i][j] == '0')
        {
            return;
        }

        // mark as visited
        grid[i][j] = '0'; 

        // explore all directions
        dfs(grid, i+1, j);
        dfs(grid, i-1, j);
        dfs(grid, i, j+1);
        dfs(grid, i, j-1);
    }
};
