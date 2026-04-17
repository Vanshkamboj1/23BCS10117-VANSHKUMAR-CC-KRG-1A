class Solution {
public:
    int solve(int i, vector<int>& arr, int k, vector<int>& dp) {
        int n = arr.size();
        if (i == n) return 0;

        if (dp[i] != -1) return dp[i];

        int maxi = 0;
        int ans = 0;

        for (int len = 1; len <= k && i + len <= n; len++) {
            maxi = max(maxi, arr[i + len - 1]);
            ans = max(ans, maxi * len + solve(i + len, arr, k, dp));
        }

        return dp[i] = ans;
    }

    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int> dp(n, -1);
        return solve(0, arr, k, dp);
    }
};