#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {};
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {};
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {};
};

static int idx = -1;
TreeNode* buildTreeFromPreOrder(vector<int> preorder) {
    idx++;
    if (idx >= (int)preorder.size()) return nullptr;
    if (preorder[idx] == -1) return nullptr;
    TreeNode* root = new TreeNode(preorder[idx]);
    root->left = buildTreeFromPreOrder(preorder);
    root->right = buildTreeFromPreOrder(preorder);
    return root;
}

TreeNode* buildTreeFromLevelOrder(vector<string> lvlOrder) {
    /*
    we are assuming that the given vector represents a complete binary tree
    (with null to indicate missing nodes)

    start out with a queue that only has the root node

    for each subsequent value in the vector
    if that value's idx is less than size of the vector and the queue has more nodes
    (since we need some nodes to attach new ones to)
        make new nodes with those values and add them to left and right of the current node
        and also add them to the queue
        also skip them if they are null,
        because null ptrs don't have child nodes,
        so we don't need to add them to queue;
        and every new node created already has null on it's left and right,
        so we don't need to do anything to the nodes either)

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
    cout << "Tree (level order): ";
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
    cout << endl;
}

int main() {
    vector<string> levelOrder = {"1", "2", "2", "3", "3", "null", "null"};
    TreeNode* rootLvlOrder = buildTreeFromLevelOrder(levelOrder);
    printTreeLevelOrder(rootLvlOrder);

    // Assuming -1 is null
    vector<int> preOrder = {1, 2, 3, -1, -1, 3, -1, -1, 2, -1, -1};
    TreeNode* rootPreOrder = buildTreeFromPreOrder(preOrder);
    cout << "Tree (pre order): ";
    printTreePreOrder(rootPreOrder);
    cout << endl;
}