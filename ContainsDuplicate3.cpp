/**
 * @file ContainsDuplicate3.cpp
 * @brief
 * @author nhzc   charles.nhzc@gmail.com
 * @version 1.0.0
 * @date 2015-06-01
 */
#include<iostream>
#include<set>
#include<vector>
using namespace std;
bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        multiset<long long> heap;
        for (int i = 0; i < nums.size(); i ++){
            if (heap.size() == k + 1){
                heap.erase(heap.find(nums[i - k - 1]));
            }
            auto minNum = heap.lower_bound(nums[i]);
            if (minNum != heap.end() && abs(*minNum - nums[i]) <= t){
				cout<<"minNum"<<*minNum<<endl;
                return true;
            }
			auto maxNum = heap.upper_bound(nums[i]);
            if (maxNum != heap.begin() && abs(*(--maxNum) - nums[i]) <= t){
				cout<<"maxNum"<<*(++maxNum)<<endl;
                return true;
            }

            heap.insert(nums[i]);

        }
        return false;
    }
int main(){
	vector<int> nums;
	nums.push_back(1);
	nums.push_back(2);
	nums.push_back(3);
	cout<<containsNearbyAlmostDuplicate(nums, 2, 3)<<endl;
	return 0;


}
