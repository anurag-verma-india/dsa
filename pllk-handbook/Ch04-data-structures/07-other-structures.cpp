#include <bits/stdc++.h>
using namespace std;

int main()
{
    bitset<10> a(string("1100110011"));
    bitset<10> b(string("0011001100"));
    bitset<10> c(a | b);
    cout << c << "\n";

    deque<int> d; // Like dynamic array, front and back elements can be changed
    d.push_back(1);
    d.push_front(2);
    cout << d.front() << "\n";
    cout << d.back() << "\n";
    d.pop_back();

    stack<int> stack_1; // Only top operations O(1)

    queue<int> q1; // Add to back, remove from front O(1)

    cout << "\n";
    priority_queue<int> q; // Supports all operations of ordered set but faster

    q.push(3);
    q.push(5);
    q.push(7);
    q.push(2);
    cout << q.top() << "\n"; // 7
    q.pop();
    cout << q.top() << "\n"; // 5
    q.pop();
    q.push(6);
    cout << q.top() << "\n"; // 6
    q.pop();

    return 0;
}
