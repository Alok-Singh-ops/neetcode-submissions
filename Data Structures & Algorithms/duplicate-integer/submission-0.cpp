class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_map<int,int> mp;
        for(auto it:nums){
            auto i = mp.find(it);
            if(i != mp.end()){
                return true;
            }
            else{
                mp[it]++;
            }
        }

        return false;
    }
};