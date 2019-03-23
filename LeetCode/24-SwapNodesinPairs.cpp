class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* cur = dummy;
        
        while (cur->next && cur->next->next) {
            ListNode* temp = cur->next->next;
            cur->next->next = temp->next;
            temp->next = cur->next;
            cur->next = temp;
            cur = cur->next->next;
        }
        
        return dummy->next;
    }
};
