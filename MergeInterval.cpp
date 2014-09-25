/**
 * @file MergeInterval.cpp
 * @brief
 * @author nhzc   charles.nhzc@gmail.com
 * @version 1.0.0
 * @date 2014-09-16
 */

/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    void insertInterval(vector<Interval> &result, Interval newIntervals){
        vector<Interval>::iterator iter = result.begin();
        while(iter != result.end()){
            if (iter -> start > newIntervals.end){
                result.insert(iter, newIntervals);
                return ;
            }
            else if (iter -> end < newIntervals.start){
                iter ++;
                continue;
            }
            else{
                newIntervals.start = min(newIntervals.start, iter -> start);
                newIntervals.end = max(newIntervals.end, iter -> end);
                iter = result.erase(iter);
            }
        }
        result.insert(result.end(), newIntervals);
        return ;
    }
    //采用insert interval中的方法，每次从集合中拿一个进去新集合里合并
    vector<Interval> merge(vector<Interval> &intervals) {
        vector<Interval> result;
        int len = intervals.size();
        for (int i = 0; i < len; i ++){
            insertInterval(result, intervals[i]);
        }
        return result;
    }
};
