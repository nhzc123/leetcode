class Solution {
public:
    int reverse(int x) {
        bool positive = true;
        if (x < 0){
            positive = false;
            x = -x;
        }


        int result = 0;
        while (x){
            result = result * 10 + x % 10;
            x /= 10;
        }

        if (positive){
            return result;
        }
        else{
            return -result;
        }

    }
};
