/**
 * @file TrappingRainWater.cpp
 * @brief
 * @author charles.nhzc@gmail.com
 * @version 1.0.0
 * @date 2014-09-06
 */

class Solution {
public:
    int trap(int A[], int n) {
        //实际上就是需要找到一个位置左右两边的最高值，因此可以首先找到全局的最高点，然后分别从左往右和从右边往左找到左右的最高值，即可获得每个位置上的峰值
        int maxVal = INT_MIN;
        int maxIndex = 0;

        for (int i = 0; i < n; i ++){
            if (A[i] > maxVal){
                maxIndex = i;
                maxVal = A[i];
            }
        }

        int left = INT_MIN;
        int right = INT_MIN;
        int sum = 0;

        for (int i = 0; i < maxIndex; i ++){
            if (A[i] > left){
                left = A[i];
            }
            else{
                sum += left - A[i];
            }
        }

        for (int i = n - 1; i > maxIndex; i --){
            if (A[i] > right){
                right = A[i];
            }
            else{
                sum += right - A[i];
            }
        }

        return sum;

    }
};
