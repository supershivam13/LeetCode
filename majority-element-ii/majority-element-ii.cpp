class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n=nums.size();
        
        map<int,int> m;
        vector<int> ans;
        
        for(int x:nums)
            m[x]++;
        
        for(auto p:m){
            if(p.second>n/3)
                ans.push_back(p.first);
        }
        
        return ans;
    }
};