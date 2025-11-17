#include<bits/stdc++.h>
using namespace std;
struct Node
{
   int data;
   Node* next;
   Node* prev;
};
Node* head = NULL;

void insertFirst(int val){
    Node* newNode = new Node;
    newNode->data = val;
    newNode->next = NULL;
    newNode->prev = NULL;

    if (head == NULL)
    {
        head = newNode;
        return;
    }

    newNode->next = head;
    head = newNode;
    newNode->next->prev = newNode;
}


void insertLast(int val){
    
    if(head == NULL){
        insertFirst(val);
        return;
    }
    Node* newNode = new Node;
    newNode->data = val;
    newNode->next = NULL;
    newNode->prev = NULL;

    Node* ptr = head;

    while (ptr->next)
    {
        ptr = ptr->next;
    }
    cout<<"Last ptr is  "<<ptr->data<<endl;
    
    ptr->next = newNode;
    newNode->prev = ptr;


}

void insertAt(int val, int index){
    if (index<=0)
    {
        insertFirst(val);
        return;
    }

    Node* newNode = new Node;
    newNode->data = val;
    newNode->next = NULL;
    newNode->prev = NULL;

    Node* ptr = head;
    int i = 1;
    while (ptr->next)
    {
        if (i == index)
        {
            break;
        }
        i++;
        ptr = ptr->next;
    }

    newNode->next = ptr->next;
    ptr->next = newNode;
    newNode->next->prev = newNode;
    newNode->prev = ptr;
}

void deleteMiddleAndmiddleprev(){
    int size = 0, i = 1;
    Node* ptr = head;
    while(ptr != NULL){
        size++;
        ptr = ptr->next;
    }
    cout<<"Initial size of ARRAY  "<<size<<endl;
   int index = size/2;
   cout<<"Middle index is  "<<index<<endl;

   Node* p = head;
   while (i<index)
   {
      p = p->next;
      i++;    
   }
  
   Node* prevOfMiddle = p;
   Node* middle = p->next;
   Node* aftermiddle = middle->next;

   cout<<"Value of P   "<< p->data<<endl;
   cout<<"Value of prevOfMiddle   "<< prevOfMiddle->data<<endl;
   cout<<"Value of aftermiddle   "<< aftermiddle->data<<endl;
   cout<<"Value of middle   "<< middle->data<<endl;


   prevOfMiddle->prev->next = aftermiddle->next;
   aftermiddle->prev = prevOfMiddle->prev;

   delete middle;
   delete prevOfMiddle;

}

int deleteIndex(int index){
    if (head == NULL)
        return -1;

    int i = 1;
    Node* ptr = head;

    while (ptr != NULL) {  
        if (i == index)  
            break;
        i++;
        ptr = ptr->next;
    }
    ptr->prev->next = ptr->next;
    ptr->next->prev = ptr->prev;
    delete ptr;
    return 0;
}

void print(){
    Node* ptr = head;
    while (ptr != NULL)
    {
        cout<<ptr->data<<"  ";
        ptr = ptr->next;
    }
    cout<<endl;
}

int main(){
   

    print();


    return 0;
}