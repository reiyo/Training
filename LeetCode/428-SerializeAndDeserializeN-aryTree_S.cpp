// Similar to 297. 
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Codec {
public:
    // Encodes a tree to a single string.
    string serialize(Node* root) {
        if (!root) return string();
        ostringstream oss;
        serialize(root, oss);
        return oss.str();
    }

    void serialize(Node* cur, ostringstream& oss) {
        // trick is to record the number of children
        oss << cur->val << " " << cur->children.size() << " ";
        for (Node* n: cur->children) serialize(n, oss);
    }
	
    // Decodes your encoded data to tree.
    Node* deserialize(string data) {
        if (data.empty()) return nullptr;
        istringstream iss(data);
        Node* res = deserialize(iss);
        return res;
    }
    
    Node* deserialize(istringstream& iss) {
        Node* cur = new Node();
        int cnt = 0;
        iss >> cur->val >> cnt;        
        for (int i=0; i<cnt; ++i) cur->children.push_back(deserialize(iss));
        return cur;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));
