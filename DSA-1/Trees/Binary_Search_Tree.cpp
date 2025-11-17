#include<bits/stdc++.h>
using namespace std;
//Binary Search Tree   BST


class Node{
    public:
    int data;
    Node *left,*right;
    Node(int val){
        data = val;
        left = right = NULL;
    }
};

//Insertation
Node* insert(Node *root, int val){
    //base case
    if(root == NULL){
        Node* temp = new Node(val);
        return temp;
    }
     
    if(root->data > val)//left side
    {
        root->left = insert(root->left,val);
    }
    else{
        root->right = insert(root->right,val);
    }


    return root;
}

void inorder(Node *root){
    if(!root) return;
    inorder(root->left);
    cout<<root->data<<"  ";
    inorder(root->right);
}


//searching
bool search(Node *root, int target){
    if(!root) return 0;

    if(root->data == target) return 1;
    else if (root->data > target)
    {
        return search(root->left,target);
    }
    else{
        return search(root->right,target);
    }

}


//Delation
Node* Delete(Node* root, int target){

    //Base
     if(!root) return NULL;
     if(root->data > target){
        root->left = Delete(root->left, target);
        return root;
     }
     else if(root->data < target){
        root->right = Delete(root->right, target);
        return root;
     }
     else{
        //Leaf Node
        if(!root->left && !root->right){
            delete root;
            return NULL;
        }
        else if(!root->right){
            Node * temp = root->left;
            delete root;
            return temp;
        }
        else if(!root->left){
            Node * temp = root->right;
            delete root;
            return temp;
        }
        else{
            Node* child = root->left;
            Node* parent = root;

            while (child->right)
            {
                parent = child;
                child = child->right;
            }
            
            if(root != parent){
                parent->right = child->left;
                child->left = root->left;
                child->right = root->right;
                delete root;
                return child;
            }
            else{
                child->right = root->right;
                delete root;
                return child;
            }
        }
     }
}


int main(){
    int arr[]={1,9,2,4,6,8,11,14,26,13};
    Node *root = NULL;

    for (size_t i = 0; i < 10; i++)
    {
        root = insert(root,arr[i]);
    }

    inorder(root);
    cout<<endl;

    // (search(root,26 )) ? cout<<"YES"<<endl:cout<<"NO"<<endl;

    Delete(root,9);
    cout<<"After delation the tree :  ";
    inorder(root);

    return 0;
}