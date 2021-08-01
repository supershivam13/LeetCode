#define vvi             vector<vector<int>>

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        
        priority_queue<pair<int,pair<int,int>>> maxh;
        int n=points.size();
        
        vvi ans;
        
        for(int i=0;i<n;i++){
            int x=points[i][0];
            int y=points[i][1];
            
            maxh.push({(x*x) + (y*y),{x,y}});
            
            if(maxh.size()>k)
                maxh.pop();
        }
        
        while(maxh.size()>0){
            pair<int,int> xy = maxh.top().second;
            vector<int> tmp;
            tmp.push_back(xy.first);
            tmp.push_back(xy.second);
            ans.push_back(tmp);
            
            maxh.pop();
        }
        
        return ans;
    }
};