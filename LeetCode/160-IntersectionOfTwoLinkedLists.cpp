class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (!headA || !headB) return NULL;
        ListNode* cur1 = headA;
        ListNode* cur2 = headB;
        
        // even if two lists are with no intersection, they will move to NULL at the same time
        while (cur1 != cur2) {
            if (cur1 == NULL) cur1 = headB;
            if (cur2 == NULL) cur2 = headA;
            if (cur1 == cur2) return cur1;
            cur1 = cur1->next;
            cur2 = cur2->next;
        }
        
        return cur1;
    }
};
