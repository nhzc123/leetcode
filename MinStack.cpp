/**
 * @file minStack.cpp
 * @brief
 * @author nhzc   charles.nhzc@gmail.com
 * @version 1.0.0
 * @date 2014-11-14
 */
#include<iostream>
#include<vector>
#include<stack>
using namespace std;
class MinStack {
public:
    void push(int x) {
        if (v.empty()){
            v.push(0);
            minValue = x;
        }
        else if (minValue >= x){
             v.push(x - minValue);
                minValue = x;
        }
        else{
        v.push(x - minValue);
        }
    }

    void pop() {
        if (v.top() < 0){
            minValue = minValue - v.top();
        }
        v.pop();

    }

    int top() {
        if (v.top() < 0){
            return minValue;
        }
        else{
            return v.top() + minValue;
        }
    }

    int getMin() {
       return minValue;
    }
private:
    stack<double> v;
    double minValue;
};

class MinStack {
public:
    void push(int x) {
        s.push(x);
        if (_min.empty() || _min.top() >= x){
            _min.push(x);
        }
    }

    void pop() {
        if (!s.empty()){
            if (s.top() == _min.top()){
                _min.pop();
            }
            s.pop();
        }
    }
    int top() {
        return s.top();
    }
    int getMin() {
       return _min.top();
    }
private:
    stack<int> s;
    stack<int> _min;
};
