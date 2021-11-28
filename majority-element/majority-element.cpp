class Solution {
public:
    int majorityElement(vector<int>& nums) {
        
        int n=nums.size();
        map<int,int> m;
        
        for(int x:nums)
            m[x]++;
        
        for(auto p:m)
            if(p.second>n/2)
                return p.first;
    
        return -1;   
    }
};