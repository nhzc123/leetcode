/**
 * @file JumpGame2.cpp
 * @brief
 * @author nhzc   charles.nhzc@gmail.com
 * @version 1.0.0
 * @date 2014-09-22
 */

class Solution {
public:
    int jump(int A[], int n) {
       int result = 0;
       int last = 0;//能到达的最远距离
       int cur = 0; //res + 1步能到达的最远距离
       for (int i = 0; i < n; i ++){
           if (i > last){//如果能到达的最远距离比i小，说明目前的步数需要 + 1步才能够到达更远的距离，并且在 last范围内的res步数都                          //可以到达
                last = cur;
                ++ result;
           }
           cur = max(cur, i + A[i]);
       }
       return result;
    }
};
