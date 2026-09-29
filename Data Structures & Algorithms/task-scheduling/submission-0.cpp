static const int _ = [](){ios_base::sync_with_stdio(false);cin.tie(NULL);return 0;}();
class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int freq[26] = {};
        for (char c : tasks) freq[c - 'A']++;
        int maxF = *max_element(freq, freq + 26);
        int cnt = count(freq, freq + 26, maxF);
        return max((int)tasks.size(), (maxF - 1) * (n + 1) + cnt);
    }
};