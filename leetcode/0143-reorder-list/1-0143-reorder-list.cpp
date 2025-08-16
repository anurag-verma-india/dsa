
// t: 0ms - 100%, s: 23 - 80%
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
    find the middle of the list
    reverse the right half
    merge the left half and the reversed right half

---
complexity
time: O(n)

space: O(1)

*/

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

void printLL(ListNode* head) {
    ListNode* temp = head;

    cout << "Linked List values: ";
    while (temp != nullptr) {
        cout << temp->val << " ";
        temp = temp->next;
    }
    cout << endl;
}

class Solution {
   public:
    void reorderList(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;

        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* left = head;
        ListNode* right = slow->next;
        slow->next = nullptr;  // cut the link of the left half to the right one

        // cout << "---- Left ----" << endl;
        // printLL(left);
        // cout << "---- Right ----" << endl;
        // printLL(right);

        // reverse the right half
        ListNode* prev = nullptr;
        ListNode* temp = right;
        ListNode* nxt = nullptr;

        while (temp) {
            nxt = temp->next;
            temp->next = prev;
            prev = temp;
            temp = nxt;
        }
        right = prev;
        // cout << "--rev--" << endl;
        // printLL(right);

        // Merge the right half with the left half
        ListNode* l_nxt;
        ListNode* r_nxt;
        while (left && right) {
            l_nxt = left->next;
            r_nxt = right->next;
            left->next = right;
            right->next = l_nxt;

            right = r_nxt;
            left = l_nxt;
        }
    }
};

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

    // cout << "----List----" << endl;
    // printLL(head);

    Solution sol;
    sol.reorderList(head);

    cout << "----Reordered----" << endl;
    printLL(head);

    return 0;
}
