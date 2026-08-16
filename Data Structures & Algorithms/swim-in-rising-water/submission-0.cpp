class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        int left = 0, right = n * n - 1;
        
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (canReach(grid, mid)) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        
        return left;
    }
    
private:
    bool canReach(vector<vector<int>>& grid, int time) {
        int n = grid.size();
        if (grid[0][0] > time) return false;
        
        vector<vector<bool>> visited(n, vector<bool>(n, false));
        queue<pair<int, int>> q;
        
        q.push({0, 0});
        visited[0][0] = true;
        
        vector<pair<int, int>> dirs = {{1,0}, {-1,0}, {0,1}, {0,-1}};
        
        while (!q.empty()) {
            auto [r, c] = q.front();
            q.pop();
            
            if (r == n-1 && c == n-1) return true;
            
            for (auto [dr, dc] : dirs) {
                int nr = r + dr;
                int nc = c + dc;
                
                if (nr >= 0 && nr < n && nc >= 0 && nc < n &&
                    !visited[nr][nc] && grid[nr][nc] <= time) {
                    visited[nr][nc] = true;
                    q.push({nr, nc});
                }
            }
        }
        
        return false;
    }
};
