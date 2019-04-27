class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head) return head;
        
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* prev = dummy;
        ListNode* cur = head;
        
        while (cur) {
            while (cur->next && cur->val == cur->next->val) cur = cur->next;
            
            if (prev->next == cur) {
                prev = cur;
            }
            else {
                prev->next = cur->next;
            }
            
            cur = cur->next;
        }
        
        return dummy->next;
    }
};
