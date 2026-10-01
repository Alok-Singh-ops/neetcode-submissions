class Solution {
public:
    int solve(int idx, vector<int>& coins, int amount,
              vector<vector<int>>& dp) {

        if (amount == 0)
            return 0;

        if (idx == coins.size())
            return INT_MAX;

        if (dp[idx][amount] != -1)
            return dp[idx][amount];

        int taken = INT_MAX;

        if (coins[idx] <= amount) {
            int result = solve(idx, coins, amount - coins[idx], dp);

            if (result != INT_MAX)
                taken = 1 + result;
        }

        int notTaken = solve(idx + 1, coins, amount, dp);

        return dp[idx][amount] = min(taken, notTaken);
    }

    int coinChange(vector<int>& coins, int amount) {
        vector<vector<int>> dp(
            coins.size(),
            vector<int>(amount + 1, -1)
        );

        int ans = solve(0, coins, amount, dp);

        return ans == INT_MAX ? -1 : ans;
    }
};