class Solution {
	public:
    int removeDuplicates(int A[], int n) {
	        if (n == 0)
	            return 0;
	        int index = 0;
	        int count = 1;
	        for (int i = 1; i < n; i++){
			            if (A[index] != A[i]){
						                A[++index] = A[i];
						                count = 1;
						            }
			            else if (count == 1){
						                A[++index] = A[i];
						                count ++;
						            }

			        }

	        return index + 1;

	    }
};
