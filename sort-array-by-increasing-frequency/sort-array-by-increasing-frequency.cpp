class Solution {
public:
    vector<int> frequencySort(vector<int>& a) {
        
        unordered_map<int,int> mp;
        vector<int> ans;
        int n=a.size();
        
        for(int i=0;i<n;i++)
            mp[a[i]]++;
        
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> minh;
        
        for(auto i:mp)
            minh.push({i.second,-i.first});
        
        while(minh.size()>0){
            int freq=minh.top().first;
            int num =-minh.top().second;
            
            while(freq){
                ans.push_back(num);
                freq--;
            }
            
            minh.pop(); 
        }
        
        return ans;
        
    }
};