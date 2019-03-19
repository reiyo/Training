class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (!head || n<=0) return head;
        
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* current = dummy;
        ListNode* frontier = dummy;
        int cnt = 0;
        
        while (cnt < n && frontier!=NULL) {
            frontier = frontier->next;
            ++ cnt;
        }
        
        if (frontier == NULL) return head;
        frontier = frontier->next;
        
        while (frontier!=NULL) {
            frontier = frontier->next;
            current = current->next;
        }
        
        current->next = current->next->next;
        return dummy->next;
    }
};
