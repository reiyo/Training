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

// BFS, no reverse is required
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int> > outs;
        if (root == nullptr) return outs;
        
        queue<TreeNode*> q;
        q.push(root);
        bool left2right = false;

        while (!q.empty()) {
            left2right = !left2right;
            const int size = q.size();
            vector<int> out(size);
            int index = (left2right)? 0 : size-1;
            
            // important! use size rather than q.size() because the q.size() may change in the loops
            for (int i=0; i<size; ++i) {
                TreeNode* ptr = q.front();
                q.pop();
                
                if (left2right) out[index++] = ptr->val;
                else out[index--] = ptr->val;
                
                if (ptr->left != nullptr) {
                    q.push(ptr->left);
                }
                if (ptr->right != nullptr) {
                    q.push(ptr->right);
                }
            }
            
            outs.push_back(out);
        }
        
        return outs;
    }
};
