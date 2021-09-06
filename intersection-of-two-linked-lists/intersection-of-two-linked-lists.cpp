class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        
        set<ListNode*> s;
        
        if(headA==NULL)
            return headB;
        if(headB==NULL)
            return headA;
        
        while(headA!=NULL){
            s.insert(headA);
            headA=headA->next;
        }
        
        while(headB!=NULL){
            
            if(s.find(headB)!=s.end())
                return headB;
            
            headB=headB->next;
        }
        
        return NULL;
        
    }
};