class Solution {
public:
    bool hasPathSum(TreeNode* root, int sum) {
        if(root == NULL)
            return false;
        
        int newsum = sum - root->val;
        
        if(root->left == NULL && root->right == NULL)
            return newsum == 0;
        
        return hasPathSum(root->left, newsum) || hasPathSum(root->right, newsum);
    }
};