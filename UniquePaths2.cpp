/**
 * @file UniquePaths2.cpp
 * @brief
 * @author charles.nhzc@gmail.com
 * @version 1.0.0
 * @date 2014-09-04
 */

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
        int dp[101][101];
        if (obstacleGrid[0][0] == 1 ){
            return 0;
        }
        dp[0][0] = 1;

        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();

        if (obstacleGrid[m - 1][n - 1] == 1){
            return 0;
        }

        for (int i = 1; i < m; i ++){
            if (obstacleGrid[i][0] == 0){
                dp[i][0] = dp[i - 1][0];
            }
            else{
                dp[i][0] = 0;
            }
        }

        for (int j = 1; j < n; j ++){
            if ( obstacleGrid[0][j] == 0){
                dp[0][j] = dp[0][j - 1];

            }
            else{
                dp[0][j] = 0;
            }
        }

        for (int i = 1; i < m; i ++){
            for (int j = 1; j < n; j ++){
                if (obstacleGrid[i][j] == 1){
                    dp[i][j] = 0;
                }
                else{
                    dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
                }
            }
        }

        return dp[m - 1][n - 1];

    }
};
