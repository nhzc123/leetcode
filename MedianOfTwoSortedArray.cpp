/**
 * @file MedianOfTwoSortedArray.cpp
 * @brief
 * @author nhzc   charles.nhzc@gmail.com
 * @version 1.0.0
 * @date 2014-09-24
 */

class Solution {
public:
    //解法就是求第K个最小的数，
    /*
    1. 保持A是短的那一个数组，B是长的
    2. 平分k, 一半在A，一半在B （如果A的长度不足K/2,那就pa就指到最后一个）
    3. 如果pa的值 < pb的值，那证明第K个数肯定不会出现在pa之前，递归，把A数组pa之前的砍掉，同理递归砍B数组。
    4. 递归到 m == 0 （短的数组用完了） 就返回 B[k - 1], 或者k == 1（找第一个数）就返回min(A第一个数，B第一个数）。
    */
    double find(int A[], int m, int B[], int n, int k){
        if (m > n){//将小的数组放到前面去
            return find(B, n, A, m, k);
        }
        if (m == 0){//如果其中一个数组已经被删除没了
            return B[k - 1];
        }
        if (k == 1){//如果取最小的1个数
            return min(A[0], B[0]);
        }
        int indexA = min(k / 2, m);
        int indexB = k - indexA;
        if (A[indexA - 1] < B[indexB - 1]){
            return find(A + indexA, m - indexA, B, n, k - indexA);
        }
        else if (A[indexA - 1] > B[indexB - 1]){
            return find(A, m, B + indexB, n - indexB, k - indexB);
        }
        else{
            return A[indexA - 1];
        }
    }
    double findMedianSortedArrays(int A[], int m, int B[], int n) {
        int k = m + n;
        if (k %2 == 0){//中位数的偶数取两数和的平均
            return (find(A, m, B, n, k / 2) + find(A, m, B, n, k / 2 + 1)) / 2.0;
        }
        else{
            return find(A, m, B, n, k / 2 + 1);
        }

    }
};
