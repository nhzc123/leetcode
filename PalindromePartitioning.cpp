class Solution {
public:

    bool isValid(string s){
        int i = 0;
        int j = s.length() - 1;

        while (i < j){
            if (s[i] != s[j]){
                return false;
            }
            i++;
            j--;
        }
        return true;
    }

    void dfs(string s,vector<string> v,vector<vector<string>> &res){
        if (s.length() == 0){
            res.push_back(v);
            return ;
        }

        for (int i = 1; i <= s.length() ; i ++){
            string substr = s.substr(0,i);


            if (isValid(substr)){
                v.push_back(substr);
                dfs(s.substr(i),v,res);
                v.pop_back();
            }

        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        if (s.size() == 0 ){
            return res;
        }

        if (s.size() == 1){
            vector<string> v;
            v.push_back(s);
            res.push_back(v);

            return res;
        }

        vector<string> v;

        dfs(s,v,res);

        return res;

    }
};
