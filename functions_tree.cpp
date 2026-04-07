#include <bits/stdc++.h>
using namespace std;
class TreeNode{
    public:
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

TreeNode* BuildTree(){
    int d;
    cin>>d;
    if(d==-1){
        return nullptr;
    }
    else{
        TreeNode* n=new TreeNode(d);
        n->left=BuildTree();
        n->right=BuildTree();
        return n;
    }
}
void printpreorder(TreeNode* root){
    if(root == nullptr){
        return;
    }
    cout<<root->val<<" ";
    printpreorder(root->left);
    printpreorder(root->right);
}
void printinorder(TreeNode* root){
    if(root==nullptr){
        return;
    }
    
    printinorder(root->left);
    cout<<root->val<<" ";
    printinorder(root->right);
}
void printpostorder(TreeNode* root){
    if(root==nullptr){
        return;
    }
    printpostorder(root->left);
    printpostorder(root->right);
    cout<<root->val<<" ";
}
void levelorder(TreeNode* root){
    if(root==nullptr){
        return;
    }
    queue<TreeNode*> q;
    q.push(root);
    q.push(nullptr);
    while(!q.empty()){
        TreeNode* temp=q.front();
        if(temp==nullptr){
            cout<<endl;
            q.pop();
            if(!q.empty()){
                q.push(nullptr);
            }
        }
        else{
            cout<<temp->val<<" ";
            q.pop();
            if(temp->left){
                q.push(temp->left);
            }
            if(temp->right){
                q.push(temp->right);
            }
        }
    }
}   

int countnode(TreeNode* root){
    if(root==nullptr){
        return 0;
    }
    return 1+countnode(root->left)+countnode(root->right);
}

int height(TreeNode* root){
    if(root==nullptr){
        return 0;
    }
    int h1=height(root->left);
    int h2=height(root->right);
    return 1+max(h1,h2);
}

int diameter(TreeNode* root){
    if(root==nullptr){
        return 0;
    }
    int op1=height(root->left)+height(root->right);
    int op2=diameter(root->left);
    int op3=diameter(root->right);
    return max(op1,max(op2,op3));
}
TreeNode* BuildlevelTree(){
    int d;
    cin>>d;
    TreeNode* root=new TreeNode(d);
    queue<TreeNode*> q;
    q.push(root);
    while(!q.empty()){
        TreeNode* temp=q.front();
        q.pop();
        int c1,c2;
        cin>>c1>>c2;
        if(c1!=-1){
            temp->left=new TreeNode(c1);
            q.push(temp->left);
        }
        if(c2!=-1){
            temp->right=new TreeNode(c2);
            q.push(temp->right);
        }
    }
    return root;

}
TreeNode* maketreeinorderandpreorder(vector<int> &pre, vector<int> &in ,int s,int e){
    int index=0;
    if(s>e){
        return nullptr;
    }
    int d=pre[index];
    TreeNode* root=new TreeNode(d);
    index++;
    int k=-1;
    for(int j=s;j<=e;j++){
        if(in[j]==d){
            k=j;
            break;
        }
    }
    root->left=maketreeinorderandpreorder(pre,in,s,k-1);
    root->right=maketreeinorderandpreorder(pre,in,k+1,e);
    return root;
}
TreeNode* maketreeinorderandpostorder(vector<int> &in,vector<int> &post ,int s,int e){
    int index=post.size()-1;
    if(s>e){
        return nullptr;
    }
    int d=post[index];
    TreeNode* root=new TreeNode(d);
    index--;
    int k=-1;
    for(int j=s;j<=e;j++){
        if(in[j]==d){
            k=j;
            break;
        }
    }
    root->right=maketreeinorderandpostorder(in,post,k+1,e);
    root->left=maketreeinorderandpostorder(in,post,s,k-1);
    return root;
}

void mirror(TreeNode* root){
    if(root==nullptr){
        return;
    }
    swap(root->left, root->right);
    mirror(root->left);
    mirror(root->right);
}

int main() {
    TreeNode* root = BuildlevelTree();
    printinorder(root);
    return 0;
}