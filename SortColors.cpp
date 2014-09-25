/**
 * @file SortColors.cpp
 * @brief
 * @author nhzc   charles.nhzc@gmail.com
 * @version 1.0.0
 * @date 2014-09-23
 */

class Solution {
public:
    void sortColors(int A[], int n) {
        //碰到0交换到前面，碰到2交换到后面 碰到1不做任何操作
        int zero = 0;
        int two = n - 1;
        int i = 0;
        while (i < n){
            switch (A[i]){
                case 0:
                    swap(A[zero], A[i]);
                    i ++;
                    zero ++;
                    break;
                case 1:
                    i ++;
                    break;
                case 2:
                    if (i > two){
                        return;
                    }
                    swap(A[two], A[i]);
                    two --;
                    break;
            }
        }
    }
};
