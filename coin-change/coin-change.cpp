class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {

        // Initialising DP array with INT_MAX;
        long long int dp[amount + 1];
        for (int i = 0; i <= amount; i++)
            dp[i] = INT_MAX;

        dp[0] = 0;

        for (int i = 1; i <= amount; i++) {
            for (int j = 0; j < coins.size(); j++) {
                if (i - coins[j] >= 0)
                    dp[i] = min(dp[i], dp[i - coins[j]] + 1);
            }
        }

        if (dp[amount] == INT_MAX)
            return -1;
        else
            return dp[amount];
    }
};
