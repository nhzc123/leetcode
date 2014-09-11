class Solution {
public:

    bool isValid(string s){
        if (s[0] == '0'){
            if(s.length() == 1){
                return true;
            }
            else{
                return false;
            }
        }

        int num = stoi(s);

        return num <= 255 && num > 0;
    }

    void dfs(string s,string tmp,vector<string> &res,int count){
        if (count == 3 && isValid(s)){
            res.push_back(tmp  + s);
            return ;
        }

        for (int i = 1; i < s.length() && i < 4; i ++){
            string substr = s.substr(0,i);

            if (isValid(substr)){
                dfs(s.substr(i),tmp  + substr + ".",res,count + 1);
            }

        }
    }
    vector<string> restoreIpAddresses(string s) {

        vector<string> res;

        if (s.length() < 4 || s.length() > 12){
            return res;
        }

        dfs(s,"",res,0);
        return res;
    }
};
