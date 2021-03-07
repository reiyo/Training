// DFS
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

// BFS
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int> > outs;
        if (root == nullptr) return outs;
        
        queue<TreeNode*> q;
        unordered_map<TreeNode*, int> m;
        q.push(root);
        m[root] = 0;

        while (!q.empty()) {
            TreeNode* ptr = q.front();
            q.pop();
            int level = m[ptr];
            
            if (outs.size() <= level) outs.push_back(vector<int>());
            
            outs[level].push_back(ptr->val);
            
            if (ptr->left != nullptr) {
                q.push(ptr->left);
                m[ptr->left] = level + 1;
            }
            if (ptr->right != nullptr) {
                q.push(ptr->right);
                m[ptr->right] = level + 1;
            }
        }
        
        for (int i=1; i<outs.size(); i+=2) {
            reverse(outs[i].begin(), outs[i].end());
        }
        
        return outs;
    }
};
