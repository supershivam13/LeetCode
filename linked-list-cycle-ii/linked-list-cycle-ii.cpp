class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        
        bool hasCycle = false;
        ListNode* fast = head;
        ListNode* slow = head;
        
        while(fast!=NULL and fast->next!=NULL){       
            slow = slow->next;
            fast = fast->next->next;
            
            if(fast==slow){
                hasCycle=true;
                break;
            }
        }
        
        if(hasCycle==false)
            return NULL;
        
        fast=head;
        
        while(fast!=slow){
            slow=slow->next;
            fast=fast->next;
        }
        
        return fast;
        
    }
};