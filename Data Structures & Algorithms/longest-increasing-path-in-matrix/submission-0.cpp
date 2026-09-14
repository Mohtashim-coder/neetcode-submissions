class Solution {
public:
    int m, n;
    vector<vector<int>> dp;
    int dirs[4][2] = {{0,1}, {0,-1}, {1,0}, {-1,0}};
    
    int dfs(vector<vector<int>>& matrix, int i, int j) {
        // Already computed
        if (dp[i][j] != -1) return dp[i][j];
        
        int best = 1; // minimum path length from this cell is 1 (the cell itself)
        
        for (auto& d : dirs) {
            int ni = i + d[0], nj = j + d[1];
            if (ni >= 0 && ni < m && nj >= 0 && nj < n 
                && matrix[ni][nj] > matrix[i][j]) {
                best = max(best, 1 + dfs(matrix, ni, nj));
            }
        }
        
        return dp[i][j] = best;
    }
    
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        m = matrix.size();
        n = matrix[0].size();
        dp.assign(m, vector<int>(n, -1));
        
        int ans = 0;
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                ans = max(ans, dfs(matrix, i, j));
        
        return ans;
    }
};
