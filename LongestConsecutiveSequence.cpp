/**
 * @file LongestConsecutiveSequence.cpp
 * @brief
 * @author charles.nhzc@gmail.com
 * @version 1.0.0
 * @date 2014-08-30
 */

class Solution {
public:
    int longestConsecutive(vector<int> &num) {
        if(num.size() == 0){
            return 0;
        }

        unordered_set<int> visited;
        unordered_set<int> exist;

        for (int i = 0; i < num.size(); i ++){
            exist.insert(num[i]);
        }

        int maxLength = 0;

        for (int i = 0; i < num.size(); i ++){
            if (visited.find(num[i]) != visited.end()){
                continue;
            }

            int count = 1;
            int left = num[i];

            while (exist.find(-- left) != exist.end()){
                count ++;
                visited.insert(left);
            }

            int right = num[i];

            while (exist.find(++ right) != exist.end()){
                count ++;
                visited.insert(right);
            }

            maxLength = max(maxLength, count);
        }

        return maxLength;
    }
};
