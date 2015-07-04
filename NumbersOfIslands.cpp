/**
 * @file NumbersOfIslands.cpp
 * @brief
 * @author nhzc   charles.nhzc@gmail.com
 * @version 1.0.0
 * @date 2015-04-19
 */
class Solution {
public:
//obviously, dfs
    bool dfs(int i, int j, vector<vector<char>> &grid){
        if (i >= 0 && i < grid.size() && j >= 0 && j < grid[i].size() && grid[i][j] == '1'){
            grid[i][j] = '3';
            dfs(i + 1, j, grid);
            dfs(i - 1, j, grid);
            dfs(i, j + 1, grid);
            dfs(i, j - 1, grid);
            return true;
        }
        return false;
    }
    int numIslands(vector<vector<char>> &grid) {
        int result = 0;
        for (int i = 0; i < grid.size(); i ++){
            for (int j = 0;j < grid[i].size(); j ++){
                if (dfs(i, j, grid)){
                    result ++;
                }
            }
        }
        return result;

    }
};
