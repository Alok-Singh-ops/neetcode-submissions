class Solution {
public:
    vector<vector<int>> res;
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        res.clear();
        sort(candidates.begin(), candidates.end());
        vector<int> cur;
        dfs(candidates, target, 0, cur, 0);
        return res;
    }

private:
    void dfs(vector<int>& candidates, int target, int i, vector<int>& cur, int total) {
        if (total == target) {
            res.push_back(cur);
            return;
        }
        if (total > target || i == candidates.size()) {
            return;
        }

        cur.push_back(candidates[i]);
        dfs(candidates, target, i + 1, cur, total + candidates[i]);
        cur.pop_back();

        while (i + 1 < candidates.size() && candidates[i] == candidates[i + 1]) {
            i++;
        }
        dfs(candidates, target, i + 1, cur, total);
    }
};