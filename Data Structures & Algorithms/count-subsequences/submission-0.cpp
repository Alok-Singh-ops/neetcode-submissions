class Solution {
    vector<vector<int>> dp;
public:
    int numDistinct(string s, string t) {
        int m = s.size(), n = t.size();
        if (n > m) return 0;
        dp.assign(m + 1, vector<int>(n + 1, -1));
        return dfs(s, t, 0, 0);
    }

private:
    int dfs(const string &s, const string &t, int i, int j) {
        if (j == t.size()) return 1;
        if (i == s.size()) return 0;
        if (dp[i][j] != -1) return dp[i][j];

        int res = dfs(s, t, i + 1, j);
        if (s[i] == t[j]) {
            res += dfs(s, t, i + 1, j + 1);
        }
        dp[i][j] = res;
        return res;
    }
};