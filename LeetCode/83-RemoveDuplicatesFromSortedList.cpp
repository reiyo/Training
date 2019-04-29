class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head) return head;
        
        ListNode* tail = head;
        ListNode* cur = head->next;
        
        while (cur != NULL) {
            if (cur->val == tail->val) tail->next = cur->next;
            else tail = tail->next;
            
            cur = cur->next;
        }
        
        return head;
    }
};
