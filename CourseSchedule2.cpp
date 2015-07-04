/**
 * @file CourseSchedule2.cpp
 * @brief
 * @author nhzc   charles.nhzc@gmail.com
 * @version 1.0.0
 * @date 2015-05-16
 */
class Solution {
public:
    vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<int> result;
        bool *flag = new bool [numCourses];
        for (int i = 0; i < numCourses; i ++){
            flag[i] = false;
        }
        if (numCourses == 0){
            return result;
        }
        map<int, int> inDegree;
        map<int, vector<int> > paths;
        int first, second;
        for (int i = 0; i < prerequisites.size(); i ++){
            first = prerequisites[i].first;
            second = prerequisites[i].second;
            if (inDegree.find(first) != inDegree.end()){
                inDegree[first] ++;
            }
            else{
                inDegree[first] = 1;
                flag[first] = true;
            }
            if (paths.find(second) != paths.end()){
                paths[second].push_back(first);
            }
            else{
                vector<int> v;
                v.push_back(first);
                paths[second] = v;
            }
        }
        queue<int> q;
        for (int i = 0; i < numCourses; i ++){
            if (!flag[i]){
                q.push(i);
            }
        }
        int index;
        while (!q.empty()){
            index = q.front();
            result.push_back(index);
            q.pop();
            for (int i = 0 ; i < paths[index].size(); i ++){
                inDegree[paths[index][i]] --;
                if (inDegree[paths[index][i]] == 0){
                    q.push(paths[index][i]);
                }
            }
        }
        if (result.size() == numCourses){
            return result;
        }
        else{
            vector<int> tem;
            return tem;
        }

    }
};
