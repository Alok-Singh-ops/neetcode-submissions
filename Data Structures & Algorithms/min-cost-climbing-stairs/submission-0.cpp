class Solution {
public:

    int solve(int idx, vector<int>& cost, vector<int>& dp) {
        if (idx >= cost.size())
            return 0;

        if (dp[idx] != -1)
            return dp[idx];

        int oneStep = solve(idx + 1, cost, dp);
        int twoStep = solve(idx + 2, cost, dp);

        return dp[idx] = cost[idx] + min(oneStep, twoStep);
    }

    int minCostClimbingStairs(vector<int>& cost) {
        vector<int> dp(cost.size(), -1);

        return min(
            solve(0, cost, dp),
            solve(1, cost, dp)
        );
    }
};