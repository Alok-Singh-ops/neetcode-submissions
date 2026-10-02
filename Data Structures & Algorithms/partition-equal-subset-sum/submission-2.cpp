#include<cstring>
class Solution {
public:
    int dp[101][2501];
    bool solve(int idx, vector<int>& nums, int sum) {
        if (sum == 0)
            return true;

        if (idx >= nums.size())
            return false;
        if(dp[idx][sum] != -1) return dp[idx][sum];
        bool taken = false;

        if (nums[idx] <= sum) {
            taken = solve(idx + 1, nums, sum - nums[idx]);
        }

        bool notTaken = solve(idx + 1, nums, sum);

        return dp[idx][sum] = taken || notTaken;
    }

    bool canPartition(vector<int>& nums) {
        int sum = 0;

        for (auto it : nums) {
            sum += it;
        }

        if (sum % 2 != 0)
            return false;
            memset(dp,-1,sizeof(dp));

        return solve(0, nums, sum / 2);
    }
};