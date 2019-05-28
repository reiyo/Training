class Solution {
public:
    vector<TreeNode*> generateTrees(int n) {
        if (n <= 0) return vector<TreeNode*>();
        return collect(1, n);
    }
    
    vector<TreeNode*> collect(int start, int end)
    {
        if (start > end) {
            return vector<TreeNode*>(1, NULL);
        }
        
        vector<TreeNode*> results;
        
        for (int i=start; i<=end; ++i) {
            vector<TreeNode*> left = collect(start, i-1);
            vector<TreeNode*> right = collect(i+1, end);
            
            for (int j=0; j<left.size(); ++j) {
                for (int k=0; k<right.size(); ++k) {
                    TreeNode *newnode = new TreeNode(i);
                    newnode->left = left[j];
                    newnode->right = right[k];
                    results.push_back(newnode);
                }
            }
        }
        
        return results;
    }
};
