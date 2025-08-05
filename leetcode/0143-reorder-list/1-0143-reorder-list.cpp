
// https://leetcode.com/problems/reorder-list/
#include <bits/stdc++.h>

#include "./file_as_stdin.cpp"
#include "./read_int.cpp"

/*
Description:
You are given the head of a singly linked-list. The list can be represented as:

L0 → L1 → … → Ln - 1 → Ln
Reorder the list to be on the following form:

L0 → Ln → L1 → Ln - 1 → L2 → Ln - 2 → …
You may not modify the values in the list's nodes. Only nodes themselves may be changed.

input:
    ListNode* head: head of the linked list

output:
    void : just manipulate the existing list to reorder in the given format, starting from HEAD

approach:


---
complexity

space:

time:

*/

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
   public:
    void reorderList(ListNode* head) {
        ListNode* temp = head;

        unordered_map<ListNode*, ListNode*> prevMap;

        ListNode* prev = nullptr;
        while (temp != nullptr) {
            prevMap.insert(temp, prev);
            prev = temp;
            temp = temp->next;
        }
    }
};

void printLL(ListNode* head) {
    ListNode* temp = head;

    cout << "Linked List values: ";
    while (temp->next != nullptr) {
        cout << temp->val << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    file_as_stdin("input.txt");
    vector<int> int_vec = read_int();

    ListNode* curr = nullptr;
    ListNode* prev = nullptr;
    ListNode* head = nullptr;
    for (int i = 0; i < (int)int_vec.size(); i++) {
        curr = new ListNode(int_vec[i]);
        if (head == nullptr) {
            head = curr;
        }
        if (prev != nullptr) {
            prev->next = curr;
        }
        prev = curr;
    }

    cout << "----List----" << endl;
    printLL(head);

    Solution sol;
    sol.reorderList(head);

    cout << "----Reordered----" << endl;
    printLL(head);

    return 0;
}
