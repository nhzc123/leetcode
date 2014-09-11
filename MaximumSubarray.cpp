/**
 * @file MaximumSubarray.cpp
 * @brief
 * @author charles.nhzc@gmail.com
 * @version 1.0.0
 * @date 2014-09-01
 */

class Solution {
public:
    int maxSubArray(int A[], int n) {
        int sum = 0;
        int maxSum = INT_MIN;

        for (int i = 0; i < n; i ++){
            sum += A[i];

            maxSum = max(maxSum, sum);

            if (sum < 0){
                sum = 0;
            }
        }

        return maxSum;
    }
};
