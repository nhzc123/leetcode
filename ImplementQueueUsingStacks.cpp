/**
 * @file ImplementQueueUsingStacks.cpp
 * @brief
 * @author nhzc   charles.nhzc@gmail.com
 * @version 1.0.0
 * @date 2015-07-07
 */
class Queue {
public:
    stack<int> s[2];
    //int cur = 0;
    // Push element x to the back of queue.
    void push(int x) {
        s[0].push(x);
    }

    // Removes the element from in front of queue.
    void pop(void) {
        while (s[0].size() > 1){
            s[1].push(s[0].top());
            s[0].pop();
        }

        s[0].pop();

        while (s[1].size() > 0){
            s[0].push(s[1].top());
            s[1].pop();
        }

    }

    // Get the front element.
    int peek(void) {
        while (s[0].size() > 1){
            s[1].push(s[0].top());
            s[0].pop();
        }
        int peekNum = s[0].top();
        s[1].push(peekNum);
        s[0].pop();

        while (s[1].size() > 0){
            s[0].push(s[1].top());
            s[1].pop();
        }
        return peekNum;
    }

    // Return whether the queue is empty.
    bool empty(void) {
        return s[0].empty();
    }
};

class Queue {
public:
    stack<int> s[2];
    //int cur = 0;
    // Push element x to the back of queue.
    void push(int x) {
        s[0].push(x);
    }

    // Removes the element from in front of queue.
    void pop(void) {
        if (!s[1].empty()){
            s[1].pop();
        }
        else{
            while (!s[0].empty()){
                s[1].push(s[0].top());
                s[0].pop();
            }
            s[1].pop();
        }

    }

    // Get the front element.
    int peek(void) {
        if (!s[1].empty()){
            return s[1].top();
        }
        else{
            while (!s[0].empty()){
                s[1].push(s[0].top());
                s[0].pop();
            }
            return s[1].top();
        }
    }

    // Return whether the queue is empty.
    bool empty(void) {
        return s[0].empty() && s[1].empty();
    }
};
