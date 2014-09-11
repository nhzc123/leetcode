class Solution {
public:
    int searchInsert(int A[], int n, int target) {
        int low = 0;
        int high = n - 1;

        while (low <= high){
            int mid = low + (high - low) /2;
            if (A[mid] > target){
                high = mid - 1;
            }
            else if (A[mid] == target){
                return mid;
            }
            else {
                low = mid + 1;
            }
        }
        return low;
    }
};
