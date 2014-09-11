/**
 * @file PascalTriangle.cpp
 * @brief
 * @author charles.nhzc@gmail.com
 * @version 1.0.0
 * @date 2014-09-02
 */

class Solution {
public:
    vector<vector<int> > generate(int numRows) {
        vector<vector<int> > result;
        vector<int> tem;

        if (numRows == 0){
            return result;
        }



        for (int i = 0; i < numRows; i ++){
            tem.clear();
            for (int j = 0; j < i + 1; j ++){
                if (j == 0){
                    tem.push_back(1);
                }
                else if (j == i){
                    tem.push_back(1);
                }
                else{
                    tem.push_back(result[i - 1][j] + result[i - 1][j - 1]);
                }

            }
            result.push_back(tem);
        }

        return result;

    }
};
