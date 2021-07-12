class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& a) {
        
        int n=a.size();
        int m=a[0].size();
        
        int dp[n][m];
        
        //Base Condition ( base case is whole last row here )
        for(int i=0;i<m;i++)
            dp[n-1][i]=a[n-1][i];
        
        for(int i=n-2;i>=0;i--){
            for(int j=m-1;j>=0;j--){
                
                // down cell always exist
                dp[i][j]=dp[i+1][j];
                
                // if down right cell exists
                if(j+1<m)
                    dp[i][j]=min(dp[i][j],dp[i+1][j+1]);
                    
                // if down left cell exists  
                if(j-1>=0)
                    dp[i][j]=min(dp[i][j],dp[i+1][j-1]);
                
                dp[i][j]+=a[i][j];
            }
        }
        
        int ans=INT_MAX;
        
        for(int i=0;i<m;i++){
            ans=min(ans,dp[0][i]);
        }
        
        return ans;
    }
};