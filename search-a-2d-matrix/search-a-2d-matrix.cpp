class Solution {
public:
    bool searchMatrix(vector<vector<int>>& a, int x) {
        
        int m=a.size();
        int n=a[0].size();
        
        int i=0;
        int j=n-1;
        
        while(i>=0 and i<m and j>=0 and j<n){
        
            if(a[i][j]==x)
                return true;
            
            else if(a[i][j]>x)
                j--;
            else 
                i++;
        }
        
        return false;        
    }
};