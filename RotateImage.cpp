/**
 * @file RotateImage.cpp
 * @brief
 * @author nhzc   charles.nhzc@gmail.com
 * @version 1.0.0
 * @date 2014-09-24
 */

class Solution {
public:
    void rotate(vector<vector<int> > &matrix) {
        int n = matrix.size();
        //沿着正对角线反转一次 再对着水平线反转一次
        for (int i = 0; i < n; i ++){//对着正对角线反转
            for (int j = 0; j < n - i; j ++){
                swap(matrix[i][j], matrix[n - j - 1][n - i - 1]);
            }
        }
        for (int i = 0; i < n /2; i ++){//对着水平线转一次
            for (int j = 0; j < n; j ++){
                swap(matrix[i][j], matrix[n - i - 1][j]);
            }
        }
    }
};
