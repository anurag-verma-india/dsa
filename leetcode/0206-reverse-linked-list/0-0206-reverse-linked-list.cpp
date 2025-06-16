
//
#include <bits/stdc++.h>

#include "./file_as_stdin.cpp"
#include "./read_int.cpp"

/*
Description:

input:

output:

approach:

---
complexity

space:

time:

*/

//  Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

struct ListNode2 {
    int val;
    ListNode* next;
    ListNode2() : val(0), next(nullptr) {}
    ListNode2(int x) : val(x), next(nullptr) {}
    ListNode2(int x, ListNode2* next) : val(x), next(next) {}
};

class Solution {
   public:
    ListNode* reverseList(ListNode* head) {
    }
};

int main() {
    file_as_stdin("input.txt");
    vector<int> int_vec = read_int();
    return 0;
}