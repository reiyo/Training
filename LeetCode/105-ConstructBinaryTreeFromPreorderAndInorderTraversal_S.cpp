class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return construct(0, 0, inorder.size(), preorder, inorder);
    }
    
    TreeNode* construct(int prStart, int inStart, int inEnd, vector<int>& preorder, vector<int>& inorder)
    {
        if (inEnd < inStart || inStart >= inorder.size()) {
            return NULL;
        }
        
        TreeNode* root = new TreeNode(preorder[prStart]);
        int tmp = 0;
        
        for (int i=inStart; i<=inEnd; ++i) {
            if (inorder[i] == root->val) {
                tmp = i;
                break;
            }
        }
        
        root->left = construct(prStart+1, inStart, tmp-1, preorder, inorder);
        root->right = construct(prStart+(tmp-inStart)+1, tmp+1, inEnd, preorder, inorder);
        return root;
    }
};
