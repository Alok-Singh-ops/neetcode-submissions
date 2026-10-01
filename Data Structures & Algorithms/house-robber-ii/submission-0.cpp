class Solution {
public:

    int solve(int idx, vector<int>& nums, vector<int>& dp) {
        if (idx >= nums.size())
            return 0;

        if (dp[idx] != -1)
            return dp[idx];

        int taken = nums[idx] + solve(idx + 2, nums, dp);
        int notTaken = solve(idx + 1, nums, dp);

        return dp[idx] = max(taken, notTaken);
    }

    int rob(vector<int>& nums) {
        int n = nums.size();

        if (n == 1)
            return nums[0];

        // Case 1: Remove first house
        vector<int> case1(nums.begin() + 1, nums.end());

        // Case 2: Remove last house
        vector<int> case2(nums.begin(), nums.end() - 1);

        vector<int> dp1(case1.size(), -1);
        vector<int> dp2(case2.size(), -1);

        return max(
            solve(0, case1, dp1),
            solve(0, case2, dp2)
        );
    }
};