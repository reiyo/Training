class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        return check(root, root);
    }
    
    bool check(TreeNode *t1, TreeNode *t2)
    {
        if (!t1 || !t2) return t1 == t2;
        return ((t1->val == t2->val) && check(t1->left, t2->right) && check(t1->right, t2->left));
    }
};
