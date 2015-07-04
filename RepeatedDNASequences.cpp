/**
 * @file RepeatedDNASequences.cpp
 * @brief
 * @author nhzc   charles.nhzc@gmail.com
 * @version 1.0.0
 * @date 2015-04-19
 */
#include<iostream>
#include<string>
#include<vector>
#include<map>
using namespace std;
int str2Int(char c){
        if (c == 'A'){
            return 0;
        }
        if (c == 'C'){
            return 1;
        }
        if (c == 'G'){
            return 2;
        }
        else if (c == 'T'){
            return 3;
        }
    }
    vector<string> findRepeatedDnaSequences(string s) {
        vector<string> result;
        map<int, int> m;
		int len = s.length();
        for (int i = 0; i <= len - 10; i ++){
            int key = 0;
            for (int j = 0; j < 10; j ++){
                key <<= 2;
                key += str2Int(s[i + j]);
            }
            if (m.find(key) == m.end()){
                m[key] = 1;
            }
            else{
                m[key] += 1;
                if (m[key] == 2){
                    result.push_back(s.substr(i, 10));
                }
            }
        }
        return result;

    }

int main(){
vector<string> tem = findRepeatedDnaSequences("AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT");
for (int i = 0; i < tem.size(); i ++){
	cout<<tem[i]<<endl;
}
return 0;

}
