#include <bits/stdc++.h>
using namespace std;
class node{
    public:
    int data;
    node* left;
    node* right;
    node(int n){
        data=n;
        left = NULL;
        right = NULL;
    }
};
// this insert for a bst 
node* insert1(node* root, int n) {
    if (root == NULL) {
        return new node(n);
    }
    if (n < root->data) {
        root->left = insert1(root->left, n);
    } else {
        root->right = insert1(root->right, n);
    }
    return root;
}
// this insert for normal binary tree
node* insert(node* root, int n) {
    if (root == NULL) {
        return new node(n);
    }
    
    queue<node*> q;
    q.push(root);

    while (!q.empty()) {
        node* temp = q.front();
        q.pop();

        // Insert as left child if empty
        if (temp->left == NULL) {
            temp->left = new node(n);
            return root;
        } else {
            q.push(temp->left);
        }

        // Insert as right child if empty
        if (temp->right == NULL) {
            temp->right = new node(n);
            return root;
        } else {
            q.push(temp->right);
        }
    }
    return root;
}
void inorder(node* root) {
    if (root == NULL) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}
int main() {
    node* root = NULL;
    root = insert(root, 5);
    root = insert(root, 3);
    root = insert(root, 7);
    root = insert(root, 2);
    root = insert(root, 4);
    root = insert(root, 6);
    root = insert(root, 8);
    cout << "Inorder traversal of the binary tree: ";
    inorder(root);
    return 0;
}