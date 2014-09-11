class Solution {
public:
    bool wordBreak(string s, unordered_set<string> &dict) {

        if(  s.length() == 0 ){

            return true;
        }
        bool flag[1000];
        memset(flag, false,sizeof(flag));
        flag[0] = true;

        for( int i = 0 ; i < s.length(); i++){

            for( int j = 0; j <= i; j++){

                if( flag[j] && ( dict.find( s.substr(j,i +1 - j)) != dict.end())){
                    flag[i + 1] = true;

                }
            }
        }

        return flag[s.length()];

    }
};
