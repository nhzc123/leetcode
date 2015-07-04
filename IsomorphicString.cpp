/**
 * @file IsomorphicString.cpp
 * @brief
 * @author nhzc   charles.nhzc@gmail.com
 * @version 1.0.0
 * @date 2015-04-29
 */
#include<iostream>
#include<string>
#include<vector>
using namespace std;
bool isIsomorphic(string s, string t) {
        vector<int> tmp;
        vector<vector<int> > countS(256, tmp);
        vector<vector<int> > countT(256, tmp);
        vector<int> flagT(256, -1);
        int lenS = s.length();
        int lenT = t.length();
        if (lenS != lenT){
            return false;
        }
        for (int i = 0; i < lenS; i ++){
            countS[s[i]].push_back(i);
            countT[t[i]].push_back(i);
            flagT[t[i]] = 1;
        }
        int countMap = 0;
        for (int i = 0; i < 256; i ++){
            for (int j = 0; j < 256; j ++){
                if (countS[i].size() != countT[j].size()){
                    continue;
                }
                else{
                    if (flagT[j] == 1){
                        int k = 0;
                        for (; k < countS[i].size(); k ++){
                            if (countS[i][k] != countT[j][k]){
                                break;
                            }
                        }
                        if (k == countS[i].size()){
                            flagT[j] = -1;
                            countMap ++;
                        }
                    }
                }
            }
        }
        for (int i = 0; i < lenS; i ++){
            if (flagT[t[i]] == 1){
                return false;
            }
        }
        return true;

    }
int main(){
	cout<<isIsomorphic("a", "a")<<endl;
	return 0;

}
