/**
 * @file SearchA2DMatrix.cpp
 * @brief
 * @author nhzc   charles.nhzc@gmail.com
 * @version 1.0.0
 * @date 2014-09-24
 */

class Solution {
public:
    bool searchMatrix(vector<vector<int> > &matrix, int target) {
        int start = 0;
        int end = 0;
        if (matrix.size() != 0){
             end = matrix.size() * matrix[0].size() - 1;
        }
        else{
            return false;
        }
        while (start <= end){
            int mid = (start + end) / 2 ;
            int row = mid / matrix[0].size();
            int col = mid % matrix[0].size();
            if (matrix[row][col] == target){
                return true;
            }
            else if (matrix[row][col] < target){
                start = mid + 1;
            }
            else{
                end = mid - 1;
            }
        }
        return false;
    }
};
