class Solution {
public:
    vector<vector<int>> solve(int idx, vector<int>& nums) {
        // Base case
        if (idx == nums.size()) {
            return {{}};
        }

        // Take current element
        vector<vector<int>> taken = solve(idx + 1, nums);

        for (auto &it : taken) {
            it.push_back(nums[idx]);
        }

        // Don't take current element
        vector<vector<int>> notTaken = solve(idx + 1, nums);

        // Combine both
        vector<vector<int>> ans = taken;

        for (auto &it : notTaken) {
            ans.push_back(it);
        }

        return ans;
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        return solve(0, nums);
    }
};