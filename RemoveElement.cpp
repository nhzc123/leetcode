class Solution {
public:
    int removeElement(int A[], int n, int elem) {
        int index = 0;
        if (n == 0){
            return index;
        }
        for (int i = 0; i < n; i++){
            if (elem != A[i]){
                A[index++] = A[i];
            }
        }
        return index;

    }
};
