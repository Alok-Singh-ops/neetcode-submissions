/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */
class Solution {
public:
    bool canAttendMeetings(vector<Interval>& intervals) {
        map<int,int> mp;
        for (auto &&i : intervals)
        {
            mp[i.start]++;
            mp[i.end]--;
            int sum = 0;
            for (auto &&it : mp)
            {
                sum += it.second;
                if (sum > 1)
                {
                    mp[i.start]--;
                    mp[i.end]++;
                    return false;
                }
                
            }
            
        }
        return true;
    }
};