class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums, vector<int>& a) {
        vector<int> v;
        unordered_map<int,int> mp;
        stack<int> s;
        
        for(int i=a.size()-1;i>=0;i--){
            
            if(s.size()==0)
                mp[a[i]]=-1;
            
            else if(s.size()>0 and s.top()>a[i])
                mp[a[i]]=s.top();
            
            else if(s.size()>0 and s.top()<=a[i]){
                
                while(s.size()>0 and s.top()<=a[i])
                    s.pop();
                
                if(s.size()==0)
                    mp[a[i]]=-1;
                else
                    mp[a[i]]=s.top();
            }
            
            s.push(a[i]);
        }
        
        for(int i=0;i<nums.size();i++)
            v.push_back(mp[nums[i]]);
        
        return v;
    }
};