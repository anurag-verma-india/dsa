// t: 0ms, 100%; s: 20mb, 13%;
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
    follow the level order traversal (iterative approach)

    make a queue, add root to the queue, then a NULL to mark the end of level on
    initialize maxDepth with 1 (if root is not null)

    while queue is not empty
    add left and right of current node to the queue
    but if current node is null
        and queue is not empty (add 1 to the maxDepth)
        add NULL to the queue (since all elements of the next level have been added to the queue)

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
        if (root == nullptr) return 0;
        queue<TreeNode*> q;
        q.push(root);
        q.push(nullptr);
        int depth = 1;
        while (q.size() > 0) {
            TreeNode* curr = q.front();
            q.pop();
            if (curr == nullptr) {
                if (!q.empty()) {
                    depth++;
                    q.push(nullptr);
                    continue;
                } else {
                    break;
                }
            }
            if (curr->left != nullptr) {
                q.push(curr->left);
            }
            if (curr->right != nullptr) {
                q.push(curr->right);
            }
        }
        return depth;
    }
};

static int idx = -1;
TreeNode* buildTree(vector<int> tree_vec) {
    idx++;
    if (tree_vec[idx] == -1) {
        return nullptr;
    }
    TreeNode* root = new TreeNode(tree_vec[idx]);
    root->left = buildTree(tree_vec);
    root->right = buildTree(tree_vec);
    return root;
}

void PrintTree(TreeNode* treeNode) {
    if (treeNode == nullptr) {
        cout << "-1 ";
        return;
    }
    cout << treeNode->val << " ";
    PrintTree(treeNode->left);
    PrintTree(treeNode->right);
    return;
}

int main() {
    file_as_stdin("input.txt");
    vector<int> int_vec = read_int();
    TreeNode* root = buildTree(int_vec);
    PrintTree(root);
    cout << endl;
    Solution sol;
    int depth = sol.maxDepth(root);
    cout << "Max depth of tree is: " << depth << endl;
    return 0;
}