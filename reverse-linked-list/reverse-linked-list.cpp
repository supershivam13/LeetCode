/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        
        // Base Condition ( either 0 or 1 node only )
        if (head == NULL or head->next == NULL)
            return head;

        // Recursive call to reverse smaller linked list and return the head of the reversed list
        ListNode* RevHead = reverseList(head->next);

        head->next->next = head;
        head->next = NULL;

        return RevHead;
        
    }
};