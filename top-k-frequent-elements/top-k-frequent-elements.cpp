class Solution {
public:
    vector<int> topKFrequent(vector<int>& a, int k) {
        
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>> > minh;
        
        vector<int> ans;
        
        int n=a.size();
        unordered_map<int,int> mp;
        
        for(int i=0;i<n;i++)
            mp[a[i]]++;
        
        for(auto i:mp){
            minh.push({i.second,i.first});
            
            if(minh.size()>k)
                minh.pop();
        }
        
        while(minh.size()>0){
            ans.push_back(minh.top().second);
            minh.pop();
        }
        
        return ans;
        
    }
};