// 3 solutions: recursive, iterative, iterative (interweaving of nodes) 
// below is the second one, while the last one perhaps to be the best
class Solution {
public:
    Node* copyRandomList(Node* head) {        
        unordered_map<Node*, Node*> dict;
        Node* cur = head;

        while (cur) {
            dict[cur] = new Node(cur->val);
            cur = cur->next;
        }

        dict[NULL] = NULL;
        cur = head;

        while (cur) {
            dict[cur]->next = dict[cur->next];
            dict[cur]->random = dict[cur->random];
            cur = cur->next;
        }
        
        return dict[head];
    }
};
