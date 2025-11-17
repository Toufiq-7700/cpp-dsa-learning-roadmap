#include<iostream>
using namespace std;

int Sum(int n){
    //1+2+..+n
    if(n<=0) return 0;
    if(n==1) return 1;
    return Sum(n-1) + n;
}
int mySeries(int n){
    //1+4+7+10+...
    //f(1)= 1; f(4) = 1 + 4; f(7) = 1 + 4 + 7;
    if(n==1) return 1;
    return mySeries(n-1) + 3;
}
int newSeries(int n){
    //2+6+10+..
    //f(n) = returns the sum of the 1st n terms of the series
    //f(1) = 2; f(2) = 2 + 6; f(3) = 2 + 6 + 10
    if(n==1) return 2;
    return newSeries(n-1) + (4*n -2);
}
int myNewSewries(int n){
    //3+5+7+...
    //f(n) = returns the sum of the 1st n terms of the series
    //f(1) = 3; f(2) = 3 + 5; f(3) = 3 + 5 + 7
    if(n==1) return 3;
    return myNewSewries(n-1) + (2*n + 1);
}
int main(){
    int n = 4;
    int sum = Sum(n);
    cout << "sum upto " << n << " : " << sum << endl;

    sum = mySeries(n);
    cout << "mySeries sum " << n << " : " << sum << endl;

    sum = newSeries(n);
    cout << "newSeries sum " << n << " : " << sum << endl;

    sum = myNewSewries(n);
    cout << "myNewSewries sum " << n << " : " << sum << endl;
}

