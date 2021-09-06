// Time Complexity - O(N + M)
// Space Complexity - O(N + M)

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* a, ListNode* b) {

        if (a == NULL)
            return b;
        if (b == NULL)
            return a;

        ListNode* p1=a;
        ListNode* p2=b;
        ListNode* dummyNode = new ListNode();
        ListNode* p3 = dummyNode;

        while(p1!=NULL and p2!=NULL){
            
            if(p1->val < p2->val){
                p3->next=p1;
                p1=p1->next;
            }
            else{
                p3->next=p2;
                p2 = p2->next;
            }
            p3=p3->next;
        }
        
        while(p1!=NULL){
            p3->next=p1;
            p1=p1->next;
            p3=p3->next;
        }
        
        while(p2!=NULL){
            p3->next=p2;
            p2=p2->next;
            p3=p3->next;
        }
        
        ListNode* newhead = dummyNode->next;
        
        return newhead;
    }
};