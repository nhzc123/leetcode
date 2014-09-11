/**
 * @file SurroundedRegions.cpp
 * @brief
 * @author nhzc   charles.nhzc@gmail.com
 * @version 1.0.0
 * @date 2014-09-10
 */
class Solution {
public:
    const int moveX[4] = {0, 0, -1, 1};
    const int moveY[4] = {-1, 1, 0, 0};
    void bfs(vector<vector<char>>& board, vector<vector<int>>& visited, queue<pair<int, int>>& q){
        while (!q.empty()){
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            //遍历每个O的四个方向
            for (int i = 0; i < 4; i ++){
                int tmpX = x + moveX[i];
                int tmpY = y + moveY[i];
                if (tmpX < 0 || tmpX >= board.size() || tmpY < 0 || tmpY >= board[0].size()){
                    continue;
                }
                if (board[tmpX][tmpY] == 'X'){
                    continue;
                }
                if (visited[tmpX][tmpY]){
                    continue;
                }
                visited[tmpX][tmpY] = 1;
                q.push(make_pair(tmpX, tmpY));
            }
        }
    }
    void solve(vector<vector<char>> &board) {
        //跟边界接壤的0全部都不用搜索，所以可以用bfs将上下左右四个边界放在队列中，如果跟0接壤的0则不用变换成X，用一个矩阵visited         //储存访问状态
        if (board.size() == 0){
            return ;
        }
        vector<vector<int>> visited(board.size(), vector<int> (board[0].size(), 0));
        queue<pair<int, int>> q;
        //左边界 右边界
        for (int i = 0; i < board[0].size(); i ++){
            if (board[0][i] != 'X' && visited[0][i] != 1){
                visited[0][i] = 1;
                q.push(make_pair(0, i));
            }
            if (board[board.size() - 1][i] != 'X' && visited[board.size() - 1][i] != 1){
                visited[board.size() - 1][i] = 1;
                q.push(make_pair(board.size() - 1, i));
            }
        }
        //上边界 下边界
        for (int i = 0; i < board.size(); i ++){
            if (board[i][0] != 'X' &&  visited[i][0] != 1){
                visited[i][0] = 1;
                q.push(make_pair(i, 0));
            }
            if (board[i][board[0].size() - 1] != 'X' && visited[i][board[0].size() - 1] != 1){
                visited[i][board[0].size() - 1] = 1;
                q.push(make_pair(i, board[0].size() - 1));
            }
        }

        //对矩阵做一个bfs搜索
        bfs (board, visited, q);

        for (int i = 0; i < board.size(); i ++){
            for (int j = 0; j < board[0].size(); j ++){
                board[i][j] = (visited[i][j] == 0) ? 'X':'O';
            }
        }


    }
};
