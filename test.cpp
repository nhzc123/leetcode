/**
 * @file test.cpp
 * @brief
 * @author nhzc   charles.nhzc@gmail.com
 * @version 1.0.0
 * @date 2015-08-15
 */
#include<iostream>
using namespace std;
bool isBadVersion(int version){
	if (version >= 1702766719){
		return true;
	}
	else{
		return false;
	}
}
int firstBadVersion(int n) {
        int left = 0;
        int right = n - 1;
        while (left <= right){
            int mid = left + (right - left) / 2;
			cout<<mid<<endl;
            if (isBadVersion(mid)){
                right = mid - 1;
            }
            else{
                left = mid + 1;
            }
        }
        return left;
    }

int main(int argc, char *argv[])

{

cout<<firstBadVersion(2126753390)<<endl;

return 0;

}
