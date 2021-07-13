int dp[101][101];

class Solution {
public:
    int uniquePaths(int n, int m) {
        
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(i==n or j==m)
                    dp[i][j]=1;
            }
        }
        
        for(int i=n-1;i>=1;i--){
            for(int j=m-1;j>=1;j--){
                dp[i][j]=dp[i+1][j]+dp[i][j+1];
            }
        }
        
        return dp[1][1];
        
        
    }
};