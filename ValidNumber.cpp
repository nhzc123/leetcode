class Solution {
public:
    bool isNumber(const char *s) {
        while (*s !='\0' && *s ==' '){
            s++;
        }
        if (*s =='\0'){
            return false;
        }
        if (*s == '+' || *s == '-'){
            s++;
        }

        const char *e = s + strlen(s) - 1;
        while (e >= s && *e ==' '){
            e--;
        }

        bool is_digit = false;
        bool has_exp = false;
        bool has_dot = false;

        while (s <= e){
            if (*s >= '0' && *s <= '9'){
                is_digit = true;
            }
            else if (*s == '.'){
                if (has_exp || has_dot){
                    return false;
                }
                has_dot = true;
            }
            else if (*s == 'e'){
                if (has_exp || !is_digit){
                    return false;
                }
                has_exp = true;
                is_digit = false;
            }
            else if (*s == '+' || *s =='-'){
                if (*(s - 1) != 'e'){
                    return false;
                }
            }
            else {
                return false;
            }
            s++;
        }
        return is_digit;
    }
};
