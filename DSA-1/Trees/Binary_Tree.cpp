#include<bits/stdc++.h>
using namespace std;
#include<queue>

class Node{
    public:
    int data;
    Node *left, *right;

    Node(int val){
        data = val;
        left = right = NULL;
    }

};

void Pre_Order(Node * root){
    if(root == NULL) return;
    cout<<root->data<<"  ";
    Pre_Order(root->left);
    Pre_Order(root->right);
}

int main(){
    int x,first,second;
    cout<<"Enter the root element "<<endl;
    cin>>x;

    queue<Node*> q;

    Node *root = new Node(x);
    q.push(root);

    //Build the binary tree;
    while(!q.empty()){
        Node *temp = q.front(); 
        q.pop();
        //Left Node
        cout<<"Enter the left child of "<<temp->data<<" : ";
        cin>>first;
        if(first != -1){
            temp->left = new Node(first);
            q.push(temp->left);
        }
        //Right Node
        cout<<"Enter the right child of "<<temp->data<<" : ";
        cin>>second;
        if (second != -1){
            temp->right = new Node(second);
            q.push(temp->right);
        } 
    }


    cout<<endl;
    cout<<"Tree in pre-order : ";
    Pre_Order(root);


    return 0;
}