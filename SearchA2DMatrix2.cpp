class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rows = matrix.size();
        if (rows == 0){
            return false;
        }
        int cols = matrix[0].size();
        //从右上角开始比较，如果比右上角的大　则去掉行，如果小，则去掉列
        int indexA = 0;
        int indexB = matrix[0].size() - 1;
        while (indexA < rows && indexB >= 0){
            if (matrix[indexA][indexB] > target){
                indexB --;
            }
            else if (matrix[indexA][indexB] < target){
                indexA ++;
            }
            else{
                return true;
            }
        }
        
        return false;
    }
};
