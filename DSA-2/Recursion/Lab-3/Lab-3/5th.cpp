#include<bits/stdc++.h>
using namespace std;


int fib(int n){
    if(n == 1) return 1;
    if(n == 2) return 2;

    return fib(n-1) + fib(n-2);
}



int stair(int n){
    if(n <= 0)  return 0;
    if(n == 1) return 1;
    if(n == 2) return 2;

    return stair(n-1)+stair(n-2);

}

int main(){

cout<<"No of dist Ways: "<<stair(3)<<endl;


    return 0;
}

