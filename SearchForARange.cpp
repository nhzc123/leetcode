/**
 * @file SearchForARange.cpp
 * @brief
 * @author charles.nhzc@gmail.com
 * @version 1.0.0
 * @date 2014-09-04
 */

class Solution {
public:
    vector<int> searchRange(int A[], int n, int target) {
        vector<int> result;
        bool flag = false;

        for (int i = 0; i < n; i ++){
            if (A[i] == target){
                if (!flag){
                    flag = true;
                    result.push_back(i);
                    result.push_back(i);
                }
                else{
                    result[1] = i;
                }
            }
        }

        if (flag){
            return result;
        }
        else{
            result.push_back(-1);
            result.push_back(-1);
            return result;
        }
    }
};
