#include<iostream>
using namespace std;

int DistinctWays(int n){
    if(n<=0) return 0;
    if(n <= 2 ) return n;
    return DistinctWays(n-1) + DistinctWays(n-2) + DistinctWays(n-3);
}

int FindNthTerm(int n){
    //find the nth term of the following series
    //1, 2, 5, 8, 11, 14
    //f(1) = 1; f(2) = 2; f(3) = 5; f(4) = 4
    if(n==1 || n==2) return n;
    return FindNthTerm(n-1) + 3;
}

int main(){
    int n = 4;
    int d = DistinctWays(n);
    cout << "no of distinct ways: " << d << endl;
}
