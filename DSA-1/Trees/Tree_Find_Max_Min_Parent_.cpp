#include<bits/stdc++.h>
using namespace std;

struct Node{
    int val;
    Node *left;
    Node *right;
};
Node *insertNode(Node *root,int v){
    if(root==NULL){
        Node *n = new Node;
        n->val = v;
        n->left = NULL;
        n->right = NULL;
        root = n;
    }
    else if(v<root->val){
        /// left side
        root->left = insertNode(root->left,v);
    }
    else if(v>root->val){
        /// right side
        root->right = insertNode(root->right,v);
    }
    return root;
}
void inorder(Node *root){
    if(root==NULL){
        return;
    }
    inorder(root->left);
    cout<<root->val<<"->";
    inorder(root->right);
}
int findMin(Node *root){
    if(root==NULL){
        return -1;
    }
    if(root->left==NULL){
        return root->val;
    }
    else{
        return findMin(root->left);
    }
}
int findMax(Node *root){
    if(root==NULL){
        return -1;
    }
    if(root->right==NULL){
        return root->val;
    }
    else{
        return findMax(root->right);
    }
}
bool searchItem(Node *root,int item){
    if (root == NULL) return false;
    if (root->val == item) return true;
    else if (item < root->val) return searchItem(root->left, item);
    else return searchItem(root->right, item);
}

Node* findParent(Node * root, int v){
    if (root == NULL && root->val == v) return NULL;

    if (root->left->val == v){
        return root;
    } 
    else if(root->right->val == v){
        return root;
    }


    if (v < root->val)return findParent(root->left, v);
    if(v>root->val) return findParent(root->right, v);


}
int main(){
    Node *root = NULL;
    root = insertNode(root,15);
    root = insertNode(root,9);
    root = insertNode(root,23);
    root = insertNode(root,4);
    root = insertNode(root,12);
    root = insertNode(root,20);
    root = insertNode(root,26);
    root = insertNode(root,2);
    root = insertNode(root,7);
    root = insertNode(root,13);
    root = insertNode(root,1);
    root = insertNode(root,5);
    root = insertNode(root,8);
    root = insertNode(root,14);
    root = insertNode(root,17);
    root = insertNode(root,22);
    root = insertNode(root,24);
    root = insertNode(root,29);
    root = insertNode(root,6);
    cout<<root->left->right->right->val<<endl;
    inorder(root);
    cout<<endl;
    cout<<"Mininum: "<<findMin(root)<<endl;
    cout<<"Maximum: "<<findMax(root)<<endl;


    cout<< searchItem(root,12)<<endl;

    cout<<findParent(root,20);
    return 0;
}