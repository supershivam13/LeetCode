
class Solution {
public:
    // Reverse a Linked List
    ListNode* reverseList(ListNode *head)
    {
        // { Prev Curr Temp }
        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* temp;

        while (curr != NULL) {

            // store next
            temp = curr->next;

            // update current
            curr->next = prev;

            prev = curr;
            curr = temp;
        }

        head = prev;

        return head;
    }
    
    ListNode* addTwoNumbers(ListNode* first, ListNode* second) {
        
        first = reverseList(first);
        second = reverseList(second);
        
        int sum = 0;
        int carry = 0;

        // to store the final result
        ListNode* res = NULL;
        // for traversing the new LinkedList
        ListNode* curr = NULL;
        ListNode* temp;

        // Run until either one of the linked list is not empty
        while (first != NULL or second != NULL) {

            // if any list became NULL, then add 0 else add data
            sum = carry + (first ? first->val : 0) + (second ? second->val : 0);
            carry = (sum >= 10) ? 1 : 0;
            sum = sum % 10;

            // Making a new node with data = 'sum'
            temp = new ListNode(sum);

            // res stores the address of the head of the new LinkedList
            if (res == NULL)
                res = temp;
            else
                curr->next = temp;
            curr = temp;

            // Checking whether already has became NULL, if not then move to next
            if (first) first = first->next;
            if (second) second = second->next;
        }

        // Adding the last carry node if carry remains > 0
        if (carry > 0) {
            temp = new ListNode(carry);
            curr->next = temp;
            curr = temp;
        }
        
        res = reverseList(res);
        return res;
        
    }
};