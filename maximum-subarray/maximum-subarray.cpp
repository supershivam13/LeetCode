int dp[100001];


class Solution {
public:
    int maxSubArray(vector<int>& a) {
        
        int n=a.size();
        
         int z = 0;

         dp[0] = 0;
        
        for(int i=1;i<= n;i++) {
        // a[i] will always be there, adding the dp[i-1] only if it is greater than 0
        dp[i] = max(dp[i - 1], z) + a[i-1];
    }

    int result = *max_element(dp + 1, dp + n + 1);
        
        
        return result;
        
        
    }
};