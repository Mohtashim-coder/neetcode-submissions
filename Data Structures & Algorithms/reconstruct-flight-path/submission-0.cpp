class Solution {
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        // Build graph: from → list of destinations (min-heap for lexicographical order)
        unordered_map<string, priority_queue<string, vector<string>, greater<string>>> graph;
        
        for (auto& ticket : tickets) {
            graph[ticket[0]].push(ticket[1]);
        }
        
        vector<string> result;
        dfs(graph, "JFK", result);
        
        reverse(result.begin(), result.end());
        return result;
    }
    
private:
    void dfs(unordered_map<string, priority_queue<string, vector<string>, greater<string>>>& graph,
             string airport, vector<string>& result) {
        // Visit all destinations from current airport in lexicographical order
        while (!graph[airport].empty()) {
            string next = graph[airport].top();
            graph[airport].pop();
            dfs(graph, next, result);
        }
        
        // Add airport after all destinations are visited
        result.push_back(airport);
    }
};