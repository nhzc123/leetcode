/**
 * @file WordLadder.cpp
 * @brief
 * @author charles.nhzc@gmail.com
 * @version 1.0.0
 * @date 2014-09-09
 */

class Solution {
public:
    int ladderLength(string start, string end, unordered_set<string> &dict) {
        //直接bfs广度优先搜索，使用队列就OK了
        unordered_map<string, int> distance;
        queue<string> q;
        q.push(start);
        distance[start] = 1;
        //bfs
        while (!q.empty()){
            string cur = q.front();
            q.pop();
            //对于每一个单词，循环遍历它的所有可能单个位置的变化，如果在dict存在，则放入队列当中
            for (int i = 0; i < cur.length(); i ++){
                //对于每个位置，遍历26个字母
                for (char w = 'a'; w <= 'z'; w ++){
                    string next = cur;
                    next[i] = w;
                    if (dict.find(next) == dict.end() || distance.find(next) != distance.end()){
                        continue;
                    }
                    distance[next] =  distance[cur] + 1;
                    q.push(next);
                }
            }
        }
        return distance[end];
    }
};
