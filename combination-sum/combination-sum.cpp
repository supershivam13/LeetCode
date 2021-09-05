vector<vector<int>> ans;
vector<int> temp;

class Solution {
public:
    
    void solve(vector<int>& a, int x,int ind){
        
        if(x==0){
            ans.push_back(temp);
            return;
        }
        
        if(x<0)
            return;
        
        if(ind==a.size())
            return;
        
        temp.push_back(a[ind]);
        solve(a,x-a[ind],ind);
        temp.pop_back();
        
        solve(a,x,ind+1);
    }
    
    
    vector<vector<int>> combinationSum(vector<int>& a, int x) {
        
        ans.clear();
        temp.clear();
        
        solve(a,x,0);
        
        return ans;
    }
};