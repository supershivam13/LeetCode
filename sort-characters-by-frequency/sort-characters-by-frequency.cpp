class Solution {
public:
    string frequencySort(string s) {
        
        unordered_map<char,int> m;
        for(auto x : s)
            m[x]++;
        
        priority_queue<pair<int,char>> pq;
        string ans="";
        
        for(auto x : m)
            pq.push({x.second,x.first});
        
        while(!pq.empty()){
            
            pair<int,char>p = pq.top();
            
            for(int i = 0;i<p.first;i++)
                ans+=p.second;
            
            pq.pop();
        }
        return ans;
    }
};