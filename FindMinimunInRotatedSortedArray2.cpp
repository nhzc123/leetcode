/**
 * @file FindMinimunInRotatedSortedArray2.cpp
 * @brief
 * @author nhzc   charles.nhzc@gmail.com
 * @version 1.0.0
 * @date 2015-04-23
 */
class Solution {
public:
    int findMin(vector<int> &num) {
         int minNum = INT_MAX;
        int length = num.size();
        int left = 0;
        int right = length - 1;

        while (left <= right){
            int mid = left + (right - left) / 2;

            if (num[mid] < minNum){
                minNum = num[mid];
            }
            while (left <= right && num[left] == num[right] && num[left] == num[mid]){
                left ++;
                right --;
                mid = left + (right - left) / 2;
            }
            if (left > right){
                break;
            }
            if (num[left] <= num[mid] && num[right] >= num[mid]){
                return min(minNum, num[left]);
            }
            else if (num[left] <= num[mid] && num[right] <= num[mid]){
                left = mid + 1;
            }
            else if (num[left] >= num[mid] && num[right] >= num[mid]){
                right = mid - 1;
            }

        }

        return minNum;

    }
};
