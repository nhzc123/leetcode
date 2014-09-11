/**
 * @file SearchInRotatedSortedArray2.cpp
 * @brief
 * @author charles.nhzc@gmail.com
 * @version 1.0.0
 * @date 2014-09-05
 */

class Solution {
public:
    bool search(int A[], int n, int target) {
        int left = 0;
        int right = n - 1;

        while (left <= right){
            int mid = (left - right) / 2 + right;

            if (A[mid] == target){
                return true;
            }
            if (A[left] == A[mid] && A[right] == A[mid]){
                left ++;
                right --;
            }
            else if (A[left] <= A[mid]){
                if (A[left] <= target && A[mid] > target){
                    right = mid - 1;
                }
                else{
                    left = mid + 1;
                }
            }
            else{
                if (A[mid] < target && A[right] >= target){
                    left = mid + 1;
                }
                else{
                    right = mid - 1;
                }
            }
        }

        return false;
    }
};
