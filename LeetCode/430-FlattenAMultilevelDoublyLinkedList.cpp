class Solution {
public:
    Node* flatten(Node* head) {
        // implement https://leetcode.com/problems/flatten-a-multilevel-doubly-linked-list/discuss/152066/c%2B%2B-about-10-lines-solution
        // a node at most will be visited twice, so still O(N)
        for (Node* cur=head; cur; cur=cur->next) {
            if (cur->child) {
                Node* temp = cur->next;
                Node* last = cur->child;
                cur->next = cur->child;
                cur->next->prev = cur;
                cur->child = NULL;
                while (last->next) last = last->next;
                last->next = temp;
                if (temp) temp->prev = last;
            }
        }
        
        return head;
    }
    
    /* my original solution
    Node* flatten(Node* head) {
        if (!head) return head;
        traverse(head);
        return head;
    }
    
    Node* traverse (Node* cur) {
        if (cur->child) {
            Node* temp = cur->next;
            cur->next = cur->child;
            cur->next->prev = cur;
            cur->child = NULL;
            Node* last = traverse(cur->next);
            last->next = temp;
            
            if (temp) temp->prev = last;
            
            cur = last;
        }
        
        return (cur->next)? traverse(cur->next) : cur;
    }
    */
};
