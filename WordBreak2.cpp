#include<iostream>
#include<vector>
#include<string>
#include<set>
using namespace std;

void dfs(const int &i, string oneSolution);
  bool dp[1000];
    string str;
    vector<string> record[1000];
    vector<string>  result;
    vector<string> wordBreak(string s, set<string> &dict) {
        result.clear();
        for(int i = 0; i < 1000; i ++)
            record[i].clear();
        memset(dp, false, sizeof(dp));
        if(s.size() == 0 )
            return result;

        dp[s.size()] = true;
        for(int i = s.size()-1; i >= 0; i --) {
            int len1 = s.size() - i;
            for(set<string>::iterator it_set = dict.begin(); it_set != dict.end(); it_set++) {
                int len2 = it_set->size();
                if(len1 >= len2 ) {//判断条件比word break 少了一个
                    if(dp[i+len2] && s.substr(i, len2)== *it_set) {//这个地方 wa 过, len1, len2 没把握好

                        if(!dp[i]){
							cout<<"dp i + len2"<<dp[i + len2]<<endl;
							cout<<"dp "<<i<<endl;
                            dp[i] = true;
						}
                        record[i].push_back(*it_set);//*it_set 可使record[i]为true
                    }
                }
            }
        }

        if(!dp[0]) {//单词无法组成句子输出为空
            return result;
        }else{
 str = s;
            dfs(0, "");
            return result;
        }
    }

    void dfs(const int &i, string oneSolution) {
        if(i == str.size()) {//dfs框架的一部分, 判断退出条件
            result.push_back(oneSolution);
        }

        for(int s = 0; s < record[i].size(); s ++) {
            string newStr = record[i][s];
            if(i+newStr.size() != str.size()) {
                newStr.push_back(' ');
            }
            string copySolution = oneSolution;//用local variable,省去undo操作
            copySolution.append(newStr);
            dfs(i+record[i][s].size(), copySolution);

        }
    }

int main(){

	string	s = "catsanddog";
	set<string> dict;
	dict.insert("cat");
	dict.insert("cats");
	dict.insert("and");
	dict.insert("sand");

	dict.insert("dog");

	vector<string> tem =wordBreak(s,dict);

	for (int i = 0;i < tem.size(); i++){

	cout<<tem[i]<<endl;

}
	for (int i = 0; i < s.size(); i ++){
		cout<<i<<":";
		for (int j = 0; j < record[i].size(); j ++){
			cout<<record[i][j]<<" ";
		}
		cout<<endl;
	}

	return 0;
}
