class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        
        if(p==NULL and q==NULL)
            return true;
        
        if((p!=NULL and q==NULL) or (p==NULL and q!=NULL))
            return false;
        
        bool a = p->val==q->val?true:false;
        bool b = isSameTree(p->left,q->left);
        bool c = isSameTree(p->right,q->right);
        
        return (a and b and c);
    }
};