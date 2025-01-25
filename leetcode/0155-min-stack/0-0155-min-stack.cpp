// not implemented
// https://leetcode.com/problems/min-stack/description/


#include <bits/stdc++.h>

#include "./read.cpp"

int main() {
    read_input("input.txt");

    MinStack* obj = new MinStack();
}

class MinStack {
    /*
    // Some sort of ordered data structure
    */
   private:
    stack<int> st;
    int min = NULL;
    int freq_min = 0;

   public:
    MinStack() {
    }

    void push(int val) {
        if (min != NULL && val < min) {
            min = val;
            freq_min++;
        }
        st.push(val);
    }

    void pop() {
        if (st.top() == min) freq_min--;
    }

    int top() {
        return st.top();
    }

    int getMin() {
        return min;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
