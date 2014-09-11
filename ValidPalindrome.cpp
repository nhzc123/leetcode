class Solution {
public:
    bool isPalindrome(string s) {
        string alpha;
        for (int i = 0; i < s.length(); i++){
            if (s[i] >='A' && s[i] <='Z'){
                alpha += s[i] -'A' + 'a';
            }
            else if (s[i] >='a' && s[i] <= 'z'){
                alpha += s[i] ;
            }
            else if (s[i] >='0' && s[i] <= '9'){
                alpha += s[i];
            }
        }
        if (alpha.size() == 0){
            return true;
        }
        int start = 0;
        int end = alpha.size() - 1;
        while (start < end){
            if (alpha[start] == alpha[end]){
                start ++;
                end --;
            }
            else{
                return false;
            }
        }
        return true;
    }
};
