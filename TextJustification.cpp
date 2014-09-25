/**
 * @file TextJustification.cpp
 * @brief
 * @author nhzc   charles.nhzc@gmail.com
 * @version 1.0.0
 * @date 2014-09-24
 */

class Solution {
public:
    string addSpaceNormal(int L, int sentenceLength, vector<string> tmp){
        string s = tmp[0];
        if (tmp.size() == 1){
            for (int i = 0; i < L - sentenceLength; i ++){
                s +=' ';
            }
            return s;
        }
        int d = (L - sentenceLength) / (tmp.size() - 1);
        int r = (L - sentenceLength) % (tmp.size() - 1);
        for (int i = 1; i < tmp.size(); i ++){
            for (int i = 0; i < d; i ++){
                s += ' ';
            }
            if (r > 0){//平均分配
                s += ' ';
                r --;
            }
            s += tmp[i];
        }
        return s;
    }
    string addSpaceEnd(int L, int sentenceLength, vector<string> tmp){
        string s = tmp[0];
        for (int i = 1; i < tmp.size(); i ++){
            s = s +' ' + tmp[i];
        }
        for (int i = 0; i < L - sentenceLength; i ++){
            s += ' ';
        }
        return s;
    }
    vector<string> fullJustify(vector<string> &words, int L) {
        vector<string> result;
        int sentenceLength = 0;
        int count = - 1;
        vector<string> tmp;
        if (words.size() == 0 || L == 0){
            string s = "";
            result.push_back(s);
            return result;
        }
        for (int i = 0; i < words.size(); i ++){
            if (count + words[i].size() + 1 > L){
                result.push_back(addSpaceNormal(L, sentenceLength, tmp));
                count = -1;
                sentenceLength = 0;
                tmp.clear();
            }
            count = count + words[i].size() + 1;
            sentenceLength += words[i].size();
            tmp.push_back(words[i]);
        }
        result.push_back(addSpaceEnd(L, count, tmp));
        return result;
    }
};
