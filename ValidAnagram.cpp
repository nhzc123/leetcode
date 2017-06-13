class Solution {
public:
    bool isAnagram(string s, string t) {
        int isAlp[256];
        for (int i = 0; i < 256; i ++){
            isAlp[i] = 0;
        }
        if (s.length() != t.length()){
            return false;
        }
        for (int i = 0; i < s.length(); i ++){
            isAlp[s[i] - 'a'] += 1;
            isAlp[t[i] - 'a'] -= 1;
        }
        for (int i = 0; i < 256; i ++){
            if (isAlp[i] != 0){
                return false;
            }
        }
        return true;
    }
};
