class Solution {
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        if (!root) return vector<string>();
        vector<string> output;    
        dfs(root, to_string(root->val), output);
        return output;
    }
    
    void dfs(TreeNode* root, string accuStr, vector<string>& output)
    {       
        if (!root->left && !root->right) {
            output.push_back(accuStr);
            return;            
        }
        
        accuStr += "->";
        
        if (root->left) dfs(root->left, accuStr + to_string(root->left->val), output);
        if (root->right) dfs(root->right, accuStr + to_string(root->right->val), output);
    }
};
