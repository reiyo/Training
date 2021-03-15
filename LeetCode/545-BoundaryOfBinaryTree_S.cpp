// refer to https://leetcode.com/problems/boundary-of-binary-tree/discuss/101294
// note that the reference seems to view the leftmost leaf as a part of left boundary
// despite of that, the implementation does not distinguish the boundaries and leaves.
class Solution {
public:
    vector<int> boundaryOfBinaryTree(TreeNode* root) {
        vector<int> res;

        res.push_back(root->val);
        traverse(root->left, true, false, res);
        traverse(root->right, false, true, res);
        return res;
    }

    bool is_leaf(TreeNode* cur) {
        return !cur->left && !cur->right;
    }

    void traverse(TreeNode* cur, bool lb, bool rb, vector<int> &res) {
        if (!cur) return;
        if (lb && !is_leaf(cur)) res.push_back(cur->val);
        else if (is_leaf(cur)) res.push_back(cur->val);

        traverse(cur->left, lb, rb && !cur->right, res);
        traverse(cur->right, lb && !cur->left, rb, res);
        if (rb && !is_leaf(cur)) res.push_back(cur->val);
    }
};
