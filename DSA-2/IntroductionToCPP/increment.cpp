#include<iostream>
using namespace std;

void increment(int &x){
    x++;
}
void Max(int a, int b, int &m){
    if(a>b) m = a;
    else m = b;
}

int main(){
    int y = 10;
    cout << "before increment:" << y << endl;
    increment(y);
    cout << "after increment:" << y << endl;
    int a = 12, b = 54, c;
    Max(a, b, c);
    cout << "Max : " << c << endl;
}
