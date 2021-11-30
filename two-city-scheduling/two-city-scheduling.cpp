class Solution {
public:
    
    int twoCitySchedCost(vector<vector<int>>& costs) {
        
        int ans=0;
        vector<int>refund;
        
        for(auto it:costs){
            ans+=it[0];
            refund.push_back(it[0]-it[1]);
        }
        
        sort(refund.begin(),refund.end(),greater<int>());
        
        for(int i=0;i<(refund.size()/2);i++)
            ans-=refund[i];
        
        return ans;
    }
};