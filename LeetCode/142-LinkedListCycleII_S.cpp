// refer to https://leetcode.com/problems/linked-list-cycle-ii/discuss/44781 for the proof
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if (!head || !head->next) return NULL;
        
        ListNode *h = head;
        ListNode *t = head;
        bool has_cycle = false;

        while (h && h->next) {
            h = h->next->next;
            t = t->next;
            if (h == t) {
                has_cycle = true;
                break;
            }
        }

        if (!has_cycle) return NULL;
        h = head;

        while (h != t) {
            h = h->next;
            t = t->next;
        }

        return t;
    }
};
