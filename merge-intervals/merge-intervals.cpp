class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& a) {
        
        vector<vector<int>> ans;
        int n=a.size();
        vector<int> last(2,INT_MAX);
        a.push_back(last);
        sort(a.begin(),a.end());
        int i=0,j;
        bool b=false;
        
        while(i+1<=n){
        
            while(i+1<=n and a[i][1]<a[i+1][0]){
                b=true;
                ans.push_back(a[i]);
                i++;
            }
            
            // // if(b){
            //     i++;
            //     b=false;
            // }

            while(i+1<=n and a[i][1]>=a[i+1][0]){
                
                j=i+1;

                while(j<n and a[i][1]>=a[j][0]){
                    a[i][0]=min(a[i][0],a[j][0]);
                    a[i][1]=max(a[i][1],a[j][1]);
                    j++;
                }
                
                ans.push_back(a[i]);
                i=j;
            }
        }
    
    return ans;
    }
};