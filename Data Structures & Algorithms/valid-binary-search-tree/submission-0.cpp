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
    bool isValidBST(TreeNode* root) {
        return dfs(root, LONG_MIN, LONG_MAX);
    }

private:
    bool dfs(TreeNode* node, long long minVal, long long maxVal)
    {
        if(!node)
        {
            return true;
        }

        if(node->val <= minVal || node->val >= maxVal)
        {
            return false;
        }

        bool leftValid = dfs(node->left, minVal, node->val);
        bool rightValid = dfs(node->right, node->val, maxVal);

        return leftValid && rightValid;
    }
};
