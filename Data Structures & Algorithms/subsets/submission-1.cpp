class Solution {
public:

    vector<vector<int>> solve(int idx,vector<int> &nums){
        if(idx == nums.size()){
            return {{}};
        }


        vector<vector<int>> taken = solve(idx+1,nums);
        for(auto &it:taken){
            // cout << nums[idx] << " " <<endl;
            it.push_back(nums[idx]);
        }
        vector<vector<int>> ans = taken;
        vector<vector<int>> notTaken = solve(idx+1,nums);
        for(auto it:notTaken){
            ans.push_back(it);
        }
        return ans;
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        return solve(0,nums);
    }
};
