/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        
        // Empty Graph
        if(!node)
        {
            return nullptr;
        }

        // map to store visited nodes (original as copy)
        unordered_map<Node*, Node*> visited;
        return dfs(node, visited);
    }

private: 
    Node* dfs(Node* &node, unordered_map<Node*, Node*> &visited)
    {
        // if this node was already copied, return the copy
        if(visited.count(node))
        {
            return visited[node];
        }

        // create a copy of the current node
        Node* copy = new Node(node->val);
        visited[node] = copy;

        // create all neighbours
        for(Node* neighbor : node->neighbors)
        {
            copy->neighbors.push_back(dfs(neighbor, visited));
        }

        return copy;
    }
};
