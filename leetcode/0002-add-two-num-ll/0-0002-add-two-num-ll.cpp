
// https://leetcode.com/problems/add-two-numbers
#include <bits/stdc++.h>

#include "./file_as_stdin.cpp"
#include "./read_int.cpp"

/*
Description:
    You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order, and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.
    You may assume the two numbers do not contain any leading zero, except the number 0 itself.

    Example 1:
    Input: l1 = [2,4,3], l2 = [5,6,4]
    Output: [7,0,8]
    Explanation: 342 + 465 = 807.

    Example 2:
    Input: l1 = [0], l2 = [0]
    Output: [0]

    Example 3:
    Input: l1 = [9,9,9,9,9,9,9], l2 = [9,9,9,9]
    Output: [8,9,9,9,0,0,0,1]

    Constraints:

    The number of nodes in each linked list is in the range [1, 100].
    0 <= Node.val <= 9
    It is guaranteed that the list represents a number that does not have leading zeros.

input:
    ListNode l1: root of first LL
    ListNode l2: root of second LL

output:
    ListNode* sum_root: root of LL representing sum (in reverse order)

approach:
    init carry as 0
    create a new dummy node (dummy->next is root)
    Traverse the linked list
        Sum the two digits and the carry
        Make a new node with value %10 of the sum
        Make carry sum / 10 (floor division)
        if at any point curr_node1 or curr_node2 -> null
            point the curr_node->next to the sum->next

---
complexity

space:

time:
*/
// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
   public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0;
        ListNode* temp = new ListNode(0);
        ListNode* dummy = temp;
        ListNode* temp1 = l1;
        ListNode* temp2 = l2;
        while (temp1 != nullptr && temp2 != nullptr) {
            int sum = temp1->val + temp2->val + carry;
            ListNode* curr = new ListNode(sum % 10);
            temp->next = curr;
            carry = sum / 10;
            temp = curr;
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
        if (carry > 0) {
            // Add carry to which l1 or l2 remaining or make a new node
            if (temp2 != nullptr) {
                temp2->next->val = temp2->next->val + carry;
                temp->next = temp2->next;
            } else if (temp != nullptr) {
                temp1->next->val = temp1->next->val + carry;
                temp->next = temp1->next;
            } else {
                ListNode* carry_node = new ListNode(carry);
                temp->next = carry_node;
            }
        }
        return dummy->next;
    }
};

void printLL(ListNode* root) {
    ListNode* temp = root;
    while (temp != nullptr) {
        cout << temp->val << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    file_as_stdin("input.txt");
    vector<int> int_vec1 = read_int();
    vector<int> int_vec2 = read_int();
    // cout << "Input 1: ";
    // for (auto i : int_vec1) {
    //     cout << i << " ";
    // }
    // cout << endl;
    // cout << "Input 2: ";
    // for (int i : int_vec2) {
    //     cout << i << " ";
    // }
    ListNode* temp1 = new ListNode();
    ListNode* dl1 = temp1;  // dummy l1 (i.e. dl1->next = root of l1)
    ListNode* temp2 = new ListNode();
    ListNode* dl2 = temp2;  // dummy l2
    for (int i : int_vec1) {
        ListNode* temp = new ListNode(i);
        temp1->next = temp;
        temp1 = temp1->next;
    }
    for (int i : int_vec2) {
        ListNode* temp = new ListNode(i);
        temp2->next = temp;
        temp2 = temp2->next;
    }
    ListNode* l1 = dl1->next;
    ListNode* l2 = dl2->next;

    cout << "Linked List 1: ";
    printLL(l1);
    cout << "Linked List 2: ";
    printLL(l2);

    Solution sol;
    ListNode* sum_root = sol.addTwoNumbers(l1, l2);
    printLL(sum_root);
    return 0;
}