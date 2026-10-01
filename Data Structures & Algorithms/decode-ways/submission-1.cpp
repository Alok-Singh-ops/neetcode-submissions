#include<cstring>
class Solution {
public:
    int t[101];
    int solve(int idx, string &s) {
        if (idx == s.length())
            return 1;

        // 0 cannot be decoded by itself
        if (s[idx] == '0')
            return 0;
        
        if(t[idx] != -1) return t[idx];

        // Take one character
        int oneChar = solve(idx + 1, s);

        // Take two characters
        int twoChar = 0;

        if (idx + 1 < s.length() &&
            (s[idx] == '1' ||
             (s[idx] == '2' && s[idx + 1] <= '6'))) {

            twoChar = solve(idx + 2, s);
        }

        return t[idx] = oneChar + twoChar;
    }

    int numDecodings(string s) {
        memset(t,-1,sizeof(t));
        return solve(0, s);
    }
};