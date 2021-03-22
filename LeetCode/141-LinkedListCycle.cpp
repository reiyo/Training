class Solution {
public:
    bool hasCycle(ListNode *head) {
        if (!head || !head->next) return false;
        ListNode *h=head;
        ListNode *t=head;

        while (h && h->next) {
            h = h->next->next;
            t = t->next;
            if (h == t) return true;
        }

        return false;
    }
};
