class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (NULL == head || k <= 0) return head;
        
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        int len = 0;
        
        while (NULL != head) {
            head = head->next;
            ++ len;
        }
        
        k %= len;
        if (0 == k) return dummy->next;
        const int t = len - k;
        ListNode* cur = dummy;
        
        for (int i=0; i<t; ++i) {
            cur = cur->next;
        }
        ListNode* tail = cur;
        
        while (NULL != tail->next) {
            tail = tail->next;
        }
        
        tail->next = dummy->next;
        dummy->next = cur->next;
        cur->next = NULL;
        
        return dummy->next;
    }
};
