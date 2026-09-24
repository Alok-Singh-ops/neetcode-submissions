class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> st;

        int left = 0;
        int ans = 0;

        for (int right = 0; right < s.size(); right++) {

            // Duplicate found -> shrink from left
            while (st.find(s[right]) != st.end()) {
                st.erase(s[left]);
                left++;
            }

            // Add current character
            st.insert(s[right]);

            // Current window length
            ans = max(ans, right - left + 1);
        }

        return ans;
    }
};