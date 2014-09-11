/**
 * @file SpiralMatrix2.cpp
 * @brief
 * @author charles.nhzc@gmail.com
 * @version 1.0.0
 * @date 2014-09-07
 */
class Solution {
public:
    vector<vector<int> > generateMatrix(int n) {
        vector<int> tmp(n, 0);
        vector<vector<int> > result(n, tmp);

        int x1 = 0, y1 = 0;
        int x2 = n - 1, y2 = n - 1;
        int count = 1;

        while (x1 <= x2 && y1 <= y2){

            //up row
            for (int i = x1; i <= x2; i ++){
                result[y1][i] = count ++;
            }
            //right column
            for (int i = y1 + 1; i <= y2; i ++){
                result[i][x2] = count ++;
            }
            //bottom row
            if (y1 != y2){
                for (int i = x2 - 1; i >= x1; i --){
                    result[y2][i] = count ++;
                }
            }
            //left column
            if (x1 != x2){
                for (int i = y2 - 1; i >= y1 + 1; i --){
                    result[i][x1] = count ++;
                }
            }

            x1 ++;
            x2 --;
            y1 ++;
            y2 --;
        }

        return result;

    }
};
