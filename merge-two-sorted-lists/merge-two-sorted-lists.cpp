class Solution {
public:
    ListNode* mergeTwoLists(ListNode* a, ListNode* b) {

        if (a == NULL)
            return b;
        if (b == NULL)
            return a;

        ListNode* result;

        // SORTING THE LISTS RECURSIVELY
        if (a->val <= b->val) {
            result = a;
            result->next = mergeTwoLists(a->next, b);
        }
        else {
            result = b;
            result->next = mergeTwoLists(a, b->next);
        }

        return result;
    }
};