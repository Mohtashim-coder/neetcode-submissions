/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    int goodNodes(TreeNode* root) {
        
        // using bfs approach
        if(!root)
        {
            return 0;
        }

        queue<pair<TreeNode*, int>> q;  // {node, maxSoFar}
        q.push({root, INT_MIN});
        int count = 0;

        while(!q.empty())
        {
            auto[node, maxSoFar] = q.front();
            q.pop();

            // check if current node is good
            if(node->val >= maxSoFar)
            {
                count++;
            }

            // update max for children
            int newMax = max(maxSoFar, node->val);

            // add children to queue
            if(node->left)
            {
                q.push({node->left, newMax});
            }

            if(node->right)
            {
                q.push({node->right, newMax});
            }
        }
        return count;

    }
};
