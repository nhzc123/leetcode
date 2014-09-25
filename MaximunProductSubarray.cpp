/**
 * @file MaximunProductSubarray.cpp
 * @brief
 * @author nhzc   charles.nhzc@gmail.com
 * @version 1.0.0
 * @date 2014-09-24
 */

class Solution {
public:
    int maxProduct(int A[], int n) {
        int *maxA = new int[n];
        int *minA = new int[n];
        maxA[0] = minA[0] = A[0];
        int result = A[0];
        for (int i = 1; i < n; i ++){
            maxA[i] = max(max(A[i], maxA[i - 1] * A[i]), minA[i - 1] * A[i]);
            minA[i] = min(min(A[i], maxA[i - 1] * A[i]), minA[i - 1] * A[i]);
            result = max(maxA[i], result);
        }
        return result;
    }
};
