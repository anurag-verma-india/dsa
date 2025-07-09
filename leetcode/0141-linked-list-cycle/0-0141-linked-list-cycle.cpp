
// T 49%, S 7%
#include <bits/stdc++.h>

#include "./file_as_stdin.cpp"
#include "./read_int.cpp"

/*
Description:
Given head, the head of a linked list, determine if the linked list has a cycle in it.
There is a cycle in a linked list if there is some node in the list that can be reached again by continuously following the next pointer. Internally, pos is used to denote the index of the node that tail's next pointer is connected to. Note that pos is not passed as a parameter.
Return true if there is a cycle in the linked list. Otherwise, return false.

input:
    LL* head: ptr to LL head

output:
    int pos: position of start of cycle

approach:

    Create a set that stores the address of each occurring node
    (start form head)

    iterate over linked list
        check if the next address is already present in the set
        if yes return true
        otherwise add the address to the set

---
complexity

space:

time:

*/

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
   public:
    bool hasCycle(ListNode* head) {
        // ListNode* temp = head;
        set<ListNode*> addrSet;
        // ListNode dummy(0);

        ListNode* temp = new ListNode(0);
        temp->next = head;

        while (temp->next != nullptr) {
            if (addrSet.count(temp->next)) {
                return true;
            }
            addrSet.insert(temp->next);
            temp = temp->next;
        }
        return false;
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

    // ListNode* curr = nullptr;
    // ListNode* prev = nullptr;
    // ListNode* head = nullptr;
    // for (int i = 0; i < (int)int_vec.size(); i++) {
    //     curr = new ListNode(int_vec[i]);
    //     if (head == nullptr) {
    //         head = curr;
    //     }
    //     if (prev != nullptr) {
    //         prev->next = curr;
    //     }
    //     prev = curr;
    // }

    ListNode* temp = nullptr;
    ListNode* head = new ListNode(3);
    temp = head;
    temp->next = new ListNode(2);
    ListNode* cycleSt = temp->next;
    temp = temp->next;

    temp->next = new ListNode(0);
    temp = temp->next;

    temp->next = new ListNode(-4);
    temp = temp->next;
    // temp->next = cycleSt;

    // cout << "----List----" << endl;
    // printLL(head);

    Solution sol;
    // bool cycle = sol.hasCycle(head);
    string res = sol.hasCycle(head) ? "true" : "false";

    cout << "LL contains cycle: " << res << endl;

    return 0;
}