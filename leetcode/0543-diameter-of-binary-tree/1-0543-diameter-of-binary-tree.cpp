// t: 275ms, 10%; m: 23.92mb, 13%;
// https://leetcode.com/problems/diameter-of-binary-tree/description/

// https://www.youtube.com/watch?v=aPyDPImR5UM
// First brute force approach
// Also, building tree from array level-order representation

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

    find diameter of left subtree
    find diameter of right subtree

    keeping track of the maximum diameter that we have found

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

// Solution v1
class Solution {
   public:
    // int maxDia = 0;
    int diameterOfBinaryTree(TreeNode* root) {
        // int currDia = height(root->left) + height(root->right);
        // return max(maxDia, currDia);
        if (root == nullptr) return 0;
        int leftDiameter = diameterOfBinaryTree(root->left);
        int rightDiameter = diameterOfBinaryTree(root->right);
        // maxDia = max(maxDia, height(root->left) + height(root->right));
        int currDiameter = height(root->left) + height(root->right);
        return max(currDiameter, max(leftDiameter, rightDiameter));
    }

    int height(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }

        return max(height(root->left), height(root->right)) + 1;
    }
};

TreeNode* buildTreeFromLevelOrder(vector<string> lvlOrder) {
    /*
    we are assuming that the given vector represents a complete binary tree
    (with null to indicate missing nodes)

    start out with a queue that only has the root node

    for each subsequent value on the vector
    if that value is less than size of the vector
        make new nodes with those values and add them to left and right of the current node
        and also add them to the queue
     */
    if (lvlOrder.empty() || lvlOrder[0] == "null") {
        return nullptr;
    }
    int n = lvlOrder.size();
    queue<TreeNode*> q;
    TreeNode* root = new TreeNode(stoi(lvlOrder[0]));
    q.push(root);
    int i = 1;
    while (!q.empty() && i < n) {
        TreeNode* node = q.front();
        q.pop();

        // We are sure that i < n
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

void printTreePreOrder(TreeNode* root) {
    if (root == nullptr) {
        cout << "null ";
        return;
    }
    cout << root->val << " ";
    printTreePreOrder(root->left);
    printTreePreOrder(root->right);
}

void printTreeLevelOrder(TreeNode* root) {
    queue<TreeNode*> q;
    q.push(root);
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
}

int main() {
    file_as_stdin("input2.txt");
    // file_as_stdin("input3.txt");
    vector<string> string_vec = read_int_as_string();

    // for (string s : string_vec) {
    //     cout << s << " ";
    // }

    TreeNode* root = buildTreeFromLevelOrder(string_vec);

    // cout << "Tree (pre order): ";
    // printTreePreOrder(root);
    // cout << endl;
    cout << "Tree (level order): ";
    printTreeLevelOrder(root);
    cout << endl;

    Solution sol;
    int height = sol.height(root);
    int diameter = sol.diameterOfBinaryTree(root);

    cout << "Height of this tree: " << height << endl;
    cout << "Diameter of this tree: " << diameter << endl;
    return 0;
}