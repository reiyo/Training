class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* h1 = l1;
        ListNode* h2 = l2;
        int len1 = 0;
        int len2 = 0;
        
        while (l1) {
            ++ len1;
            l1 = l1->next;
        }
        
        while (l2) {
            ++ len2;
            l2 = l2->next;
        }
        
        if (len2 > len1) {
            l1 = h2;
            l2 = h1;
            h1 = l1;
            h2 = l2;
        } else {
            l1 = h1;
            l2 = h2;            
        }
        
        int carry = 0;
        
        while (l1 && l2) {
            int sum = l1->val + l2->val + carry;
            decompose(sum, carry);
            l1->val = sum;
            h2 = l1;
            l1 = l1->next;
            l2 = l2->next;
        }
        
        while (l1) {
            int sum = l1->val + carry;
            decompose(sum, carry);
            l1->val = sum;
            h2 = l1;
            l1 = l1->next;
        }
        
        if (carry) {
            h2->next = new ListNode(1);
        }

        return h1;
    }
    
    void decompose(int &sum, int &carry)
    {
        if (sum >= 10) {
            sum -= 10;
            carry = 1;
        } else {
            carry = 0;
        }        
    }
};
