// https://www.youtube.com/watch?v=R-CKBYnOv1U&list=PLfqMhTWNBTe137I_EPQd34TsgV6IO55pt&index=59
// T 100, M 40 (Same as 0- w/ minor changes)
// https://leetcode.com/problems/reverse-linked-list
#include <bits/stdc++.h>

#include "./file_as_stdin.cpp"
#include "./read_int.cpp"

/*
Description:
Given the head of a singly linked list, reverse the list, and return the reversed list.

input:
    ListNode* head: ptr to head of LL

output:
    ListNode* newHead: head of reversed LL

approach:
    traverse the LL (while currNode != nullptr)
    change links
        initialize prevNode with nullptr
        replace next of current node to prevNode
        save current node's address in prevNode
        change currentNode to point to currentNode's next
        continue

---
complexity

space: O(1)
We are not using any extra space that is proportional to the input size. We are only using a few pointers to keep track of the nodes.

time: O(n)
We are iterating through the linked list once.

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
    ListNode* reverseList(ListNode* head) {
        ListNode* curr = head;
        ListNode* prevNode = nullptr;
        ListNode* nextNode = nullptr;

        while (curr != nullptr) {
            // cout << "Current Node: " << curr->val << endl;
            nextNode = curr->next;  // replace nxt node w/ head's next
            curr->next = prevNode;
            // Prepare for the next iteration
            prevNode = curr; 
            curr = nextNode;
        }
        return prevNode;
    }
};

void printLL(ListNode* head) {
    ListNode* temp = head;
    while (temp != nullptr) {
        cout << temp->val << " ";
        temp = temp->next; // We don't need to preserve head in this situation
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
    printLL(head);

    Solution sol;
    ListNode* reverseHead = sol.reverseList(head);

    cout << "----Reverse----" << endl;

    printLL(reverseHead);

    return 0;
}
