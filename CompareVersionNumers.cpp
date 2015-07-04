/**
 * @file CompareVersionNumers.cpp
 * @brief
 * @author nhzc   charles.nhzc@gmail.com
 * @version 1.0.0
 * @date 2015-04-19
 */
#include<iostream>
#include<vector>
#include<string>
using namespace std;
    vector<string> version2vector(const string &version){
        vector<string> result;
        string dig = "";

        for (int i = 0; i < version.length(); i ++){
            if (version[i] == '.'){

                result.push_back(dig);
                dig = "";

            }
            else{
                dig += version[i];
            }
        }
        if (dig != ""){
            result.push_back(dig);
        }
        return result;
    }

    int cmp(const vector<string> &v1, const vector<string> &v2){
        //the first position
        int len = v1.size() > v2.size() ? v2.size() : v1.size();
        for (int k = 0; k < len; k ++){
            int pos1 = 0;
            while(v1[k][pos1] == '0'){
                pos1 ++;
            }
            int pos2 = 0;
            while(v2[k][pos2] == '0'){
                pos2 ++;
            }
            string s1 = v1[k].substr(pos1);
            string s2 = v2[k].substr(pos2);
            if (s1.length() > s2.length()){
                return 1;
            }
            if (s1.length() < s2.length()){
                return -1;
            }
            for (int i = 0; i < s1.length(); i ++){
                if (s1[i] > s2[i]){
                    return 1;
                }
                else if (s1[i] < s2[i]){
                    return -1;
                }
            }
        }
        if (v1.size() > v2.size()){
            for (int k = v2.size(); k < v1.size(); k++){
                for (int z = 0; z < v1[k].length(); z++){
                    if (v1[k][z] != '0'){
						cout<<v1[k][z]<<endl;
						cout<<"hehe"<<endl;
                        return 1;
                    }
                }
            }
            return 0;
        }
        else if(v1.size() < v2.size()){
            for (int k = v1.size(); k < v2.size(); k++){
                for (int z = 0; z < v2[k].length(); z++){
                    if (v2[k][z] != '0'){
                        return -1;
                    }
                }
            }
            return 0;
        }
        else{
            return 0;
        }

    }
    int compareVersion(string version1, string version2) {
        vector<string> v1 = version2vector(version1);
        vector<string> v2 = version2vector(version2);
        return cmp(v1, v2);
    }

int main(){
	string v1 = "1.0";
	string v2 = "1";
	cout<<compareVersion(v1, v2)<<endl;;
	return 0;

}
