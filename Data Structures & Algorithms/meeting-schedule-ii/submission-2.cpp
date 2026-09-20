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



/*
    

    0




*/


class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        map<int,int> mp;
        int answer = 0;
        for(auto &[start,end]:intervals){
            mp[start]++;
            mp[end]--;
        }
             int runningSum = 0;
        for(auto &[key,value]:mp){
            runningSum += value;
            answer = max(runningSum,answer);
        }
    return answer;
    }



};
