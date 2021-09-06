class Solution {
public:
    TreeNode *SortedtoBST(vector<int> &a,int start,int end){
        
        if(start>end)
            return NULL;
        
        int mid = start + ((end-start)/2);
        TreeNode* root = new TreeNode(a[mid]);
        
        root->left = SortedtoBST(a,start,mid-1);
        root->right = SortedtoBST(a,mid+1,end);
        
        return root;
    }
    
    TreeNode *sortedArrayToBST(vector<int> &a){
        
//         if(num.size() == 0) 
//             return NULL;
        
//         int middle = num.size()/2;
//         TreeNode* root = new TreeNode(num[middle]);
        
//         vector<int> leftInts(num.begin(), num.begin()+middle);
//         vector<int> rightInts(num.begin()+middle+1, num.end());
        
//         root->left = sortedArrayToBST(leftInts);
//         root->right = sortedArrayToBST(rightInts);
        
        return SortedtoBST(a,0,a.size()-1);
    }
};
