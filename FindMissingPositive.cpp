/**
 * @file FindMissingPositive.cpp
 * @brief
 * @author charles.nhzc@gmail.com
 * @version 1.0.0
 * @date 2014-09-05
 */

class Solution {
public:


    int firstMissingPositive(int A[], int n) {
        /*对于正数A[i]，我们希望它能被放在第i个位置上，这样子当我们找到A[i] != i时，我们就找到了想要的数。
当我们遍历数组的时候，如果我们发现A[i] != i，那么我们就swap(A[A[i]], A[i])，让A[i]放在正确的位置上。而对于交换之后的A[i]，我们继续做这个操作，直至交换没有意义为止。没有意义表示当前数不是正数，或超过数组长度，或与A[A[i]]相等。我们不关心这些数被排在什么位置。此外还要考虑如果整个数组都是连续的正数，比如A[] = {1,2}，经过我们上面的排序之后会变成{2, 1}，因为A[1] == 1（从1开始对比），而A[2]超出范围，所以函数会认为2之前的都出现过了而2没有出现过，返回2。为了防止把正确的数"挤"出数组，我们让A[A[i]-1]与A[i]交换，然后比较i+1和A[i]。于是我们有了如下代码。
*/
        for (int i = 0; i < n; ){
            if (A[i] <= 0 || A[i] == i + 1 || A[A[i] -1] == A[i] || A[i] > n){
                i ++;
            }
            else{
                swap(A[A[i] - 1], A[i]);
            }
        }

        int i = 0;
        for (; i < n; i ++){
            if (A[i] != i + 1){
                break;
            }
        }
        return i + 1;
    }
};
