#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node *next;
};

Node *head = NULL;

void insertAtFirst(int v){
    Node *newNode = new Node;
    newNode->data = v;
    newNode->next = NULL;

    newNode->next = head;
    head = newNode;
}

void insertAtLast(int v){
    Node * newNode = new Node;
    newNode->data = v;
    newNode->next = NULL;

    if(head==NULL){
        head = newNode;
        return;
    }

    Node *ptr = head;
    while(ptr->next!=NULL){
        ptr = ptr->next;
    }
    ptr->next = newNode;
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
int deleteFrom(int index){
    if(head==NULL)
        return -1;
    int i=1;
    Node *ptr = head;
    while(ptr->next!=NULL){
        if(i == index-1)
            break;
        i++;
        ptr = ptr->next;
    }
    Node *tmp = ptr->next;
    ptr->next = tmp->next;
    int item = tmp->data;
    delete tmp;
    return item;
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
    insertAtLast(13);
    insertAtFirst(7);
    insertAtFirst(10);
    insertAtFirst(2);
    insertAtFirst(17);
    insertAt(9,3);
    insertAt(5,0);
    print();
    cout<<deleteFrom(3)<<endl;
    print();
    return 0;
}

