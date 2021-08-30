class Solution {
public:
    ListNode* mergeTwoLists(ListNode* a, ListNode* b) {

        // if either one list is empty, return the other list
        if (a == NULL)
            return b;
        if (b == NULL)
            return a;

        ListNode* c;

        // SORTING THE LISTS RECURSIVELY
        if (a->val < b->val)
            c = a, c->next = mergeTwoLists(a->next, b);
        else
            c = b, c->next = mergeTwoLists(a, b->next);

        return c;
    }
    
    ListNode* midpoint(ListNode *head){
        
        if(head==NULL)
            return head;
        
        ListNode* slow = head;
        ListNode* fast = head->next;
        
        while(fast!=NULL and fast->next!=NULL){
            fast = fast->next->next;
            slow = slow->next;
        }
        
        return slow;
    }
    
    ListNode* MergeSort(ListNode* head){
        
        if(head==NULL or head->next==NULL)
            return head;
        
        ListNode* mid = midpoint(head);
        
        ListNode* a = head;
        ListNode* b = mid->next;
        mid->next = NULL;
        
        a = MergeSort(a);
        b = MergeSort(b);
        
        return mergeTwoLists(a,b); 
    }
    
    ListNode* sortList(ListNode* head) {
        
        return MergeSort(head);
    }
};