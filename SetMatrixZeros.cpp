/**
 * @file SetMatrixZeros.cpp
 * @brief
 * @author nhzc   charles.nhzc@gmail.com
 * @version 1.0.0
 * @date 2014-09-19
 */

class Solution {
public:
    void setZeroes(vector<vector<int> > &matrix) {
        //可以利用matrix本身的存储空间，首先检查第一行和第一列是否有0，只有将其他行和其他列是否需要置换为0扫描一遍
        //最后再扫一遍改变matrix的内容
        bool rowsFlag = false;
        bool colsFlag = false;
        int lenOfRows = matrix.size();
        if (lenOfRows == 0){
            return ;
        }
        int lenOfCols = matrix[0].size();
        for (int i = 0; i < lenOfCols; i ++){
            if (matrix[0][i] == 0){
                colsFlag = true;
                break;
            }
        }
        for (int i = 0; i < lenOfRows; i ++){
            if (matrix[i][0] == 0){
                rowsFlag = true;
                break;
            }
        }
        //检查中间是否有0，有的话将状态修改到对应的第一行跟第一列
        for (int i = 1; i < lenOfRows; i ++){
            for (int j = 1; j < lenOfCols; j ++){
                if (matrix[i][j] == 0){
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }
        for (int i = 1; i < lenOfRows; i ++){
            if (matrix[i][0] == 0){
                for (int j = 1; j < lenOfCols; j ++){
                    matrix[i][j] = 0;
                }
            }
        }
        for (int i = 1; i < lenOfCols; i ++){
            if (matrix[0][i] == 0){
                for (int j = 1; j < lenOfRows; j ++){
                    matrix[j][i] = 0;
                }
            }
        }
        if (colsFlag){
            for (int i = 0; i < lenOfCols; i ++){
                matrix[0][i] = 0;
            }
        }
        if (rowsFlag){
            for (int i = 0; i < lenOfRows; i ++){
                matrix[i][0] = 0;
            }
        }
        return ;
    }
};
