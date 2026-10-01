#include <cstring> 
class Solution {
public:
    int t[46];
    int solve(int idx,int n){
        if(idx == n) return 1;
        if(idx > n) return 0;
        if(t[idx] != -1) return t[idx];

        int oneStep = solve(idx+1,n);
        int twoStep = solve(idx+2,n);

        return t[idx] = oneStep + twoStep;
    }


    int climbStairs(int n) {
        memset(t,-1,sizeof(t));
        return solve(0,n);
    }
};
