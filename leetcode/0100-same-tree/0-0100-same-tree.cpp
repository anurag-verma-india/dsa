
// t: 0ms, 100%; s: 12.74 mb, 77.42%;
// https://leetcode.com/problems/same-tree/
#include <bits/stdc++.h>

#include "./file_as_stdin.cpp"
#include "./read_string.cpp"

/*
Description:

input:
    TreeNode* p
    TreeNode* q

output:
    bool isSameTree

approach:
    for each node check
        either they both are nullptr
        or if the values are equal
          then call the check function for left and right of the current node

        otherwise if they both are not null or have different values
            then set isSameTree to false

---
complexity

space:

time:

*/

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class Solution {
    bool areSame = true;

    void compareNodes(TreeNode* p, TreeNode* q) {
        if (p == nullptr && q == nullptr) {
            return;
        }
        if ((p == nullptr && q != nullptr) || (p != nullptr && q == nullptr)) {
            areSame = false;
            return;
        }
        // Both p & q are not null
        if (p->val != q->val) {
            areSame = false;
        }
        compareNodes(p->left, q->left);
        compareNodes(p->right, q->right);
        return;
    };

   public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        compareNodes(p, q);
        return areSame;
    }
};

TreeNode* buildTreeLevelOrder(vector<string> lvlOrder) {
    /*
    Initialize a queue with the root node

    for each subsequent val in the array
    make new nodes attach them to left and right of the current top node
    add them to the queue
    do this until either the queue is empty or the array is over
    */
    if (lvlOrder.empty() || lvlOrder[0] == "null") {
        return nullptr;
    }
    int n = lvlOrder.size();
    queue<TreeNode*> q;
    TreeNode* root = new TreeNode(stoi(lvlOrder[0]));  // We are sure that lvlOrder[0] is not "null"
    q.push(root);
    int i = 1;  // we already used lvlOrder[0]
    while (!q.empty() && i < n) {
        TreeNode* node = q.front();
        q.pop();

        // already checked i < n
        if (lvlOrder[i] != "null") {
            node->left = new TreeNode(stoi(lvlOrder[i]));
            q.push(node->left);
        }
        i++;

        if (i < n && lvlOrder[i] != "null") {
            node->right = new TreeNode(stoi(lvlOrder[i]));
            q.push(node->right);
        }
        i++;
    }
    return root;
}

void printTreeLevelOrder(TreeNode* root) {
    queue<TreeNode*> q;
    q.push(root);
    // cout << "Tree (level order): ";
    while (!q.empty()) {
        TreeNode* node = q.front();
        q.pop();
        if (node == nullptr) {
            cout << "null ";
        } else {
            cout << node->val << " ";
        }
        if (node != nullptr) {
            q.push(node->left);
            q.push(node->right);
        }
    }
    // cout << endl;
}

int main() {
    file_as_stdin("input.txt");
    vector<string> int_vec_p = read_string();
    vector<string> int_vec_q = read_string();

    // vector<string> int_vec_p = {"1", "2", "3"};
    TreeNode* root_p = buildTreeLevelOrder(int_vec_p);
    cout << "Tree p: ";
    printTreeLevelOrder(root_p);
    cout << endl;

    TreeNode* root_q = buildTreeLevelOrder(int_vec_q);
    cout << "Tree q: ";
    printTreeLevelOrder(root_q);
    cout << endl;

    Solution sol;
    string ans = sol.isSameTree(root_p, root_q) ? "true" : "false";
    cout << "is same tree: " << ans << endl;

    return 0;
}