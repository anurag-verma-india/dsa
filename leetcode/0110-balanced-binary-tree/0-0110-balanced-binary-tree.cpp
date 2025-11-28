// t: 0ms, 100%; s: 23%, 5.9mb;
// https://leetcode.com/problems/balanced-binary-tree/
#include <bits/stdc++.h>

#include "./file_as_stdin.cpp"
#include "./read_string_space_sep.cpp"

/*
Description:
    Given a binary tree, determine if it is height-balanced.
    height-balanced: height of left and right subtree of any node differs by not more than 1
    i.e. dfference between heights is either 0 or 1

input:
    TreeNode* root

output:
    bool isBalanced

approach:
    call height function
    after calculating left and right height at each point
    if the difference is more than 1 return false
    if then function call does not return any false then return true

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
   public:
    bool balanced = true;
    bool isBalanced(TreeNode* root) {
        height(root);
        return balanced;
    }
    int height(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }
        int leftHt = height(root->left);
        int rightHt = height(root->right);

        if (abs(leftHt - rightHt) > 1) {
            balanced = false;
        }

        return max(leftHt, rightHt) + 1;
    }
};

TreeNode* buildTreeFromLevelOrder(vector<string> lvl) {
    /*
    (if first val is null, or vector is empty just return a nullptr
    to indicate a tree with 0 nodes)

    make a queue, q to keep track of the nodes from previous level
    (we will attach new nodes in the next level to these)

    init with just a new node that is root and add that to queue

    for each subsequent node
    while the queue is not empty
    (since we need some nodes from previous lvl to attach new nodes to)
    and the idx is less then given vector's size
        if the next idx is not null
            make a new node attach to the q top


        increment idx and check if idx < n
            then do the same for right node

        then increment idx and continue


    after this is over make return root node's addr
    */
    int n = lvl.size();
    if (n <= 0 || lvl[0] == "null") {
        return nullptr;
    }
    queue<TreeNode*> q;
    int i = 1;
    TreeNode* root = new TreeNode(stoi(lvl[0]));
    q.push(root);

    while (!q.empty() && i < n) {
        TreeNode* node = q.front();
        q.pop();

        // just checked i < n
        if (lvl[i] != "null") {
            node->left = new TreeNode(stoi(lvl[i]));
            q.push(node->left);
        }
        i++;

        if (i < n && lvl[i] != "null") {
            node->right = new TreeNode(stoi(lvl[i]));
            q.push(node->right);
        }
        i++;
    }

    return root;
}

void printTree(TreeNode* root) {
    queue<TreeNode*> q;
    q.push(root);
    while (!q.empty()) {
        TreeNode* node = q.front();
        q.pop();
        if (node == nullptr) {
            cout << "null ";
        } else {
            cout << node->val << " ";
            q.push(node->left);
            q.push(node->right);
        }
    }
}

int main() {
    file_as_stdin("input.txt");
    vector<string> str = read_string_space_sep();

    // TreeNode* node = new TreeNode(5);
    // cout << node->val << endl;

    TreeNode* root = buildTreeFromLevelOrder(str);
    cout << "Tree: ";
    printTree(root);
    cout << endl;

    Solution sol;
    bool balanced = sol.isBalanced(root);

    cout << "Is balanced: " << (balanced ? "true" : "false") << endl;

    return 0;
}