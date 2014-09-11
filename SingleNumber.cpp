ass Solution {
public:
    int singleNumber(int A[], int n) {

        if (n == 0){

            return 0;
        }

        if (n == 1){

            return A[0];
        }

        int sum = A[0];

        for (int i = 1; i< n; i++){

            sum ^= A[i];
        }

        return sum;

    }
};
