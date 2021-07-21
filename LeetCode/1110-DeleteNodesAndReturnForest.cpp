// Time Complexity: O(n), where n is the number of nodes
// Space Comlexity: O(n+h), where h is the height of the tree
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
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        vector<TreeNode*> res;
        unordered_set<int> del(to_delete.begin(), to_delete.end());

        helper(root, del, res);
        if (del.find(root->val) == del.end()) res.push_back(root); // don't forget to consider the root!
        return res;
    }

    TreeNode* helper(TreeNode* node, unordered_set<int>& del, vector<TreeNode*>& res) {
        if (node == nullptr) return nullptr;

        node->left = helper(node->left, del, res);
        node->right = helper(node->right, del, res);

        if (del.find(node->val) != del.end()) {
            if (node->left != nullptr) res.push_back(node->left);
            if (node->right != nullptr) res.push_back(node->right);
            // if we do del.erase(node->val) here to save memory space, we will get wrong answer because the processing of root is too late
            // if we still want to do so, we can move the processing of root before the helper(root, del, res) 
            return nullptr;
        }
        else return node;
    }
};
