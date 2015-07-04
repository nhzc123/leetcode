/**
 * @file DungeonGame.cpp
 * @brief
 * @author nhzc   charles.nhzc@gmail.com
 * @version 1.0.0
 * @date 2015-04-19
 */
#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
//http://www.tuicool.com/articles/E7zqQzE
//正向求解比较困难，可以定义dp[i][j] 表示从i,j 到最后所需要的血量，可以得到
//dp[i][j] = max(min(dp[i+1][j],dp[i][j+1]) - dungeon[i][j], 0)

    int calculateMinimumHP(vector<vector<int> > &dungeon) {
        int m = dungeon.size();
        int n = dungeon[0].size();
        int **dp = new int *[m];
        for(int i =0; i < m; i ++){
            dp[i] = new int[n];
        }
        //memset(dp, 0, sizeof(dp));
        dp[m - 1][n - 1] = max(0 - dungeon[m - 1][n - 1], 0);
        for (int i = m - 2; i >= 0; i --){
            dp[i][n - 1] = max(dp[i + 1][n - 1] - dungeon[i][n - 1], 0);
        }
        for (int j = n - 2; j >= 0; j --){
            dp[m - 1][j] = max(dp[m - 1][j + 1] - dungeon[m - 1][j], 0);
        }
        for (int i = m - 2; i >= 0; i --){
            for (int j = n - 2; j>= 0; j --){
                dp[i][j] = max(min(dp[i + 1][j], dp[i][j + 1]) - dungeon[i][j], 0);
            }
        }
        return dp[0][0] + 1;
    }
};

int main(){
vector<int> tem;
tem.push_back(0);
vector<vector<int>> result;
result.push_back(tem);
cout<<calculateMinimumHP(result)<<endl;
return 0;

}
