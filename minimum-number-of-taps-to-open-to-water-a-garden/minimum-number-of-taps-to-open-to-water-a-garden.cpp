class Solution {
public:
    int minTaps(int n, vector<int>& ranges) {
        vector<int> dp(n+1, -1);
        dp[0] = 0;
        for (int i = 1; i <= ranges[0]; ++i) {
            dp[i] = 1;
        }
        
        for (int i = 1; i < ranges.size(); ++i) {
            int start = std::max(0, i-ranges[i]);
            int end = std::min((int) ranges.size()-1, i+ranges[i]);
            if (dp[start] == -1) continue;
            int min_taps = dp[start];
            for (int j = start+1; j <= end; ++j) {
                if (dp[j] == -1) {
                    dp[j] = 1 + min_taps;
                } else {
                    dp[j] = std::min(dp[j], 1+min_taps);
                }
                min_taps = std::min(min_taps, dp[j]);
            }
        }
        return dp.back();
    }
};