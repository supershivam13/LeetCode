class Solution {
public:
    int minAreaRect(vector<vector<int>>& v) {
        
        int ans=INT_MAX;
        int n=v.size();
        
        set<pair<int,int>> s;
        pair<int,int> p1,p2,p3,p4;
        
        for(int i=0;i<n;i++)
            s.insert({v[i][0],v[i][1]});
        
        
        for(int i=0;i<n-1;i++){
            for(int j=i+1;j<n;j++){
                
                
                
                p1.first=v[i][0];
                p1.second=v[i][1];
                
                p2.first=v[j][0];
                p2.second=v[j][1];
            
                if (p1.first == p2.first or p1.second == p2.second)
                    continue;

                p3.first = p1.first;
                p3.second = p2.second;

                p4.first = p2.first;
                p4.second = p1.second;
                
                if(s.find(p3)!=s.end() and s.find(p4)!=s.end()){
                    int area = abs(p1.first-p2.first) * abs(p1.second-p2.second);
                    ans = min(ans,area);
                }
                
            }
        }
        
        if(ans==INT_MAX)
            return 0;
        else
            return ans;
        
    }
};