
class Solution {
public:
    bool isValidBST(TreeNode* root,long low,long high){
        
        if(root==NULL)
            return true;
        
        if(root->val<=low or root->val>=high )
            return false;
        
        bool left = isValidBST(root->left,low,root->val);
        bool right = isValidBST(root->right,root->val,high);
        
        return (left and right);
    }
    
    bool isValidBST(TreeNode* root) {
        
        return isValidBST(root,LONG_MIN,LONG_MAX);
    }
};