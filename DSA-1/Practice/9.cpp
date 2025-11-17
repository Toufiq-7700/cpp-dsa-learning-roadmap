#include<bits/stdc++.h>
#include<vector>
#include<algorithm>
#define long long ll;
using namespace std;

struct Node
{
    Node* next;
    int val;
};
Node* top = NULL;

bool isEmpty(){
    return top == NULL;
}

void push(int x){
    Node* newNode = new Node;
    newNode->val = x;
    newNode->next = NULL;

    newNode->next = top;
    top = newNode;
}

void pop(){
    Node*temp = top;
    top = top->next;
    delete temp;
}

int peek(){
    return top->val;
}

void print(){
    Node* ptr = top;
    while (ptr)
    {
        cout<<ptr->val<<"  ";
        ptr = ptr->next;
    }
    cout<<endl;
}



int main(){
    push(1);
    push(2);
    push(3);
    push(4);
    push(5);

    pop();

    print();

    cout<<peek()<<endl;

    return 0;
}