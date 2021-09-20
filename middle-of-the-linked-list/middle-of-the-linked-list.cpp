class Solution {
public:
    int length(ListNode* head) {

        int count = 0;
        ListNode* temp = head;

        while (temp != NULL) {
            count++;
            temp = temp->next;
        }
        return count;
    }
    
    ListNode* middleNode(ListNode* head) {
        
        if(head==NULL)
            return head;
        
        ListNode* slow=head;
        ListNode* fast=head->next;

        while(fast!=NULL and fast->next!=NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        
        int l = length(head);
    
        if(l%2==0)
            slow=slow->next;
        
    return slow;
    }
};