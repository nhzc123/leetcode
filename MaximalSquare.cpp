/**
 * @file MaximalSquare.cpp
 * @brief
 * @author nhzc   charles.nhzc@gmail.com
 * @version 1.0.0
 * @date 2015-06-04
 */
class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int rows = matrix.size();
        if (rows == 0){
            return 0;
        }
        int cols = matrix[0].size();
        if (cols == 0){
            return 0;
        }
        vector<int> tem(cols, 0);
        vector<vector<int> > v(rows, tem);

        int maxValue = INT_MIN;
        for (int i = 0; i < rows; i ++){
            for (int j = 0; j < cols; j ++){
                v[i][j] = matrix[i][j] - '0';

            if (i != 0 && j != 0 && matrix[i][j] != '0'){
                v[i][j] = min(v[i - 1][j - 1], min(v[i - 1][j], v[i][j - 1])) + 1;
            }
            maxValue = max(maxValue, v[i][j]);
            }
        }
        return maxValue * maxValue;
    }
};
