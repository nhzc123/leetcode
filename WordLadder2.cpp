/**
 * @file WordLadder2.cpp
 * @brief
 * @author nhzc   charles.nhzc@gmail.com
 * @version 1.0.0
 * @date 2014-09-10
 */
class Solution {
public:
    void bfs(string& start, map<string, int>& dis, unordered_set<string>& dict){
        dis[start] = 0;
        queue<string> q;
        q.push(start);
        while (!q.empty()){
            string cur = q.front();
            q.pop();
            for (int i = 0; i < cur.length(); i ++){
                for (char w = 'a'; w <= 'z'; w ++){
                    string next = cur;
                    next[i] = w;
                    //这里的查询顺序非常重要啊啊啊啊啊唉！！！！！！！
                    if (dict.find(next) == dict.end() || dis.find(next) != dis.end() ){
                        continue;
                    }
                    dis[next] = dis[cur] + 1;
                    q.push(next);
                }
            }
        }

    }
    void findPath(string& cur,vector<string>& path,  vector<vector<string>>& result, map<string, int>& dis){
        path.push_back(cur);
        if (dis[cur] == 0){
            vector<string> tmp(path);
            reverse(tmp.begin(), tmp.end());
            result.push_back(tmp);
        }
        else{
            //对于cur的每个位置循环变化
            for (int i = 0; i < cur.length(); i ++){
                for (char w = 'a'; w <= 'z'; w ++){
                    string next = cur;
                    next[i] = w;
                    if (dis.find(next) == dis.end() || dis[next] + 1 != dis[cur]){
                        continue;
                    }
                    findPath(next, path, result, dis);
                }
            }
        }
        path.pop_back();
    }
    vector<vector<string>> findLadders(string start, string end, unordered_set<string> &dict) {
        //可以利用第一步的结果 先用bfs记录出一个所有单词从start变化到end的步骤数
        //然后再使用dfs从end从后面往前面搜索，将路径变成1的路径记录下来
        map<string, int> dis;
        bfs(start, dis, dict);
        vector<vector<string>> result;
        vector<string> path;
        if (dis.find(end) != dis.end()){
            findPath(end, path, result, dis);
        }
        return result;
    }
};
