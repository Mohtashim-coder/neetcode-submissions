class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        // Build adjacency list
        vector<vector<int>> adj(numCourses);
        for (auto& prereq : prerequisites) {
            adj[prereq[1]].push_back(prereq[0]);  // b → a
        }
        
        // visited: 0 = unvisited, 1 = visiting, 2 = visited
        vector<int> visited(numCourses, 0);
        
        for (int i = 0; i < numCourses; i++) {
            if (visited[i] == 0) {
                if (hasCycle(adj, visited, i)) {
                    return false;  // Cycle detected!
                }
            }
        }
        
        return true;
    }
    
private:
    bool hasCycle(vector<vector<int>>& adj, vector<int>& visited, int node) {
        // Mark as currently visiting
        visited[node] = 1;
        
        // Check all neighbors
        for (int neighbor : adj[node]) {
            if (visited[neighbor] == 1) {
                return true;  // Found a cycle!
            }
            if (visited[neighbor] == 0) {
                if (hasCycle(adj, visited, neighbor)) {
                    return true;
                }
            }
        }
        
        // Mark as fully visited
        visited[node] = 2;
        return false;
    }
};