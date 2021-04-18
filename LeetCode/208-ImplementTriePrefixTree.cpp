class Node {
public:
    Node() {
        memset(child, 0, sizeof(child));
        // void *memset(void *s, int c, size_t n)
        // as nullptr is not an integer, so it does not work below
        // memset(child, nullptr, 26);
        
        is_word = false;
    }
    
    Node* child[26];
    bool is_word; // does not use is_leaf because a word can be in an internal node
};

class Trie {
public:
    Node* root;
    
    /** Initialize your data structure here. */
    Trie() {
        root = new Node();
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        Node* cur = root;
        
        for (char c: word) {
            if (cur->child[c-'a'] == nullptr) cur->child[c-'a'] = new Node();
            cur = cur->child[c-'a'];
        }
        
        cur->is_word = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        Node* cur = root;
        
        for (char c: word) {
            if (cur->child[c-'a'] == nullptr) return false;
            cur = cur->child[c-'a'];
        }
        
        return cur->is_word;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        Node* cur = root;
        
        for (char c: prefix) {
            if (cur->child[c-'a'] == nullptr) return false;
            cur = cur->child[c-'a'];
        }
        
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
