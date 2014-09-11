/**
 * @file SearchInRotatedSortedArray.cpp
 * @brief
 * @author charles.nhzc@gmail.com
 * @version 1.0.0
 * @date 2014-09-05
 */

class Solution {
public:
    int search(int A[], int n, int target) {
        //变异的二分查找
        int left = 0;
        int right = n - 1;

        while (left <= right){
            int mid = (left - right) / 2 + right;

            if (A[mid] == target){
                return mid;
            }
            //左边有序
            else if (A[left] < A[mid]){
                if (A[left] <= target && target < A[mid]){
                    right = mid - 1;
                }
                else{
                    left = mid + 1;
                }
            }
            //右边有序
            else{
                if (A[mid] < target && target <= A[right]){
                    left = mid + 1;
                }
                else{
                    right = mid - 1;
                }
            }
        }

        return -1;
    }
};
