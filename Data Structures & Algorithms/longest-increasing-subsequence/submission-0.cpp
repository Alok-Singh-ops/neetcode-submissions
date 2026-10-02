class Solution {
public:
    int solve(int idx, int prev, vector<int>& nums,
              vector<vector<int>>& dp) {

        if (idx == nums.size())
            return 0;

        if (dp[idx][prev + 1] != -1)
            return dp[idx][prev + 1];

        int taken = 0;

        if (prev == -1 || nums[idx] > nums[prev]) {
            taken = 1 + solve(idx + 1, idx, nums, dp);
        }

        int notTaken = solve(idx + 1, prev, nums, dp);

        return dp[idx][prev + 1] = max(taken, notTaken);
    }

    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();

        vector<vector<int>> dp(n, vector<int>(n + 1, -1));

        return solve(0, -1, nums, dp);
    }
};