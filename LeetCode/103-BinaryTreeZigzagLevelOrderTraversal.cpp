class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> results;
        traverse(root, 0, results);
        
        for (int i=1; i<results.size(); i+=2) {
            reverse(results[i].begin(), results[i].end());    
        }
        
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
