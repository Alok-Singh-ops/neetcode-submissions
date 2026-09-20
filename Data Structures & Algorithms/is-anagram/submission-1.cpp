class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char,int> sFreq,tFreq;
        for(auto it: t){
            tFreq[it]++;
        }
        for(auto it: s){
            sFreq[it]++;
        }
        if(sFreq == tFreq)
            return true;
        return false;
    }
};
