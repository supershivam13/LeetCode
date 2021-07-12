class Solution {
public:
    int minPathSum(vector<vector<int>>& a) {
        
        int n=a.size();
        int m=a[0].size();
        
        // 1-based indexing and 1 extra row and column for base condition
        int dp[n+2][m+2];
        
        for(int i=1;i<=m+1;i++)
            dp[n+1][i]=INT_MAX;
        
        for(int i=1;i<=n+1;i++)
            dp[i][m+1]=INT_MAX;
        
        dp[n+1][m]=dp[n][m+1]=0;
        
        for(int i=n;i>=1;i--){
            for(int j=m;j>=1;j--){
                dp[i][j]=a[i-1][j-1]+min(dp[i+1][j],dp[i][j+1]);
            }
        }
        
        return dp[1][1];
        
    }
};