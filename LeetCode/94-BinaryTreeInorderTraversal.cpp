class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        if (!root) return vector<int>();
        
        stack<TreeNode*> mystack;
        set<TreeNode*> visited;
        vector<int> results;
        
        mystack.push(root);
        visited.insert(root);
        
        while(!mystack.empty()) {
            TreeNode* cur = mystack.top();
            
            if (cur->left && !visited.count(cur->left)) {
                mystack.push(cur->left);
                visited.insert(cur->left);
            }
            else {
                results.push_back(cur->val);
                mystack.pop();
                
                if (cur->right) {
                    mystack.push(cur->right);
                    visited.insert(cur->right);
                }
            }
        }
        
        return results;
    }
};
