/**
 * @file CountPrimes.cpp
 * @brief
 * @author nhzc   charles.nhzc@gmail.com
 * @version 1.0.0
 * @date 2015-04-29
 */
#include<iostream>
using namespace std;
int countPrimes(int n) {
        bool *array = new bool [n + 1];
        //memset(array, 0, sizeof(array));
        array[0] = array[1] = true;
		cout<<"haha"<<endl;
        for (int i = 2; i * i < n ; i++){
            if (!array[i]){
                int c = i * i;
                while (c < n){
                    array[c] = true;
                    c += i;
                }
            }
        }
		cout<<"hehe"<<endl;
        int result = 0;
        for (int i = 0; i < n; i ++){
            if (!array[i]){
                result ++;
            }
        }
        delete [] array;
        return result;
    }
int main(){
	cout<<countPrimes(477900)<<endl;
	return 0;

}
