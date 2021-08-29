int res;

int maxpathsum(TreeNode* root){
    
    if(root==NULL)
        return 0;
    
    int l=maxpathsum(root->left);
    int r=maxpathsum(root->right);
    
    int s1 = max( max(l,r)+root->val , root->val );
    int s2 = l + r + root->val;
    
    res=max(res,max(s1,s2));
    
    return s1;
}

class Solution {
public:
    int maxPathSum(TreeNode* root) {
        
        if(root==NULL)
            return 0;
        
        res=INT_MIN;
        maxpathsum(root);
        
        return res;
    }
};