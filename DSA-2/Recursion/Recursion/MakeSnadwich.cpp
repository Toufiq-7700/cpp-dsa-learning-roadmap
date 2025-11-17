#include<iostream>
using namespace std;

int makeSandwich(int n, int m){
    //n--> breads, m==> eggs
    //we need 2 breads and 3 eggs to make a sandwich
    //then how many sandwiches you can make using n breads and m eggs
    if(n < 2 || m < 3) return 0;
    return 1 + makeSandwich(n-2, m-3);
}

int makeCar(int x, int y, int z){
    //You have x rectangle blocks, y circle blocks and z triangle blocks
    //You need 2 rectangle, 3 circle and 1 triangle to make a car
    //how many cars you can make
    if(x < 2 || y < 3 || z < 1) return 0;
    return 1 + makeCar(x-2, y-3, z-1);
}

int main(){
    int breads = 10, eggs = 7;
    int s = makeSandwich(breads, eggs);
    cout << "no of sandwich : " << s << endl;
}
