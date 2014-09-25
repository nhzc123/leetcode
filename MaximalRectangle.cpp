/**
 * @file MaximalRectangle.cpp
 * @brief
 * @author nhzc   charles.nhzc@gmail.com
 * @version 1.0.0
 * @date 2014-09-15
 */

class Solution {
public:
    int largestRetcangleInHistogram(int *dp, int n){
        int result = 0;
        stack<int> s;
        dp[n - 1] = 0;
        for (int i = 0; i < n; ){
            if (s.empty() || dp[i] > dp[s.top()]){
                s.push(i ++);
            }
            else{
                int tmp = s.top();
                s.pop();
                result = max(result, dp[tmp] * (s.empty() ? i: i - s.top() - 1));
            }
        }
        return result;
    }
    int maximalRectangle(vector<vector<char> > &matrix) {
        //可以将一个二维矩阵降维成一个一行行的直方图http://blog.csdn.net/doc_sgl/article/details/11832965
        //每一行的直方图的高度都是该行以上的1的个数
        int rows = matrix.size();
        if (rows == 0){
            return 0;
        }
        int cols = matrix[0].size();
        if (cols == 0){
            return 0;
        }
        int **dp = new int *[rows];
        for (int i = 0; i < rows; i ++){
            dp[i] = new int [cols + 1];
            memset(dp[i], 0, sizeof(int) * (cols + 1));
        }
        //计算每一列向上数1的个数，建立直方图
        for (int i = 0; i < cols; i ++){
            if (matrix[0][i] == '1')
                dp[0][i] = 1;
        }
        for (int i = 1; i < rows; i ++){
            for (int j = 0; j < cols; j ++){
                if (matrix[i][j] == '1'){
                    dp[i][j] = dp[i - 1][j] + 1;
                }
            }
        }
        int result = 0;
        for (int i = 0; i < rows; i ++){
            result = max(result, largestRetcangleInHistogram(dp[i], cols + 1));
        }
        for (int i = 0; i < rows; i ++){
            delete [] dp[i];
        }
        delete [] dp;
        return result;
    }
};
