/**
 * @file SubstringOfConcatenationOfAllWords.cpp
 * @brief
 * @author nhzc   charles.nhzc@gmail.com
 * @version 1.0.0
 * @date 2014-09-17
 */

class Solution {
public:
    vector<int> findSubstring(string S, vector<string> &L) {
        //在S中每次取一个L中长度的string，开始的下标i ++ i < S的长度 - L所有字符串的总长度
        //用一个map来存储L中出现的字符串，记录出现的次数，然后在S中取定长的字符串在L的map中查找是否存在，如果存在则
        //记录出现 当S中的map比L中的大的时候，可以跳出以i下标为开头的循环
        map<string, int> mapL;
        map<string, int> mapS;
        for (int i = 0; i < L.size(); i ++){
            mapL[L[i]] ++;//储存L中字符串的出现次数
        }
        vector<int> result;
        int lenL = L.size();
        if (lenL == 0){
            return result;
        }
        int lenWord = L[0].size();
        if (S.size() < lenL * lenWord){
            return result;
        }
        for (int i = 0; i <= S.size() - lenWord * lenL; i ++){//下标开端直到S尾端距离有L个长度为止
            int j = 0;
            mapS.clear();
            for (j = 0; j < lenL; j ++){//查询L中每个字符串是否在以i开端的S中出现
                string word = S.substr(i + j * lenWord, lenWord);
                if (mapL.find(word) == mapL.end()){//不在S中出现
                    break;
                }
                mapS[word] ++;
                if (mapS[word] > mapL[word]){//S的连续子串中出现比L中字符串还多
                    break;
                }
            }
            if (j == lenL){
                result.push_back(i);
            }

        }
        return result;
    }
};
