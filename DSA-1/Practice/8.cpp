#include<bits/stdc++.h>
#include<vector>
#include<algorithm>
#define long long ll;
using namespace std;
#define size 10
int stck[size], top = -1;

bool isFull(){
    return top == size-1;
}
bool isEmpty(){
    return top == -1;
}

void push(int x){
    if(isFull()){
        cout<<"Stack is Full..!!"<<endl;
        return;
    }
    top += 1;
    stck[top] = x;
}
int pop(){
    if (isEmpty())
    {
        cout<<"Underflow!!!"<<endl;
        return -1;
    }
    int item = stck[top];
    top -= 1;
    return item;
}

int peek(){
    return stck[top];
}

void print(){
    for(int i = 0; i<=top; i++){
        cout<<stck[i]<<"  ";
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


    return 0;
}