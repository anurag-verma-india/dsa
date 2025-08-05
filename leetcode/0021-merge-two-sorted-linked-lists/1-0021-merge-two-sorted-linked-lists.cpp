
// https://leetcode.com/problems/merge-two-sorted-lists/
#include <bits/stdc++.h>

#include "./file_as_stdin.cpp"
#include "./read_int.cpp"

/*
Description:
You are given the heads of two sorted linked lists list1 and list2.
Merge the two lists into one sorted list. The list should be made by splicing together the nodes of the first two lists.
Return the head of the merged linked list.

input:
    list1, list2: Heads of two lists

output:
    head: head of merged list

approach:

---
complexity

space: O(1)
We are not creating any new nodes. We are just rearranging the pointers. We only use a constant amount of extra space for pointers.

time: O(m+n)
We iterate through both lists once, where m and n are the lengths of the two lists.

*/

//  Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
   public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
    }
};

void printLL(ListNode* head) {
    ListNode* temp = head;
    while (temp != nullptr) {
        cout << temp->val << " ";
        temp = temp->next;  // We don't need to preserve head in this situation
    }
    cout << endl;
}

int main() {
    file_as_stdin("input.txt");
    vector<int> int_vec = read_int();

    ListNode* curr = nullptr;
    ListNode* prev = nullptr;
    ListNode* head1 = nullptr;
    for (int i = 0; i < (int)int_vec.size(); i++) {
        curr = new ListNode(int_vec[i]);
        if (head1 == nullptr) {
            head1 = curr;
        }
        if (prev != nullptr) {
            prev->next = curr;
        }
        prev = curr;
    }

    int_vec = read_int();
    curr = nullptr;
    prev = nullptr;
    ListNode* head2 = nullptr;
    for (int i = 0; i < (int)int_vec.size(); i++) {
        curr = new ListNode(int_vec[i]);
        if (head2 == nullptr) {
            head2 = curr;
        }
        if (prev != nullptr) {
            prev->next = curr;
        }
        prev = curr;
    }

    cout << "----List1----" << endl;
    printLL(head1);
    cout << "----List2----" << endl;
    printLL(head2);

    Solution sol;
    ListNode* mergedHead = sol.mergeTwoLists(head1, head2);

    cout << "----Merged----" << endl;
    printLL(mergedHead);

    return 0;
}