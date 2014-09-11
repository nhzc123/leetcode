/**
 * @file Triangle.cpp
 * @brief
 * @author charles.nhzc@gmail.com
 * @version 1.0.0
 * @date 2014-09-01
 */

class Solution {
public:
    int minimumTotal(vector<vector<int> > &triangle) {
        int length = triangle.size();
        if (length == 0){
            return 0;
        }

        if (length == 1){
            return triangle[0][0];
        }

        for (int i = 1; i < length; i ++){
            for (int j = 0; j < triangle[i].size(); j ++){
                if (j == 0){
                    triangle[i][j] += triangle[i - 1][0];
                }
                else if (j == triangle[i].size() - 1){
                    triangle[i][j] += triangle[i - 1][j - 1];
                }
                else{
                    triangle[i][j] += min(triangle[i - 1][j], triangle[i - 1][j -1]);
                }
            }
        }

        int minLen = INT_MAX;

        for (int i = 0; i < triangle[length - 1].size(); i ++){
            minLen = min(minLen, triangle[length - 1][i]);
        }

        return minLen;
    }
};
