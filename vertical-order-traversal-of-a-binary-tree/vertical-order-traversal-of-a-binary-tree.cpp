void TraverseTree(TreeNode* root,map<int,map<int,vector<int>>> &m,int x,int y){
    
    if(root==NULL)
        return;
    
    m[x][y].push_back(root->val);
    TraverseTree(root->left,m,x-1,y+1);
    TraverseTree(root->right,m,x+1,y+1);
}

class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        
        vector<vector<int>> ans;
        map<int,map<int,vector<int>>> m;
        
        TraverseTree(root,m,0,0);
        
        for(auto col:m){
            vector<int> v;
            
            for(auto row:col.second){
                vector<int> v1 = row.second;
                sort(v1.begin(),v1.end());
                
                v.insert(v.end(),v1.begin(),v1.end());
            }
    
            ans.push_back(v);
        }
        
        return ans;
    }
};