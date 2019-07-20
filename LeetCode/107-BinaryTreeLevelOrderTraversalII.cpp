class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> results;
        traverse(root, 0, results);
        reverse(results.begin(), results.end());
        return results;
    }
    
    void traverse(TreeNode* root, int depth, vector<vector<int>>& results) {
        if (!root) return;
        
        if (results.size() <= depth) results.push_back(vector<int>(1, root->val));
        else results[depth].push_back(root->val);
        
        traverse(root->left, depth+1, results);
        traverse(root->right, depth+1, results);
    }
};
