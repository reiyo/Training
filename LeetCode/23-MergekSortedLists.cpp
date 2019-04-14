// refer to Approach 5 of the solution
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (!l1) return l2;
        if (!l2) return l1;
        ListNode* pseudo = new ListNode(0);
        ListNode* cur = pseudo;
        
        while (l1 && l2) {
            if (l1->val < l2->val) {
                cur->next = l1;
                l1 = l1->next;
                cur->next->next = NULL;
                cur = cur->next;
            } else {
                cur->next = l2;
                l2 = l2->next;
                cur->next->next = NULL;
                cur = cur->next;
            }
        }
        
        if (l1) {
            cur->next = l1;
        } else if (l2) {
            cur->next = l2;
        }
        
        cur = pseudo->next;
        delete pseudo;
        return cur;
    }
    
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.empty()) return NULL;
        else if (lists.size() == 1) return lists[0];
        size_t interval = 1;
        
        while (interval < lists.size()) {
            for (auto i=0; i<lists.size(); i+=(2*interval)) {
                if (i+interval < lists.size()) {
                    lists[i] = mergeTwoLists(lists[i], lists[i+interval]);
                }
            }
            
            interval *= 2;
        }
        
        return lists[0];
    }
};
