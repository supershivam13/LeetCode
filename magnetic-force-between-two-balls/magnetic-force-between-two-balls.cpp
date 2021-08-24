class Solution {
public:
    
    bool isvalid(vector<int>&a, int n, int m,int dist){
        
        int count=1;
        int last_place=a[0];
        
        for(int i=1;i<n;i++){
            if(a[i]-last_place>=dist){
                count++;
                last_place=a[i];
            }
        }
        
        if(count>=m)
            return true;
        else
            return false;
    }
    int maxDistance(vector<int>& a, int m) {
        
        int n=a.size();
        sort(a.begin(),a.end());
        
        int low=1;
        int high=a[n-1]-a[0];
        int mid;
        int res=-1;
        
        while(low<=high){
            
            mid=low+((high-low)/2);
            
            if(isvalid(a,n,m,mid)==true){
                res=mid;
                low=mid+1;
            }
            else
                high=mid-1;
        }
        
        return res;
    }
};