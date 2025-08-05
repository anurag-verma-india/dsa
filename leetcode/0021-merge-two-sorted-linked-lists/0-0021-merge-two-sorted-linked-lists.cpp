// T 1%, S 62%
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
    temp1 & temp2 to keep track of the values
    initialize new head as the smaller of the two nodes' val

    Find the smaller of the two addresses
    Make the prevNode's next smaller of the two
    Move the temp of that list to point to next

    if ptr of any one of the list is null then just make the prevNode's next point to the other one
    (cuz this this list is over and return head)

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
        ListNode* head = nullptr;
        ListNode* prevNode = nullptr;
        ListNode* temp1 = list1;
        ListNode* temp2 = list2;

        // If any one the list's length is 0, the merged list is simply the other one
        if (list1 == nullptr) return list2;
        if (list2 == nullptr) return list1;

        //  initialize the head of merged list w/ the smaller of the two
        if (temp1->val < temp2->val) {
            head = temp1;
            cout << "start: " << temp1->val << " ";
            temp1 = temp1->next;
        } else {
            head = temp2;
            cout << "start: " << temp1->val << " ";
            temp2 = temp2->next;
        }

        cout << endl;
        prevNode = head;
        while (temp1 != nullptr && temp2 != nullptr) {
            cout << "temp1: " << temp1->val << ", " << "temp2: " << temp2->val << endl;
            if (temp1->val < temp2->val) {
                prevNode->next = temp1;
                temp1 = temp1->next;
            } else {
                prevNode->next = temp2;
                temp2 = temp2->next;
            }
            prevNode = prevNode->next;
        }

        // Append the list that is left
        if (temp1 == nullptr) {
            prevNode->next = temp2;
            cout << "last: " << temp2->val << endl;
        } else {
            prevNode->next = temp1;
            cout << "last: " << temp1->val << endl;
        }

        return head;
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