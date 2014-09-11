/**
 * @file ValiSudoku.cpp
 * @brief
 * @author charles.nhzc@gmail.com
 * @version 1.0.0
 * @date 2014-09-01
 */
class Solution {
public:
    bool isValidSudoku(vector<vector<char> > &board) {

        bool flag[9];


        //row
        for (int i = 0; i < 9; i ++){
            memset(flag,false,sizeof(flag));

            for (int j = 0; j < 9; j ++){
                if (board[i][j] =='.')
                    continue;
                if (flag[board[i][j] -'1']){
                    return false;
                }
                else{
                    flag[board[i][j] - '1'] = true;
                }
            }
        }

         //colum
        for (int i = 0; i < 9; i ++){
            memset(flag,false,sizeof(flag));

            for (int j = 0; j < 9; j ++){
                if (board[j][i] =='.')
                    continue;
                if (flag[board[j][i] -'1']){
                    return false;
                }
                else{
                    flag[board[j][i] - '1'] = true;
                }
            }
        }

        //block
        for (int i = 0; i < 9; i ++){
            int startRow = (i / 3) * 3;
            int startCol = (i % 3) * 3;
            memset(flag,false,sizeof(flag));

            for (int j = startRow; j < startRow + 3; j ++){
                for (int k = startCol; k < startCol + 3; k ++){
                    if (board[j][k] =='.')
                        continue;
                    if (flag[board[j][k] -'1']){
                    return false;
                }
                else{
                    flag[board[j][k] - '1'] = true;
                }
                }
            }
        }

        return true;
    }
};
