#include <bits/stdc++.h>
using namespace std;
class TreeNode{
    public:
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int d) {
        val=d;
        left=nullptr;
        right=nullptr;
    }
};

// Insertion in BST
TreeNode* insertinbst(TreeNode* root,int data){
    if (root==nullptr){
        root=new TreeNode(data);
        return root;
    }
    else if(data<=root->val){
        root->left=insertinbst(root->left,data);
    }
    else{
        root->right=insertinbst(root->right,data);
    }
    return root;

}

TreeNode* buildtree(){
    int d;
    cin>>d;
    TreeNode* root=nullptr;
    while(d!=-1){
        root=insertinbst(root,d);
        cin>>d;
    }
    return root;
}

// Searching in BST
TreeNode* search(TreeNode* root,int key){
    if(root==nullptr){
        return nullptr;
    }
    if(root->val==key){
        return root;
    }
    else if(root->val<key){
        return search(root->right,key);
    }
    else{
        return search(root->left,key);
    }
}

// Checking BST or Not
bool isbst(TreeNode* root,int minv=INT_MIN,int maxv=INT_MAX){
    if(root==nullptr){
        return true;
    }
    if(root->val>=minv and root->val<=maxv and isbst(root->left,minv,root->val) and isbst(root->right,root->val,maxv)){
        return true;
    }
    return false;
}

// BST using sorted array
TreeNode* arraytobst(int* a,int s,int e){
    if(s>e){
        return nullptr;
    }
    int mid=(s+e)/2;
    TreeNode* root=new TreeNode(a[mid]);
    root->left=arraytobst(a,s,mid-1);
    root->right=arraytobst(a,mid+1,e);
    return root;
}

// Height Balanced Tree
class Pair{
    public:
    int height;
    bool balance;
};
Pair heightbalanced(TreeNode* root){
    Pair p;
    if(root==nullptr){
        p.height=0;
        p.balance=true;
        return p;
    }
    Pair left=heightbalanced(root->left);
    Pair right=heightbalanced(root->right);
    if(left.balance and right.balance and abs(left.height-right.height)<=1){
        p.balance=true;
    }
    else{
        p.balance=false;
    }
    p.height=max(left.height,right.height)+1;
    return p;
}

// Convert BST to linked list

int main() {
    
    return 0;
}