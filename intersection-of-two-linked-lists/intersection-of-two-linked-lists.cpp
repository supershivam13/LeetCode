class Solution {
public:
    int length(ListNode* head){
        
        int count=0;
        ListNode* temp=head;
        
        while(temp!=NULL){
            count++;
            temp=temp->next;
        }
        
        return count;
    }
    
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        
        if(headA==NULL)
            return headB;
        if(headB==NULL)
            return headA;
        
        int l1=length(headA);
        int l2=length(headB);
        
        int d=0;
        ListNode* big;
        ListNode* small;
        
        if(l1>=l2){
            d=l1-l2;
            big=headA;
            small=headB;
        }
        else{
            d=l2-l1;
            big=headB;
            small=headA;
        }
        
        while(d--)
            big=big->next;
        
        while(big!=NULL and small!=NULL){
            if(big==small)
                return big;
            
            big=big->next;
            small=small->next;
        }
        
        return NULL;
    }
};