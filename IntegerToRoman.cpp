class Solution {
public:
    void cal(string &res,int bit,char symbols[]){

        if (bit == 0){

            return ;
        }
        else if (bit <= 3){
            res.append(bit,symbols[0]);
        }
        else if (bit == 4){
            res.append(1,symbols[0]);
            res.append(1,symbols[1]);
        }
        else if (bit <= 8){
            res.append(1,symbols[1]);
            res.append(bit - 5,symbols[0]);
        }
        else if (bit == 9){
            res.append(1,symbols[0]);
            res.append(1,symbols[2]);
        }
    }
    string intToRoman(int num) {

        char symbols[8] = {'I','V','X','L','C','D','M'};
        string res ="";
        int p = 6;
        int scale = 1000;

        while (num){

            int bit = num / scale;

            cal(res,bit,symbols + p);

            num %= scale;
            p -= 2;
            scale /= 10;
        }

        return res;

    }
};
