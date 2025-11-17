#include<bits/stdc++.h>
using namespace std;
struct Node{
    int val;
    Node *next;
};
Node *start = NULL;
Node *last = NULL;

void insertNode(int v){
    Node *n1 = new Node();
    n1->val = v;
    n1->next = NULL;

    if(start==NULL){
        start = n1;
        last = n1;
    }
    else{
        last->next = n1;
        last = n1;
    }
}
void print(){
    cout<<"-----Linked List----"<<endl;
    Node *tmp = start;
    while(tmp){
        cout<<tmp->val<<"->";
        tmp = tmp->next;
    }
    cout<<endl;
}
int main(){
    insertNode(10);
    insertNode(3);
    insertNode(15);
    insertNode(20);
    insertNode(7);
    print();
    return 0;
}
