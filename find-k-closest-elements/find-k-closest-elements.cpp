class Solution {
public:
    vector<int> findClosestElements(vector<int>& a, int k, int x) {
        
        vector<int> ans;
        priority_queue<pair<int,int>> mx;
        int n=a.size();
        
        for(int i=0;i<n;i++){
            mx.push({abs(x-a[i]),a[i]});
            
            if(mx.size()>k)
                mx.pop();
        }
        
        while(mx.size()>0){
            ans.push_back(mx.top().second);
            mx.pop();
        }
        
        sort(ans.begin(),ans.end());
        
        return ans;
    }
};