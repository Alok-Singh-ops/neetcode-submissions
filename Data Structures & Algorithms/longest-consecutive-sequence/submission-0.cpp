class Solution {
public:

    

    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> st;
        int ans = 0;

        for (int x : nums) {
            st.insert(x);
        }
        for(int it:nums){
            //is it starting point
            if(st.find(it-1) == st.end()){
                int curr = it;
                int cnt = 1;
                while(st.find(curr+1) != st.end()){
                    curr += 1;
                    cnt++;
                }
                ans = max(ans,cnt);
            }
        }
        return ans;
    }
};
