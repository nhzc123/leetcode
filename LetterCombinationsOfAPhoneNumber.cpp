class Solution {
private:
    string num_letter[10] ={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    vector<string> ans;

public:

    void cal(int s, string p,string d){

        if (s == d.length()){
            ans.push_back(p);
            return ;
        }

        for (int i = 0; i < num_letter[d[s] - '0'].length();i ++){
            p.push_back(num_letter[d[s] - '0'][i]);
            cal(s + 1, p, d);
            p.pop_back();
        }

    }
    vector<string> letterCombinations(string digits) {

        ans.clear();
        string path;
        int step = 0;

        cal(step,path,digits);

        return ans;



    }
};
