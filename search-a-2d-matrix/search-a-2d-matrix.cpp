class Solution {
public:
    bool searchMatrix(vector<vector<int>>& a, int x) {
        
        int m=a.size();
        int n=a[0].size();
        
        int start=0;
        int end=(m*n)-1;
        int mid;
        
        while(start<=end){
            
            mid = start + ((end-start)/2);
            int mid_val = a[mid/n][mid%n];
            
            if(mid_val==x)
                return true;
            
            else if(mid_val>x)
                end=mid-1;
            else 
                start=mid+1;
        }
        
        return false;        
    }
};