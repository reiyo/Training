// refer to https://leetcode.com/problems/serialize-and-deserialize-binary-tree/discuss/74259/Recursive-preorder-Python-and-C%2B%2B-O(n)
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        ostringstream oss;
        doSerialization(root, oss);
        return oss.str();
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        istringstream iss(data);
        return doDeserialization(iss);
    }
    
    void doSerialization(TreeNode* root, ostringstream& oss) {
        if (root) {
            oss << root->val << " ";
            doSerialization(root->left, oss);
            doSerialization(root->right, oss);
        } else {
            oss << "# ";
        }
    }
    
    TreeNode* doDeserialization(istringstream& iss) {
        string val;
        iss >> val;
        //if (!(iss >> val)) return NULL;
        
        if (val == "#") return NULL;
        TreeNode* root = new TreeNode(stoi(val));
        root->left = doDeserialization(iss);
        root->right = doDeserialization(iss);
        return root;
    }
    
};

