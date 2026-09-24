class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> need;

        for (char c : t) {
            need[c]++;
        }

        int l = 0;
        int count = 0;
        int minLen = INT_MAX;
        int start = 0;

        for (int r = 0; r < s.length(); r++) {

            // Current character is needed
            if (need[s[r]] > 0) {
                count++;
            }

            need[s[r]]--;

            // Window is valid
            while (count == t.length()) {

                // Update answer
                if (r - l + 1 < minLen) {
                    minLen = r - l + 1;
                    start = l;
                }

                // Remove left character
                need[s[l]]++;

                // We removed a required character
                if (need[s[l]] > 0) {
                    count--;
                }

                l++;
            }
        }

        if (minLen == INT_MAX) {
            return "";
        }

        return s.substr(start, minLen);
    }
};