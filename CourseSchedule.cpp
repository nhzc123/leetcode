/**
 * @file CourseSchedule.cpp
 * @brief
 * @author nhzc   charles.nhzc@gmail.com
 * @version 1.0.0
 * @date 2015-05-07
 */

class Solution {
public:
    bool hasLoop(map<int, vector<int> > &table, const int &begin, vector<int> &path){
        if (table.count(begin) == 0){
            return false;
        }
        while (!table[begin].empty()){
            int temp = table[begin].back();
            if (find(path.begin(), path.end(), temp) != path.end()){
                return true;
            }
            path.push_back(temp);
            if (hasLoop(table, temp, path)){
                return true;
            }
            path.pop_back();
            table[begin].pop_back();
        }
        table.erase(begin);
        return false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        if (numCourses == 0 || numCourses == 1){
            return true;
        }
        if (prerequisites.size() == 0){
            return true;
        }

        map<int, vector<int> > m;
        for (auto &i : prerequisites){
            m[i[0]].push_back(i[1]);
        }
        vector<int> path;
        while (!m.empty()){
            auto it = m.begin();
            path.push_back(it->first);
            if (hasLoop(m, it->first, path)){
                return false;
            }
            path.pop_back();
        }
        return true;
    }
};
