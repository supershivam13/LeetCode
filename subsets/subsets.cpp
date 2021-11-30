class Solution {
public:
    vector<vector<int>> ans;
    
    void subsets(vector<int> a,vector<int>out){
        
        if(a.size()==0){
            ans.push_back(out);
            return;
        }
        
        vector<int> out1 = out;
        vector<int> out2 = out;
        
        out2.push_back(a[0]);
        
        a.erase(a.begin());
        
        subsets(a,out1);
        subsets(a,out2); 
    }
    
    vector<vector<int>> subsets(vector<int>& a) {
        
        vector<int> out;
        
        subsets(a,out);
        
        return ans; 
    }
};