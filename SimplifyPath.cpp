/**
 * @file SimplifyPath.cpp
 * @brief
 * @author nhzc   charles.nhzc@gmail.com
 * @version 1.0.0
 * @date 2014-09-17
 */

class Solution {
public:
    void pathToDict(stack<string> &dict, string &path){
        string word;
        path += '/';//为了在最后能够触发一次操作，因此在这里加入了一个/作为结尾
        for (int i = 0; i < path.size(); i ++){
            if (path[i] == '/'){//每次碰到/的时候触发各种处理
                if (!word.empty()){//如果它为空，则说明是碰到重复的/，这时候继续跳过
                    if (word[0] == '.' && word.size() == 2 && word[1] == '.'){//如果是../触发退栈操作
                        if (!dict.empty()){
                            dict.pop();
                        }
                    }
                    else if (!(word[0] == '.' && word.size() == 1)){//如果碰到./的话直接跳过，否则将路径名称压入
                        dict.push(word);
                    }

                }
                word.clear();
            }
            else{
                word += path[i];
            }
        }
    }
    void dictToStr(stack<string> &dict, string &word){

        while (!dict.empty()){
            word = dict.top() + '/' + word;
            dict.pop();
        }
        if (!word.empty()){//去掉一开始加上去的那个/在结尾处
            word = word.substr(0, word.size() - 1);
        }
        word = '/' + word;

    }
    string simplifyPath(string path) {
        //模拟堆栈操作
        //碰到..的时候出栈，碰到.的时候自动跳过，触发这些操作的时候是字符串碰到了/，每次循环用一个name存储当前储存的字符
        //然后再退栈返回需要的路径
        stack<string> dict;
        string result;
        pathToDict(dict, path);
        dictToStr(dict, result);
        return result;
    }
};
