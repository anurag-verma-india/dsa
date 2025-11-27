
// Not working on all test cases
// https://leetcode.com/problems/diameter-of-binary-tree/description/
#include <bits/stdc++.h>

#include "./file_as_stdin.cpp"
#include "./read_int.cpp"

/*
Description:
    Given the root of a binary tree, return the length of the diameter of the tree.
    The diameter of a binary tree is the length of the longest path between any two nodes in a tree.
    This path may or may not pass through the root.
    The length of a path between two nodes is represented by
    the number of edges between them.

input:
    TreeNode* root

output:
    int diameter

approach:
    find the height of the left and right subtree
    (-1 in both heights to get path from them to the edge,
    then +1 in both to add the path from root the left and right, then add them)
    Effectively add heights of these trees

---
complexity

space:

time:

*/

struct TreeNode {
   public:
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {};
};

class Solution {
   public:
    int diameterOfBinaryTree(TreeNode* root) {
        int diameter = heightOfBinaryTree(root->left) + heightOfBinaryTree(root->right);
        return diameter;
    }
    int heightOfBinaryTree(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }
        queue<TreeNode*> q;
        q.push(root);
        q.push(nullptr);
        int height = 1;
        while (q.size() > 0) {
            TreeNode* node = q.front();
            q.pop();
            if (node == nullptr) {
                // It is the end of the level
                if (q.size() > 0) {
                    // But it is not the end of the tree
                    height++;
                    q.push(nullptr);  // to mark end of a level
                } else {
                    // It is the end of the level and tree
                    // Do nothing
                }
            } else {
                // It is just a normal node in a level
                if (node->left != nullptr) {
                    q.push(node->left);
                }
                if (node->right != nullptr) {
                    q.push(node->right);
                }
            }
        }
        return height;
    }
};
static int idx = -1;
TreeNode* buildTree(vector<int> preorder) {
    idx++;
    if (preorder[idx] == -1) {
        return nullptr;
    }
    TreeNode* node = new TreeNode(preorder[idx]);
    node->left = buildTree(preorder);
    node->right = buildTree(preorder);
    return node;
}

void printTreePreOrder(TreeNode* root) {
    if (root == nullptr) {
        cout << "-1 ";
        return;
    }
    cout << root->val << " ";
    printTreePreOrder(root->left);
    printTreePreOrder(root->right);
}

int main() {
    file_as_stdin("input.txt");
    vector<int> int_vec = read_int();

    TreeNode* root = buildTree(int_vec);
    cout << "Tree: ";
    printTreePreOrder(root);
    cout << endl;

    Solution sol;
    // int height = sol.heightOfBinaryTree(root);
    // cout << "Height of this tree: " << height << endl;
    int diameter = sol.diameterOfBinaryTree(root);
    cout << "Diameter of this tree: " << diameter << endl;

    cout << sol.heightOfBinaryTree(nullptr) << endl;

    return 0;
}