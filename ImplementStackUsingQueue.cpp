/**
 * @file ImplementStackUsingQueue.cpp
 * @brief
 * @author nhzc   charles.nhzc@gmail.com
 * @version 1.0.0
 * @date 2015-07-15
 */
class Stack {
public:
    // Push element x onto stack.
    queue<int> q[2];
    int cur = 0;
    void push(int x) {
        q[cur].push(x);
    }

    // Removes the element on top of the stack.
    void pop() {
        while (q[cur].size() > 1){
            q[1 - cur].push(q[cur].front());
            q[cur].pop();
        }
        q[cur].pop();
        cur = 1 - cur;

    }

    // Get the top element.
    int top() {
       while (q[cur].size() > 1){
            q[1 - cur].push(q[cur].front());
            q[cur].pop();
       }
       int n = q[cur].front();
       q[cur].pop();
       q[1 - cur].push(n);
       cur = 1 - cur;
       return n;
    }

    // Return whether the stack is empty.
    bool empty() {
        return q[cur].empty();
    }
};
