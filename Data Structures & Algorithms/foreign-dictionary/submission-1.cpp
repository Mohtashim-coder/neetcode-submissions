class Solution {
public:
    string foreignDictionary(vector<string>& words) {
        // Step 1: Build graph and indegree map
        unordered_map<char, unordered_set<char>> graph;
        unordered_map<char, int> indegree;
        
        // Initialize all characters from all words
        for (string& word : words) {
            for (char c : word) {
                graph[c] = {};
                indegree[c] = 0;
            }
        }
        
        // Step 2: Build edges by comparing adjacent words
        for (int i = 0; i < words.size() - 1; i++) {
            string w1 = words[i];
            string w2 = words[i + 1];
            int len = min(w1.length(), w2.length());
            bool found = false;
            
            for (int j = 0; j < len; j++) {
                if (w1[j] != w2[j]) {
                    // w1[j] comes before w2[j]
                    if (graph[w1[j]].find(w2[j]) == graph[w1[j]].end()) {
                        graph[w1[j]].insert(w2[j]);
                        indegree[w2[j]]++;
                    }
                    found = true;
                    break;
                }
            }
            
            // If w2 is a prefix of w1, invalid order
            if (!found && w1.length() > w2.length()) {
                return "";
            }
        }
        
        // Step 3: Topological Sort (Kahn's Algorithm)
        queue<char> q;
        for (auto& [c, count] : indegree) {
            if (count == 0) {
                q.push(c);
            }
        }
        
        string result = "";
        while (!q.empty()) {
            char c = q.front();
            q.pop();
            result += c;
            
            for (char neighbor : graph[c]) {
                indegree[neighbor]--;
                if (indegree[neighbor] == 0) {
                    q.push(neighbor);
                }
            }
        }
        
        // If not all characters are in result → cycle exists
        if (result.length() != graph.size()) {
            return "";
        }
        
        return result;
    }
};