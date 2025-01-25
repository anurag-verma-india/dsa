// working
// https://github.com/neetcode-gh/leetcode/blob/main/cpp%2F0155-min-stack.cpp

#include <bits/stdc++.h>

#include "./read.cpp"

class MinStack {
    /*
    use two stacks

    Use one stack to store the normal stack
    stack_1 = simple_stack

    Use another another stack to store the minimum value in the stack and it's
    freq stack_2 = {value, freq}
     */
   private:
    stack<int> stk;
    stack<pair<int, int>> minStk;

   public:
    MinStack() {}

    void push(int val) {
        if (minStk.empty() || val < minStk.top().first)
            minStk.push({val, 1});
        else if (minStk.top().first == val)
            minStk.top().second++;
        stk.push(val);
    }

    void pop() {
        if (minStk.top().first == stk.top()) {
            minStk.top().second--;
            if (minStk.top().second == 0)
                minStk.pop();
        }
        stk.pop();
    }

    int top() { return stk.top(); }

    int getMin() { return minStk.top().first; }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */

int main() {
    // read_input("input.txt");

    MinStack *obj = new MinStack();  // Just to check syntax
}
