class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses);
        for (auto& prereq : prerequisites) {
            graph[prereq[1]].push_back(prereq[0]);
        }
        
        vector<int> visited(numCourses, 0);  // 0=unvisited, 1=visiting, 2=visited
        vector<int> result;
        
        for (int i = 0; i < numCourses; i++) {
            if (visited[i] == 0) {
                if (hasCycle(graph, visited, result, i)) {
                    return {};  // Cycle detected!
                }
            }
        }
        
        reverse(result.begin(), result.end());
        return result;
    }
    
private:
    bool hasCycle(vector<vector<int>>& graph, vector<int>& visited, 
                  vector<int>& result, int course) {
        visited[course] = 1;  // Visiting
        
        for (int next : graph[course]) {
            if (visited[next] == 1) {
                return true;  // Cycle!
            }
            if (visited[next] == 0) {
                if (hasCycle(graph, visited, result, next)) {
                    return true;
                }
            }
        }
        
        visited[course] = 2;  // Visited
        result.push_back(course);  // Add to result (post-order)
        return false;
    }
};