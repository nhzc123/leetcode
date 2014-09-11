/**
 * @file SpiralMatrix.cpp
 * @brief
 * @author charles.nhzc@gmail.com
 * @version 1.0.0
 * @date 2014-09-07
 */

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int> > &matrix) {
        vector<int> result;
        if (matrix.size() == 0){
            return result;
        }
        int x1 = 0, y1 = 0;
        int x2 = matrix[0].size() - 1;
        int y2 = matrix.size() - 1;

        while (x1 <= x2 && y1 <= y2){

            //up row
            for(int i = x1; i <= x2; i ++){
                result.push_back(matrix[y1][i]);
            }
            //right column
            for (int i = y1 + 1; i <= y2; i ++){
                result.push_back(matrix[i][x2]);
            }
            //bottom row
            if (y1 != y2)
            for (int i = x2 - 1; i >= x1; i --){
                result.push_back(matrix[y2][i]);
            }
            //left column
            if (x1 != x2)
            for (int i = y2 - 1; i > y1; i --){
                result.push_back(matrix[i][x1]);
            }

            x1 ++;
            y1 ++;
            x2 --;
            y2 --;
        }

        return result;
    }
};
