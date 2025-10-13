
// t: 7ms, 52.5%; s: 15.2mb, 46,7%;
// https://leetcode.com/problems/copy-list-with-random-pointer/
#include <bits/stdc++.h>

#include "./file_as_stdin.cpp"
#include "./read_string.cpp"

/*
Description:

input:
    Node* head

output:
    Node* new_head: head of the newly copied linked list

approach:
    keep a hashmap of old addr to new addr  (addr_map)
    make all the new nodes in the first pass through the list
        add old_addr: new_addr entry in the addr_map

    in the second pass add assign new equivalents of the old addr to the new list

---
complexity

space:

time:

*/

// Definition for a Node.
class Node {
   public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }

    Node(int _val, Node* _next, Node* _random) {
        val = _val;
        next = _next;
        random = _random;
    }

    void set_next(Node* _next) {
        next = _next;
    }
    void set_random(Node* _random) {
        random = _random;
    }
};

class Solution {
   public:
    Node* copyRandomList(Node* head) {
        Node* temp = head;
        unordered_map<Node*, Node*> addr_map;  // old_addr: new_addr
        Node* n;

        Node* new_head = new Node(0);
        Node* prev = new_head;
        while (temp != nullptr) {
            // Making the new LL from old
            n = new Node(temp->val);
            prev->next = n;
            addr_map[temp] = n;

            prev = n;
            temp = temp->next;
        }
        temp = head;
        Node* new_temp = new_head->next;
        while (temp != nullptr) {
            if (temp->random == nullptr) {
                new_temp->random = nullptr;
            } else {
                new_temp->random = addr_map[temp->random];
            }

            new_temp = new_temp->next;
            temp = temp->next;
        }
        return new_head->next;
    }
};

void printLL(Node* root) {
    if (root == nullptr) {
        cout << "end" << endl;
        return;
    };
    printf("(addr: %p, val: %d, rnd: %p)\n", (void*)root, root->val, (void*)root->random);
    printLL(root->next);
}

int main() {
    file_as_stdin("input.txt");
    vector<string> str = read_string();
    // [[7,null],[13,0],[11,4],[10,2],[1,0]]

    // Making LL manually
    // Node* n0 = new Node(7);
    // Node* n1 = new Node(13);
    // Node* n2 = new Node(11);
    // Node* n3 = new Node(10);
    // Node* n4 = new Node(1);
    // n0->set_next(n1);
    // n1->set_next(n2);
    // n2->set_next(n3);
    // n3->set_next(n4);
    // n4->set_next(nullptr);

    // n0->set_random(nullptr);
    // n1->set_random(n0);
    // n2->set_random(n4);
    // n3->set_random(n2);
    // n4->set_random(n0);

    // cout << endl;
    // cout << endl;

    // printLL(n0);

    // cout << endl;
    // cout << endl;

    // Creating a vector from the given string
    vector<pair<int, int>> input_ll_vec;

    string ll_str = str[0];
    ll_str.erase(remove(ll_str.begin(), ll_str.end(), '['), ll_str.end());
    ll_str.erase(remove(ll_str.begin(), ll_str.end(), ']'), ll_str.end());
    string snum;

    stringstream ss(ll_str);

    while (getline(ss, snum, ',')) {
        if (snum == "null") {
            cout << "\nnull not expected as first argument" << endl;
            break;
        }
        pair<int, int> p;
        p.first = stoi(snum);
        if (!getline(ss, snum, ',')) {
            cout << "\nSecond argument not found" << endl;
            break;
        }
        if (snum == "null") {
            p.second = -1;
        } else {
            p.second = stoi(snum);
        }
        input_ll_vec.push_back(p);
    }

    // cout << "[";
    // for (auto vc : input_ll_vec) {
    //     cout << "[" << vc.first << ", " << vc.second << "], ";
    // }
    // cout << "]" << endl;

    // Building the linked list
    // input_ll_vec contains the pairs (val, random_pointer_idx)

    // Making and linking all the nodes
    Node* root = new Node(input_ll_vec[0].first);
    vector<Node*> address;
    address.push_back(root);

    for (int i = 1; i < (int)input_ll_vec.size(); i++) {
        Node* n = new Node(input_ll_vec[i].first);
        address[i - 1]->next = n;  // Giving segmentation fault
        address.push_back(n);
    }

    // Assigning the random pointers
    for (int i = 0; i < (int)input_ll_vec.size(); i++) {
        if (input_ll_vec[i].second == -1) {
            address[i]->random = nullptr;
            continue;
        }
        address[i]->random = address[input_ll_vec[i].second];
    }
    // printLL(address[0]);

    Solution sol;
    Node* new_ll = sol.copyRandomList(address[0]);
    cout << "Old" << endl;
    printLL(address[0]);

    cout << endl
         << "New" << endl;
    printLL(new_ll);

    return 0;
}