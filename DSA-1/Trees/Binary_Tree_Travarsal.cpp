//Binary Tree travarsal

#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node *left, *right;
    Node(int val){
        data = val;
        left = right = NULL;
    }
};

Node* binaryTree(){
    int x;
    cin>>x;
    if(x == -1) return NULL;
    Node *temp = new Node(x);
    cout<<"Enter the left child of "<<x<<" ";
    temp->left = binaryTree();
    cout<<"Enter the right child of "<<x<<" ";
    temp->right = binaryTree();

    return temp;
}

void Pre_Order(Node * root){
    if(root == NULL) return;
    cout<<root->data<<"  ";
    Pre_Order(root->left);
    Pre_Order(root->right);
}
void In_Order(Node *root){
    if(!root)return;
    In_Order(root->left);
    cout<<root->data<<"  ";
    In_Order(root->right);
}
void Post_Order(Node *root){
    if(!root)return;
    Post_Order(root->left);
    Post_Order(root->right);
    cout<<root->data<<"  ";
}

int main(){
    cout<<"Enter the Root ";
    cout<<endl;
    Node *root;
    root = binaryTree();

    cout<<"Tree in Pre Order .... "; 
    Pre_Order(root);
    cout<<endl;

    cout<<"Tree in IN Order .... ";
    In_Order(root);
    cout<<endl;

    cout<<"Tree in Post Order .... ";
    Post_Order(root);
    cout<<endl;


    return 0;
}