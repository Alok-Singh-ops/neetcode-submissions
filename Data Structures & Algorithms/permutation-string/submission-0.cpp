class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        unordered_map<char,int> s1Freq,s2Freq;
        int requiredWindowSize = s1.length();
        for(auto it: s1){
            s1Freq[it]++;
        }
        int l = 0;
        for(int r = 0;r<s2.length();r++){
            s2Freq[s2[r]]++;
            if(r-l+1 > requiredWindowSize){
                s2Freq[s2[l]]--;
                 if(s2Freq[s2[l]] == 0){
                    s2Freq.erase(s2[l]);
                }
                l++;
            }
            if(r-l+1 == requiredWindowSize){
                if(s2Freq == s1Freq ){
                    return true;
                }
            }

        }
return false;
    }
};
