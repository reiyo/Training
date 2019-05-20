class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if (!head) return head;
        
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* pre = dummy;
        ListNode* cur = head;
        ListNode* fix = NULL;
        int cnt = 1;
        
        while (cur) {
            if (cnt < m) {
                pre = pre->next;
                cur = cur->next;
            } else if (cnt <= n){
                ListNode* tmp = cur->next;         
                if (fix == NULL) fix = cur;
                else cur->next = pre->next;
                fix->next = tmp;
                pre->next = cur;
                cur = tmp;
            } else {
                break;
            }
            
            ++ cnt;
        }
        
        return dummy->next;
    }
};
