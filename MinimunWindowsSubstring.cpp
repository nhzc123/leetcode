/**
 * @file MinimunWindowsSubstring.cpp
 * @brief
 * @author nhzc   charles.nhzc@gmail.com
 * @version 1.0.0
 * @date 2014-09-24
 */

//用了map会超时，因为每次都需要寻找

class Solution {
public:
    bool suitWindows(map<char, int> &pattern, map<char, int> &text){
        for (map<char, int> :: iterator iter = pattern.begin(); iter != pattern.end(); iter ++){
            if (iter -> second > text[iter -> first]){
                return false;
            }
        }
        return true;
    }
    string minWindow(string S, string T) {
       map<char, int> pattern;
       map<char, int> text;
       for (int i = 0; i < T.size(); i ++){
           if (pattern.find(T[i]) == pattern.end()){
               pattern[T[i]] = 1;
           }
           else{
               pattern[T[i]] ++;
           }
       }
       for (int i = 0; i < S.size(); i ++){
           if (text.find(S[i]) == text.end()){
               text[S[i]] = 0;
           }
       }
       int start = 0, end = 0, minStart = 0, minEnd = 0, minLength = S.size();
       int flag = false;
       text[S[0]] ++;
       while (end < S.size()){
           //尾指针一直往后面走
           if (suitWindows(pattern, text)){//如果当前窗口能够包含所有字符
               if (minLength >= end - start + 1){//如果窗口为最小
                   flag = true;
                   minStart = start;
                   minEnd = end;
                   minLength = end - start + 1;
               }
               if (start < end){
                   start ++;
                   text[S[start - 1]] --;
               }
               else{
                   end ++;
                   text[S[end]] ++;
               }
           }
           else{//不行的话尾指针往后移动一位
               end ++;
               if (end < S.size()){//区间text增加1
                   text[S[end]] ++;
               }
           }
       }
       if (!flag){
           return "";
       }
       else{
           return S.substr(minStart, minLength);
       }
    }
};

//数组表示

class Solution {
public:
    bool suitWindows(int pattern[], int text[]){
        for (int i = 0; i < 256; i ++){
            if (pattern[i] > text[i]){
                return false;
            }
        }
        return true;
    }
    string minWindow(string S, string T) {
       int pattern[256];
       int text[256];
       memset(pattern, 0, sizeof(pattern));
       memset(text, 0, sizeof(text));
       for (int i = 0; i < 256; i ++){
           pattern[i] = text[i] = 0;
       }
       for(int i = 0; i < T.size(); i ++){
           pattern[T[i]] ++;
       }
       int start = 0, end = 0, minStart = 0, minEnd = 0, minLength = S.size();
       int flag = false;
       text[S[0]] ++;
       while (end < S.size()){
           //尾指针一直往后面走
           if (suitWindows(pattern, text)){//如果当前窗口能够包含所有字符
               if (minLength >= end - start + 1){//如果窗口为最小
                   flag = true;
                   minStart = start;
                   minEnd = end;
                   minLength = end - start + 1;
               }
               if (start < end){
                   start ++;
                   text[S[start - 1]] --;
               }
               else{
                   end ++;
                   text[S[end]] ++;
               }
           }
           else{//不行的话尾指针往后移动一位
               end ++;
               if (end < S.size()){//区间text增加1
                   text[S[end]] ++;
               }
           }
       }
       if (!flag){
           return "";
       }
       else{
           return S.substr(minStart, minLength);
       }
    }
};
