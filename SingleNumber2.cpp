class Solution {
public:
    int singleNumber(int A[], int n) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        int one = 0;
        int two = 0;
        int three = 0;
        for(int i = 0 ; i < n ; i++){
            two |= A[i] & one;
            one = A[i] ^ one;
            three = ~(one&two);
            one &= three;
            two &= three;
        }
        return one;
    }
};
