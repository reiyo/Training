class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        if (!head) return head;
        
        ListNode *dummy = new ListNode(0);
        dummy->next = head;
        ListNode *lastSmall = dummy;
        ListNode *lastGreat = NULL;
        ListNode *cur = head;
        
        while (cur) {
            if (cur->val < x) {
                if (lastGreat) {
                    lastGreat->next = cur->next;
                    cur->next = lastSmall->next;
                    lastSmall->next = cur;
                    lastSmall = cur;
                    cur = lastGreat;
                } else {
                    lastSmall->next = cur;
                    lastSmall = lastSmall->next;
                }
            } else {
                lastGreat = cur;
            }
            
            cur = cur->next;
        }
        
        return dummy->next;
    }
};
