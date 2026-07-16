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

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(!root)
        {
            return "";
        }

        string result;
        serializeHelper(root, result);
        return result;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.empty())
        {
            return nullptr;
        }

        stringstream ss(data);
        string item;
        queue<string> nodes;

        while(getline(ss, item, ',')){
            nodes.push(item);
        }

        return deserializeHelper(nodes);
    }

private:
    void serializeHelper(TreeNode* node, string &result)
    {
        if(!node)
        {
            result = result + "null,";
            return;
        }

        // Preorder: Root -> Left -> Right
        result = result + to_string(node->val) + ",";
        serializeHelper(node->left, result);
        serializeHelper(node->right, result);
    }

    TreeNode* deserializeHelper(queue<string>& nodes)
    {
        if (nodes.empty()) return nullptr;
        string val = nodes.front();
        nodes.pop();

        if(val == "null")
        {
            return nullptr;
        }

        TreeNode* node = new TreeNode(stoi(val));
        node->left = deserializeHelper(nodes);
        node->right = deserializeHelper(nodes);

        return node;
    }
};