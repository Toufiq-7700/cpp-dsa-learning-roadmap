#include<bits/stdc++.h>
using namespace std;
struct Node{
    int val;
    Node *next;
};
Node *F = NULL;
Node *R = NULL;

void enqueue(int v){
    Node *n1 = new Node();
    n1->val = v;
    n1->next = NULL;

    if(F==NULL){
        F = n1;
        R = n1;
    }
    else{
        R->next = n1;
        R = n1;
    }
}
int dequeue(){
    if(F==NULL){
        cout<<"UNDERFLOW"<<endl;
        return -1;
    }
    Node *tmp = F;
    int item = F->val;
    if(F==R){
        F = R = NULL;
        delete tmp;
    }
    else{
        F = F->next;
        delete tmp;
    }
    return item;
}
void print(){
    cout<<"-----Linked List----"<<endl;
    Node *tmp = F;
    while(tmp){
        cout<<tmp->val<<"->";
        tmp = tmp->next;
    }
    cout<<endl;
}
int main(){
    enqueue(10);
    enqueue(3);
    enqueue(15);
    enqueue(20);
    enqueue(7);
    print();
    cout<<dequeue();
    print();
    return 0;
}
