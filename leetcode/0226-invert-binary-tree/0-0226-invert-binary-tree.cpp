// t: 0ms, 100%; s: 12.5mb, 60%;
// https://leetcode.com/problems/invert-binary-tree/
#include <bits/stdc++.h>

#include "./file_as_stdin.cpp"
#include "./read_int.cpp"

/*
Description:

input:
    TreeNode* root

output:
    TreeNode* inv_root: root of the inverted binary tree

approach:
    For each node we just need to invert it's left and right nodes

    Traverse each node in preorder traversal
    right = Node->right
    Node->right = Node->left
    Node->left = right

    invert(Node->right)
    invert(Node->left)
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
    TreeNode* invertTree(TreeNode* root) {
        if (root == nullptr) {
            return nullptr;
        }
        TreeNode* right = root->right;
        root->right = root->left;
        root->left = right;
        invertTree(root->left);
        invertTree(root->right);
        return root;
    }
};

static int idx = -1;
TreeNode* buildTree(vector<int> preorder) {
    idx++;
    if (preorder[idx] == -1) {
        return nullptr;
    }
    TreeNode* root = new TreeNode(preorder[idx]);
    root->left = buildTree(preorder);
    root->right = buildTree(preorder);
    return root;
}

void preOrder(TreeNode* root) {
    if (root == nullptr) {
        cout << "-1 ";
        return;
    }
    cout << root->val << " ";
    preOrder(root->left);
    preOrder(root->right);
}

int main() {
    file_as_stdin("input.txt");
    vector<int> int_vec = read_int();
    TreeNode* root = buildTree(int_vec);

    cout << "Before: ";
    preOrder(root);
    cout << endl;

    Solution sol;
    sol.invertTree(root);
    cout << "After: ";
    preOrder(root);
    cout << endl;
    return 0;
}