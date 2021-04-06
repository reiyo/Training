class Solution {
public:
    Node* cloneGraph(Node* node) {
        if (!node) return nullptr;
        unordered_map<Node*, Node*> visited;
        queue<Node*> q;
        visited[node] = new Node(node->val);
        q.push(node);
        
        while (!q.empty()) {
            Node* cur = q.front();
            q.pop();
            Node* clone = visited[cur];
            
            for (Node* n: cur->neighbors) {
                if (visited.count(n) == 0) {
                    visited[n] = new Node(n->val);
                    q.push(n);
                }
                clone->neighbors.push_back(visited[n]);
            }
        }
        
        return visited[node];
    }
};
