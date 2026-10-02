class Solution {
    vector<vector<int>> dp;
    int totalSum;

public:
    int findTargetSumWays(vector<int>& nums, int target) {
        totalSum = accumulate(nums.begin(), nums.end(), 0);
        dp = vector<vector<int>>(nums.size(), vector<int>(2 * totalSum + 1, INT_MIN));
        return backtrack(0, 0, nums, target);
    }

    int backtrack(int i, int total, vector<int>& nums, int target) {
        if (i == nums.size()) {
            return total == target;
        }
        if (dp[i][total + totalSum] != INT_MIN) {
            return dp[i][total + totalSum];
        }
        dp[i][total + totalSum] = backtrack(i + 1, total + nums[i], nums, target) +
                                  backtrack(i + 1, total - nums[i], nums, target);
        return dp[i][total + totalSum];
    }
};