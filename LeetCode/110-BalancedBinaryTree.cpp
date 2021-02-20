class Solution {
public:
    bool isBalanced(TreeNode* root) {
        int height = 0;
        return traverse(root, height);
    }
    
    bool traverse(TreeNode* cur, int& height)
    {
        if (!cur) return true;  
        
        int left=0, right=0;        
        if (!traverse(cur->left, left) || !traverse(cur->right, right) || abs(left-right)>1) return false;
        
        height = max(left, right)+1;
        return true;
    }
};
