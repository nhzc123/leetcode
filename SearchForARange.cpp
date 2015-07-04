/**
 * @file SearchForARange.cpp
 * @brief
 * @author charles.nhzc@gmail.com
 * @version 1.0.0
 * @date 2014-09-04
 */

class Solution {
private:
int begin = -1;
int end = -1;
     void binarySearch(int A[], int target, int left, int right){
        if (left > right){
            return ;
        }
        int mid = (left + right) >> 1;
        if (A[mid] == target){
            if (begin > mid || begin == -1){
                begin = mid;
            }
            if (end < mid ){
                end = mid;
            }
            binarySearch(A, target, left, mid -1);
            binarySearch(A, target, mid + 1, right);


        }
        else if (A[mid] < target){
            binarySearch(A, target, mid + 1, right);
        }
        else{
            binarySearch(A, target, left, mid - 1);
        }
    }


public:
    vector<int> searchRange(int A[], int n, int target) {
        begin = end = -1;
        binarySearch(A, target, 0, n - 1);
        vector<int> ans;
        ans.push_back(begin);
        ans.push_back(end);
        return ans;
    }


};
