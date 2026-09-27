class Solution {
public:

    vector<vector<int>> solve(int idx, vector<int>& nums, int target) {

        // Target reached
        if (target == 0) {
            return {{}};
        }

        // Invalid case
        if (idx == nums.size() || target < 0) {
            return {};
        }

        // TAKE
        vector<vector<int>> taken =
            solve(idx, nums, target - nums[idx]);

        for (auto &it : taken) {
            it.push_back(nums[idx]);
        }

        // NOT TAKE
        vector<vector<int>> notTaken =
            solve(idx + 1, nums, target);

        // Combine
        vector<vector<int>> ans = taken;

        for (auto &it : notTaken) {
            ans.push_back(it);
        }

        return ans;
    }

    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        return solve(0, nums, target);
    }
};