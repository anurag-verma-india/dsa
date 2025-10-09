#include <iostream>
#include <queue>
#include <vector>
using namespace std;

class Node {
   public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
// 2 build tree
/*
Time Complexity: O(n)
 */
static int idx = -1;
Node* buildTree(vector<int> preOrder) {
    idx++;
    if (preOrder[idx] == -1) return NULL;
    Node* root = new Node(preOrder[idx]);
    root->left = buildTree(preOrder);
    root->right = buildTree(preOrder);
    return root;
}

// 3 preorder traversal
/*
Time Complexity: O(n)
*/
void pre_order(Node* root) {
    if (root == NULL) {
        cout << "-1 ";
        return;
    }
    cout << root->data << " ";
    pre_order(root->left);
    pre_order(root->right);
}
// 4 Inorder
// Time complexity: O(n)
void inorder(Node* root) {
    if (root == NULL) {
        // cout << "-1 ";
        return;
    }
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

// 5 postorder
void postorder(Node* root) {
    if (root == NULL) {
        return;
    }
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

// 6 Level order traversal
void level_order(Node* root) {
    queue<Node*> q;

    q.push(root);
    q.push(NULL);
    while (q.size() > 0) {
        Node* curr = q.front();
        q.pop();

        if (curr == NULL) {
            if (!q.empty()) {
                cout << endl;
                q.push(NULL);
                continue;
            } else {
                break;
            }
        }

        cout << curr->data << " ";
        if (curr->left != NULL) {
            q.push(curr->left);
        }
        if (curr->right != NULL) {
            q.push(curr->right);
        }
    }
    cout << endl;
}

int main() {
    vector<int> preorder_tree = {1, 2, -1, -1, 3, 4, -1, -1, 5, -1, -1};
    Node* root = buildTree(preorder_tree);

    // cout << endl;
    // cout << root->data << endl;
    // cout << root->left->data << endl;
    // cout << root->right->data << endl;

    // pre_order(root);
    // cout << endl;

    // inorder(root);
    // cout << endl;

    // postorder(root);
    // cout << endl;

    level_order(root);
    return 0;
}
