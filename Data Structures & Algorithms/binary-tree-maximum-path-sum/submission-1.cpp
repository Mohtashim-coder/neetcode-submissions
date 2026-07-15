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
    int maxPathSum(TreeNode* root) {
        // 1. Binary tree: start from root
        // 2. DP: Track global maximum
        int maxSum = INT_MIN;

        // 3. dfs: traverse entire tree
        dfs(root, maxSum);
        return maxSum;
    }

private:
    int dfs(TreeNode* node, int &maxSum)
    {
        if(!node)
        {
            return 0;
        }

        // DFS: explore left subtree
        int leftGain = max(0, dfs(node->left, maxSum));

        // DFS: explore right subtree
        int rightGain = max(0, dfs(node->right, maxSum));

        // tree & dp: path through current node
        int pathThroughNode = node->val + leftGain + rightGain;

        // DP: update global maximum
        maxSum = max(maxSum, pathThroughNode);

        // DFS & DP: return best path going up
        return node->val + max(leftGain, rightGain);
    }
};
