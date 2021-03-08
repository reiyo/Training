// one line solution can be found at https://leetcode.com/problems/count-good-nodes-in-binary-tree/discuss/635259
class Solution {
public:
    void traverse(TreeNode* cur, int val, int& cnt) {
        if (cur->val >= val) ++ cnt;
        if (cur->left!=nullptr) traverse(cur->left, max(val, cur->left->val), cnt);
        if (cur->right!=nullptr) traverse(cur->right, max(val, cur->right->val), cnt);
    }

    int goodNodes(TreeNode* root) {
        if (root==nullptr) return 0;
        int cnt = 0;
        traverse(root, root->val, cnt);
        return cnt;         
    }
};
