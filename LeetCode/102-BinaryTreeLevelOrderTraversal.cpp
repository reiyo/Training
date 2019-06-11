class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> results;
        traverse(root, 0, results);
        return results;
    }
    
    void traverse(TreeNode *t, int level, vector<vector<int>> &results)
    {
        if (!t) return;
        
        if (results.size() <= level) {
            results.push_back(vector<int>(1, t->val));
        } else {
            results[level].push_back(t->val);
        }
        
        traverse(t->left, level+1, results);
        traverse(t->right, level+1, results);
    }
};
