#include<iostream>
#include<string>
#include<vector>
#include<set>
using namespace std;

int main(){
	multiset<int> s;
	s.insert(2);
	auto be = s.begin();
	cout<<*be<<endl;
	auto en = s.end();
	cout<<*en<<endl;
	auto lb = s.lower_bound(2);
	cout<<*lb<<endl;
	auto ub = s.upper_bound(2);
	cout<<(ub == s.begin())<<endl;
	cout<<*ub<<endl;
	return 0;
}

