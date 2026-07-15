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
        int maxSum = INT_MIN;
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

        int leftGain = max(0, dfs(node->left, maxSum));
        int rightGain = max(0, dfs(node->right, maxSum));

        int currPathsum = node->val + leftGain + rightGain;

        // DP: update global maximum
        maxSum = max(maxSum, currPathsum);
        return node->val + max(leftGain, rightGain);
    }
};
