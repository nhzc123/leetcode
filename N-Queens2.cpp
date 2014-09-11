/**
 * @file N-Queens2.cpp
 * @brief
 * @author charles.nhzc@gmail.com
 * @version 1.0.0
 * @date 2014-09-04
 */

class Solution {
public:
    int rows[1001];
    int cols[1001];
    int count;

    void dfs(int q, int n){
        if (q == n){
            count ++;
            return ;
        }

        for (int i = 0; i < n; i ++){
            if (cols[i] == 0){
                int j ;
                for (j = 0; j < q; j ++){
                    if (abs(j - q) == abs(i - rows[j])){
                        break;
                    }
                }
                if (j == q){
                    rows[q] = i;
                    cols[i] = 1;
                    dfs(q + 1, n);
                    rows[q] = 0;
                    cols[i] = 0;
                }
            }
        }
    }

    int totalNQueens(int n) {
        count = 0;
        dfs(0, n);
        return count;
    }
};
