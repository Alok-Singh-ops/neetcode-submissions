class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char, int> mp;

        int l = 0;
        int ans = 0;
        int maxFreq = 0;

        for (int r = 0; r < s.length(); r++) {

            mp[s[r]]++;

            maxFreq = max(maxFreq, mp[s[r]]);

            // Number of characters we need to replace
            // to make the whole window the same
            while ((r - l + 1) - maxFreq > k) {
                mp[s[l]]--;
                l++;
            }

            ans = max(ans, r - l + 1);
        }

        return ans;
    }
};