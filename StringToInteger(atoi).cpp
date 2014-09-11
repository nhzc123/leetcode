class Solution {
public:
    int atoi(const char *str) {
        if (str == NULL){
            return 0;
        }
        while (*str == ' '){
            str++;
        }

        bool isPositive = true;
        if (*str == '+'){
            str++;
        }
        else if(*str == '-'){
            str++;
            isPositive = false;
        }

        long long int value = 0;

        while (*str != '\0'){
            if (*str >= '0' && *str <= '9'){
                value = value * 10 + *str - '0';
                str++;
            }
            else{
                break;
            }

        }

        if (!isPositive){
            value = -value;
        }
        if (value > INT_MAX){
            value = INT_MAX;
        }
        else if (value < INT_MIN){
            value = INT_MIN;
        }

        return value;
    }
};
