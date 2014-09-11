/**
 * @file WOrdSearch.cpp
 * @brief
 * @author charles.nhzc@gmail.com
 * @version 1.0.0
 * @date 2014-09-02
 */

class Solution {
public:

//简单的dfs
    int vertical[4] = {0, 0, -1, 1};
    int horizontal[4] = {-1, 1, 0, 0};
    int row;
    int col;
    int flag;
    bool dfs(vector<vector<char> > &board, string word, int x, int y,  int index){
        if (flag){
            return true;
        }

        if (word.length() == index){
            flag = true;
            return true;
        }



        for (int i = 0; i < 4; i ++){
            int curX = x + vertical[i];
            int curY = y + horizontal[i];

            if (curX >= 0 && curX < row && curY >= 0 && curY < col && board[curX][curY] == word[index]){
                board[curX][curY] = '.';

                if(dfs(board, word, curX, curY, index + 1)){
                    return true;
                }

                board[curX][curY] = word[index];
            }


        }

        return false;

    }
    bool exist(vector<vector<char> > &board, string word) {
        if (word.length() == 0){
            return true;
        }

        row = board.size();
        col = board[0].size();

        if (row * col < word.length()){
            return false;
        }
        flag = false;

        for (int i = 0; i < row; i ++){
            for (int j = 0; j < col; j ++){
                if (board[i][j] == word[0]){
                    board[i][j] = '.';
                    if (dfs(board, word, i, j, 1)){
                        return true;
                    }
                    board[i][j] = word[0];
                }
            }
        }
        return false;
    }
};

