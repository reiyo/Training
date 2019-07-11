class Solution {
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return construct(0, inorder.size()-1, postorder.size()-1, inorder, postorder);
    }
    
    TreeNode* construct(int inStart, int inEnd, int poStart, vector<int>& inorder, vector<int>& postorder)
    {
        if (poStart < 0 || inStart > inEnd) {
            return NULL;
        }
        
        TreeNode* root = new TreeNode(postorder[poStart]); 
        int tmp = 0;
        
        for (int i=inStart; i<=inEnd; ++i) {
            if (inorder[i] == root->val) {
                tmp = i;
                break;
            }
        }
        
        root->left = construct(inStart, tmp-1, poStart-(inEnd-tmp)-1, inorder, postorder);
        root->right = construct(tmp+1, inEnd, poStart-1, inorder, postorder);
        return root;
    }
};
