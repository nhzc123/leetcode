/**
 * @file PascalTriangle2.cpp
 * @brief
 * @author charles.nhzc@gmail.com
 * @version 1.0.0
 * @date 2014-09-07
 */
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> result;
        result.push_back(1);
        if (rowIndex == 0){
            return result;
        }

        for (int i = 0; i < rowIndex; i ++){
            int length = result.size() - 1;

            for (int i = length; i > 0; i --){
                result[i] += result[i - 1];
            }
            result.push_back(1);
        }

        return result;
    }
};
