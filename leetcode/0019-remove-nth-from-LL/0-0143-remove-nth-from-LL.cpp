
// t: 0ms - 100%, s: 15mb - 92%
// https://leetcode.com/problems/reorder-list/
#include <bits/stdc++.h>

#include "./file_as_stdin.cpp"
#include "./read_int.cpp"

/*
Description:
    19. Remove Nth Node From End of List
    Medium
    Topics
    premium lock icon
    Companies
    Hint
    Given the head of a linked list, remove the nth node from the end of the list and return its head.

    Example 1:
    Input: head = [1,2,3,4,5], n = 2
    Output: [1,2,3,5]

    Example 2:
    Input: head = [1], n = 1
    Output: []

    Example 3:
    Input: head = [1,2], n = 1
    Output: [1]

    Constraints:

    The number of nodes in the list is sz.
    1 <= sz <= 30
    0 <= Node.val <= 100
    1 <= n <= sz

input:
    ListNode* head: head of LL
    int n: nth position from the right supposed to be removed

output:
    ListNode* head: head of the LL with the nth node from the right removed

approach:
    cout the length of the LL
    index of node to be removed, rm = len - (n - 1)
                                    = len - n + 1
    traverse to the rm'th element and remove it  (free it's memory too)

---
complexity
time:

space:

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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // printLL(head);
        // cout << "n: " << n << endl;
        // return head;
        ListNode* temp = head;
        int ln = 0;

        while (temp) {
            ln++;
            temp = temp->next;
        }
        cout << "Length: " << ln << endl;

        int rm = ln - n + 1;

        int c = 1;  // Lowest possible value is 1, since 1 based indexing
        ListNode* prev = new ListNode(0, head);
        ListNode* prevOfHead = prev;
        temp = head;
        while (c != rm) {
            prev = temp;
            temp = temp->next;
            c++;
        }

        ListNode* rm_node = prev->next;
        prev->next = temp->next;

        ListNode* result = prevOfHead->next;
        delete rm_node;
        delete prevOfHead;
        // return head != nullptr ? head : prev->next;
        return result;
    }
};

int main() {
    file_as_stdin("input.txt");
    vector<int> int_vec = read_int();
    int n;

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

    cin >> n;  // nth position from the left

    cout << "---- List ----" << endl;
    printLL(head);

    Solution sol;
    head = sol.removeNthFromEnd(head, n);

    cout << "---- Answer ----" << endl;
    printLL(head);

    return 0;
}
