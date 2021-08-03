class Solution {
public:
    int largestRectangleArea(vector<int>& a) {
        
        vector<int> NSL,NSR;
        stack<pair<int,int>> s;
        int n=a.size();
        
        for(int i=0;i<n;i++){
            
            if(s.size()==0)
                NSL.push_back(-1);
            
            else if(s.size()>0 and s.top().first<a[i])
                NSL.push_back(s.top().second);
            
            else if(s.size()>0 and s.top().first>=a[i]){
                
                while(s.size()>0 and s.top().first>=a[i])
                    s.pop();
                
                if(s.size()==0)
                    NSL.push_back(-1);
                else
                    NSL.push_back(s.top().second);
            }
            
            s.push({a[i],i});
        }
        
        while(s.size()>0)
            s.pop();
        
        for(int i=n-1;i>=0;i--){
            
            if(s.size()==0)
                NSR.push_back(n);
            
            else if(s.size()>0 and s.top().first<a[i])
                NSR.push_back(s.top().second);
            
            else if(s.size()>0 and s.top().first>=a[i]){
                
                while(s.size()>0 and s.top().first>=a[i])
                    s.pop();
                
                if(s.size()==0)
                    NSR.push_back(n);
                else
                    NSR.push_back(s.top().second);
            }
            
            s.push({a[i],i});
        }
        
        reverse(NSR.begin(),NSR.end());
        
        vector<int> areas;
        
        for(int i=0;i<n;i++){
            
            int width,height;
            width = NSR[i]-NSL[i]-1;
            
            height = a[i];
            areas.push_back(width*height);
        }
        
        return *max_element(areas.begin(),areas.end());
    }
};