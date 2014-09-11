class Solution {
public:
    void merge(int A[], int m, int B[], int n) {
        if ( n == 0){
            return ;
        }
        int i = m - 1;
        while (i >= 0){
            A[n + i] = A[i];
            i--;
        }
        int start = 0;
        int aPoint = n;
        int bPoint = 0;
        while (aPoint < m + n && bPoint < n){
            if (A[aPoint] < B[bPoint]){
                A[start++] = A[aPoint];
                aPoint++;
            }
            else{
                A[start++] = B[bPoint];
                bPoint++;
            }
        }
        while (bPoint < n){
            A[start++] = B[bPoint];
            bPoint++;
        }
        return ;

    }
};
