#include<cstring>
class Solution {
public:
    int t[1001][1001];
    int solve(int i,int j,string text1,string text2){
        if (i == text1.size() || j == text2.size())
            return 0;

        if(t[i][j] != -1) return t[i][j];

        int matched = INT_MIN;
        if(text1[i] == text2[j])
            matched = 1+ solve(i+1,j+1,text1,text2);
        int notMatched = max(solve(i+1,j,text1,text2),solve(i,j+1,text1,text2));

        return t[i][j] = max(matched,notMatched);
    }

    int longestCommonSubsequence(string text1, string text2) {
        memset(t,-1,sizeof (t));
        return solve(0,0,text1,text2);
    }
};
