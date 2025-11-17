#include<bits/stdc++.h>
using namespace std;
#define SIZE 10
int stck[SIZE],top = -1;

bool isFull(){
    return top == SIZE-1;
}
bool isEmpty(){
    return top == -1;
}

void push(int x){
    if(isFull()){
        cout<<"OVERFLOW"<<endl;
        return;
    }
    top = top + 1;
    stck[top] = x;
    cout<<"Successful"<<endl;
}

int pop(){
    if(isEmpty()){
        cout<<"UNDERFLOW"<<endl;
        return -1;
    }
    int item = stck[top];
    top = top - 1;
    return item;
}

int peek(){
    return stck[top];
}
void print(){
    cout<<"-----------Stack--------"<<endl;
    for(int i=0;i<=top;i++){
        cout<<stck[i]<<" ";
    }
    cout<<endl;
}
int main(){
    print();
    cout<<pop()<<endl;
    push(7);
    push(5);
    push(3);
    print();
    pop();
    print();
    return 0;
}
