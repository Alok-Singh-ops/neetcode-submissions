class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<pair<int,int>> st;
        int n = temperatures.size();

        vector<pair<int,int>> vec(n);

        for(int i = n - 1; i >= 0; i--) {

            while(!st.empty() && st.top().first <= temperatures[i]) {
                st.pop();
            }

            if(st.empty()) {
                vec[i] = {-1, 0};
            }
            else {
                vec[i] = st.top();
            }

            st.push({temperatures[i], i});
        }

        vector<int> ans(n);

        for(int i = 0; i < n; i++) {
            if(vec[i].first == -1) {
                ans[i] = 0;
            }
            else {
                ans[i] = vec[i].second - i;
            }
        }

        return ans;
    }
};