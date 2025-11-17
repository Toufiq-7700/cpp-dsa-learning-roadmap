#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node *next;
    Node *prev;
};
Node *head = NULL;
void insertAtFirst(int v){
    Node *newNode = new Node;
    newNode->data = v;
    newNode->next = NULL;
    newNode->prev = NULL;

    if(head==NULL){
        head = newNode;
        return;
    }
    newNode->next = head;
    head = newNode;
    newNode->next->prev = newNode;
    newNode->prev = newNode;
}
void insertAt(int v,int index){
    if(index<=0)
    {
        insertAtFirst(v);
        return;
    }
    Node *newNode = new Node;
    newNode->data = v;
    newNode->next = NULL;
    newNode->prev = NULL;
    int i=1;
    Node *ptr = head;
    while(ptr->next){
        if(i==index)
            break;
        i++;
        ptr = ptr->next;
    }
    
    newNode->next = ptr->next;
    ptr->next = newNode;
    newNode->next->prev = newNode;
    newNode->prev = ptr;
}




void print(){
    cout<<"--------Linked list-------"<<endl;
    Node *ptr = head;
    while(ptr!=NULL){
        cout<<ptr->data<<"->";
        ptr = ptr->next;
    }
    cout<<endl;
}
int main(){
    insertAt(5,0);
    insertAtFirst(17);
    insertAtFirst(10);
    insertAtFirst(2);
    insertAtFirst(7);
    insertAt(13,2);
    print();
    return 0;
}
