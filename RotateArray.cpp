/**
 * @file RotateArray.cpp
 * @brief
 * @author nhzc   charles.nhzc@gmail.com
 * @version 1.0.0
 * @date 2015-04-19
 */
#include<iostream>
using namespace std;
void reverse(int &a, int &b){
        a ^= b;
        b ^= a;
        a ^= b;
    }
    void rotate(int nums[], int n, int k) {
        k = k %n;
        int left = 0;
        int right = n - k - 1;
        while (left < right){
            reverse(nums[left], nums[right]);
			left ++;
			right --;
        }
        left = n - k;
        right = n - 1;
        while (left < right){
            reverse(nums[left], nums[right]);
			left ++;
			right --;
        }
        left = 0;
        right = n - 1;
        while (left < right){
            reverse(nums[left], nums[right]);
			left ++;
			right --;
        }

    }

int main(){
int num[2] = {1,2};
rotate(num, 2, 0);
return 0;

}

