class Solution {
public:
    int maxProduct(vector<int>& nums) {
        vector<vector<int>> A;
        vector<int> cur;
        int res = INT_MIN;
        for (auto& num : nums) {
            res = max(res, num);
            if (num == 0) {
                if (!cur.empty()) A.push_back(cur);
                cur.clear();
            } else cur.push_back(num);
        }
        if (!cur.empty()) {
            A.push_back(cur);
        }

        for (auto& sub : A) {
            int negs = 0;
            for (auto& i : sub) {
                if (i < 0) negs++;
            }

            int prod = 1;
            int need = (negs % 2 == 0) ? negs : (negs - 1);
            negs = 0;
            for (int i = 0, j = 0; i < sub.size(); i++) {
                prod *= sub[i];
                if (sub[i] < 0) {
                    negs++;
                    while (negs > need) {
                        prod /= sub[j];
                        if (sub[j] < 0) negs--;
                        j++;
                    }
                }
                if (j <= i) res = max(res, prod);
            }
        }
        return res;
    }
};