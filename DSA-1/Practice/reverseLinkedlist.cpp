#include<bits/stdc++.h>
using namespace std;
struct Node
{
   int data;
   Node* next;
};
Node *head = NULL;
void insertAtFirst(int v){
    Node *newNode = new Node;
    newNode->data = v;
    newNode->next = NULL;

    newNode->next = head;
    head = newNode;
}
void insertAt(int v,int index){
    if(index<=0){
        insertAtFirst(v);
        return;
    }
    
    Node *newNode = new Node;
    newNode->data = v;
    newNode->next = NULL;

    int i=0;
    Node *ptr = head;
    while(ptr->next!=NULL){
        if(i==index-1)
            break;
        i++;
        ptr = ptr->next;
    }
    newNode->next = ptr->next;
    ptr->next = newNode;
}
void reverse(){
    Node* prev = NULL;
    Node* curr = head;
    Node* next = NULL;

    while (curr != NULL) {
        next = curr->next;  
        curr->next = prev;   
        prev = curr;        
        curr = next;         
    }
    head = prev; 
}


void print(){
    Node* ptr = head;
    while (ptr)
    {
        cout<<ptr->data<<"  ";
        ptr = ptr->next;
    }
    cout<<endl;
}

int main(){

    insertAt(1,0);
    insertAt(2,1);
    insertAt(3,2);
    insertAt(4,3);
    insertAt(5,4);
    cout<<"LIST......... before reverse  "<<endl;
    print();

    reverse();
    cout<<"LIST......... after reverse  "<<endl;
    print();


    return 0;
}