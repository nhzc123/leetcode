/**
 * @file N-Queens.cpp
 * @brief
 * @author charles.nhzc@gmail.com
 * @version 1.0.0
 * @date 2014-09-04
 */

class Solution {
public:
    int rows[1001];//记录每一行Q的位置
    int cols[1001];//记录列是否有Q，1为有 2为没有
    vector<vector<string> > result;

    void generated_result(int n){

        vector<string> puzzle;

        for (int i = 0; i < n; i ++){
            string tmp(n,'.');
            tmp[rows[i]] = 'Q';
            puzzle.push_back(tmp);
        }
        result.push_back(puzzle);
    }

    void dfs(int q, int n){
        if (q == n){
            generated_result(n);
            return ;
        }

        for (int i = 0; i < n; i ++){
            if (cols[i] == 0){//列上面没有Q
                int j;
                for ( j = 0; j < q; j ++){
                    if (abs(j - q) == abs(i - rows[j])){//就是判断行差值与列差值，如果每一行的Q在对角向上 则相等
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
    vector<vector<string> > solveNQueens(int n) {
        result.clear();

        dfs(0, n);

        return result;

    }
};
