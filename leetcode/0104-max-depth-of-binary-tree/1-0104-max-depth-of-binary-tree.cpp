// t: 0ms, 100%; m: 19.27 mb, 12.75%;
// https://leetcode.com/problems/maximum-depth-of-binary-tree/description/
#include <bits/stdc++.h>

#include "./file_as_stdin.cpp"
#include "./read_int.cpp"

/*
Description:
    Given the root of a binary tree, return its maximum depth.
    A binary tree's maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.

input:
    TreeNode root

output:
    int depth: max depth of the tree

approach:
    initialize the queue with root node addr followed by nullptr,
    depth var to 0

    while queue is not empty
        if curr != null
            add left and right to queue (if they are not null)
        if curr == null
            depth++
        pop current node


    otherwise just add left and right to queue

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
    int maxDepth(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }
        queue<TreeNode*> q;
        int depth = 1;
        q.push(root);
        q.push(nullptr);
        while (q.size() != 0) {
            TreeNode* node = q.front();
            q.pop();
            if (node == nullptr) {
                if (!q.empty()) {
                    depth++;
                    if (!q.empty()) {
                        // This was not the last node
                        // Just the end of this level
                        q.push(nullptr);
                    }
                }
            } else {
                if (node->left != nullptr) {
                    q.push(node->left);
                }
                if (node->right != nullptr) {
                    q.push(node->right);
                }
            }
        }
        return depth;
    }
};

static int idx = -1;
TreeNode* build_tree(vector<int> preorder) {
    idx++;
    if (preorder[idx] == -1) {
        return nullptr;
    }
    TreeNode* root = new TreeNode(preorder[idx]);
    root->left = build_tree(preorder);
    root->right = build_tree(preorder);
    return root;
}

void printTree(TreeNode* root) {
    if (root == nullptr) {
        cout << "-1 ";
        return;
    }
    cout << root->val << " ";
    printTree(root->left);
    printTree(root->right);
    return;
}

int main() {
    file_as_stdin("input.txt");
    // cout << "Reading input" << endl;
    vector<int> int_vec = read_int();

    // cout << "building tree"<< endl;
    TreeNode* root = build_tree(int_vec);

    cout << "Tree: ";
    printTree(root);
    cout << endl;

    // cout << "Finding max depth" << endl;
    Solution sol;
    int depth = sol.maxDepth(root);

    cout << "Depth of this tree is " << depth << endl;

    return 0;
}