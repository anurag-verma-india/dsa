// 
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
    This approach uses a dummy node to simplify the code.
    1. Create a `dummy` node that will act as a placeholder for the start of the new list.
    2. Create a `tail` pointer, initially pointing to the `dummy` node.
    3. Iterate through both lists. In each step, set `tail->next` to the smaller node.
    4. After appending a node, advance the `tail` pointer (`tail = tail->next`).
    5. After the loop, the merged list starts at `dummy->next`.

---
complexity

space: O(1)
We are not creating any new nodes. We are just rearranging the pointers. We only use a constant amount of extra space for the dummy node and pointers.

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
        ListNode dummy;
        ListNode* tail = &dummy;

        while (list1 != nullptr && list2 != nullptr) {
            if (list1->val < list2->val) {
                tail->next = list1;
                list1 = list1->next;
            } else {
                tail->next = list2;
                list2 = list2->next;
            }
            tail = tail->next;
        }

        if (list1 != nullptr) {
            tail->next = list1;
        } else {
            tail->next = list2;
        }

        return dummy.next;
    }
};

void printLL(ListNode* head) {
    ListNode* temp = head;
    while (temp != nullptr) {
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
