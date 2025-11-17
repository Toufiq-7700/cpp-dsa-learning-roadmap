#include<bits/stdc++.h>
using namespace std;
#define SIZE 5

int Q[SIZE],F=-1,R=-1;

bool isEmpty(){
    return F==-1;
}

bool isFull(){
    return R==SIZE-1;
}
void enqueue(int item){
    if(isFull()){
        cout<<"OVERFLOW"<<endl;
        return;
    }
    if(F==-1){
        F = R = 0;
    }
    else{
        R = R + 1;
    }
    Q[R] = item;
}
int dequeue(){
    if(isEmpty()){
        cout<<"UNDERFLOW"<<endl;
        return -1;
    }
    int item = Q[F];
    if(F==R){
        F = R = -1;
    }
    else{
        F = F + 1;
    }
}
void print(){
    cout<<"-------QUEUE---------"<<endl;
    for(int i=F;i<=R;i++){
        cout<<Q[i]<<" ";
    }
    cout<<endl;
}
int main(){
    dequeue();
    enqueue(9);
    dequeue();
    enqueue(10);
    enqueue(3);
    enqueue(15);
    print();
    dequeue();
    print();
    enqueue(17);
    print();
    return 0;
}
