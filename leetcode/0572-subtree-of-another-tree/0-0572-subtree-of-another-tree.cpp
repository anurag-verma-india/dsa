
// https://leetcode.com/problems/subtree-of-another-tree/
#include <bits/stdc++.h>

#include "./file_as_stdin.cpp"
#include "./read_int.cpp"

/*
Description:

input:
    TreeNode* root
    TreeNode* subRoot

output:
    bool isSubTree

approach:
    for each node check if could be a subtree

    start from the root node
        check if this tree matches the subtree
        then check it's left and right if they match do this recursively

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
    bool isSameTree() {
        /*
        Base case if both nodes 
        */
    }

   public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
    }
};

TreeNode* BuildTreeLevelOrder(vector<string> v) {
    /**
     * If vector is not empty make first node
     * Make a queue to keep track of the nodes
     * Loop over each value in the inp vector until either the queue is empty or the string is over
     *     keep a reference of the top node (queue) and pop it
     *     Make a new node and attach it to the current node, both left and right
     *     (if it's not null and there are still values left in the vector)
     *     also add these newly created nodes to the queue and we'll skip all null nodes
     *
     */
    int n = v.size();
    if (n < 0 || v[0] == "null") {
        return nullptr;
    }

    queue<TreeNode*> q;
    // 0 is not null
    TreeNode* root = new TreeNode(stoi(v[0]));
    q.push(root);
    int i = 1;
    while (!q.empty() && i < n) {
        TreeNode* node = q.front();
        q.pop();

        if (v[i] != "null") {
            node->left = new TreeNode(stoi(v[i]));
            q.push(node->left);
        }
        i++;

        if (i < n && v[i] != "null") {
            node->right = new TreeNode(stoi(v[i]));
            q.push(node->right);
        }
        i++;
    }
    return root;
}

void PrintTreeLevelOrder(TreeNode* root) {
    /**
     * Make a queue and add root to it
     * while the queue is not empty
     *     if the current top node is not null
     *         print the node's val (or null)
     *     add it's left and right values to the queue
     */
    queue<TreeNode*> q;
    q.push(root);
    cout << endl;
    while (!q.empty()) {
        if (q.front() == nullptr) {
            cout << "null ";
        } else {
            cout << q.front()->val << " ";
            q.push(q.front()->left);
            q.push(q.front()->right);
        }
        q.pop();
    }
    cout << endl;
}

int main() {
    file_as_stdin("input.txt");
    vector<string> int_vec1 = read_int();
    vector<string> int_vec2 = read_int();

    // cout << "1: \n";
    // for (string s : int_vec1) {
    //     cout << s << " ";
    // }
    // cout << endl;
    // cout << "2: \n";
    // for (string s : int_vec2) {
    //     cout << s << " ";
    // }
    // cout << endl;

    TreeNode* mainTree = BuildTreeLevelOrder(int_vec1);
    TreeNode* subTree = BuildTreeLevelOrder(int_vec2);

    PrintTreeLevelOrder(mainTree);
    PrintTreeLevelOrder(subTree);

    return 0;
}