class Solution {
public:
    int evalRPN(vector<string> &tokens) {
        int len = tokens.size();
        stack<int> s;
        int t1 , t2 , tem;
        for(int i = 0; i < len; i++){
            if(tokens[i] !="+" && tokens[i] !="-" && tokens[i] !="*" && tokens[i] !="/"){
                s.push(atoi(tokens[i].c_str()));
            }
            else{
                t1 = s.top() ;
                s.pop();
                t2 = s.top() ;
                s.pop();

                if( tokens[i] == "+"){
                    tem = t1 + t2;
                }
                else if( tokens[i] == "-"){
                    tem = t2 - t1;
                }
                else if( tokens[i] == "*"){
                    tem = t2 * t1;
                }
                else if( tokens[i] == "/"){
                    tem = t2 / t1;
                }

                s.push(tem);

            }
        }

        if( s.size() == 1){
            return s.top();
        }
	 }
};
