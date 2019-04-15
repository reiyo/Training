class Solution {
public:
    int findTilt(TreeNode* root) {
        int accu_diff = 0;
        traverse(root, accu_diff);
        return accu_diff;
    }
    
    int traverse(TreeNode* root, int& accu_diff) {
        if (!root) return 0;
        const int l_sum = traverse(root->left, accu_diff);
        const int r_sum = traverse(root->right, accu_diff);
        accu_diff += abs(l_sum - r_sum);   
        return (l_sum + r_sum + root->val);
    }
};
