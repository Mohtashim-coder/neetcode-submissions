class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        // Build adjacency list
        vector<vector<int>> adj(n);
        for (auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);  // Undirected!
        }
        
        vector<bool> visited(n, false);
        int components = 0;
        
        // Visit each node
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                components++;  // Found a new component
                dfs(adj, visited, i);
            }
        }
        
        return components;
    }
    
private:
    void dfs(vector<vector<int>>& adj, vector<bool>& visited, int node) {
        visited[node] = true;
        
        for (int neighbor : adj[node]) {
            if (!visited[neighbor]) {
                dfs(adj, visited, neighbor);
            }
        }
    }
};