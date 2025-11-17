#include<bits/stdc++.h>
using namespace std;
struct Node
{
   int data;
   Node* next;
};
Node* head = NULL;

void insertFirst(int val){
    Node* newNode = new Node;
    newNode->data = val;
    newNode->next = NULL;

    newNode->next = head;
    head = newNode;
}

void insertLast(int val){
    Node* newNode = new Node;
    newNode->data = val;
    newNode->next = NULL;

    Node* ptr = head;
    while (ptr->next != NULL)
    {
        ptr = ptr->next;
    }
    ptr->next = newNode;
    
}

void insertAt(int val, int index){
    Node* newNode = new Node;
    newNode->data = val;
    newNode->next = NULL;

    Node* ptr = head;
    int i = 1;
    while (ptr->next != NULL)
    {
        if(i == index) break; //index start with 0 || (100,3) => 3  2  1  100  0  -1
        
        ptr = ptr->next;
        i++;

    }
    cout<<"PTR is "<<ptr->data<<endl;

    newNode->next = ptr->next;
    ptr->next = newNode;
    
}

int deleteAt(int index){
    Node* temp = new Node;
    Node* ptr = head;
    int i = 1;
    
    while (ptr->next != NULL)
    {
        if(i == index) break; 
        
        ptr = ptr->next;
        i++;
    }

    temp = ptr->next;
    ptr->next = temp->next;
    int item = temp->data;
    delete temp;

    return item;
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


int main(){

    insertFirst(1);
    insertFirst(2);
    insertFirst(3);

    insertLast(0);
    insertLast(-1);

    insertAt(100,3);
    deleteAt(3);


    print();


    return 0;
}

