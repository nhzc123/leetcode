class Solution {
public:
    string countAndSay(int n) {
        string begin = "1";

        for (int i = 0; i < n - 1; i ++){
            string next;
            int start = 0;

            while (start < begin.size()){
                int end = start;
                int count = 0;
                char num = begin[start];
                while (end < begin.size() && begin[start] == begin[end]){
                    count++;
                    end++;
                }
                next += char(count + '0');
                next += num;
                start = end;
            }
            begin = next;
        }
        return begin;
    }
};
