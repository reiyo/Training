class Solution {
public:
    bool isValidBST(TreeNode* root) {
        if (!root) return true;
        return traverse(root, NULL, NULL);
    }
    
    bool traverse(TreeNode* cur, TreeNode* leftBound, TreeNode* rightBound)
    {
        if (leftBound && cur->val <= leftBound->val) return false;
        if (rightBound && cur->val >= rightBound->val) return false;
        
        bool flag = true;
        
        if (cur->left) {
            flag = traverse(cur->left, leftBound, cur);
        }
        
        if (!flag) return false;
        
        if (cur->right) {
            flag = traverse(cur->right, cur, rightBound);
        }
        
        return flag;
    }
};
