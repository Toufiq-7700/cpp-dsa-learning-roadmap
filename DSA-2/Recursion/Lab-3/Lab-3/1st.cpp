#include<bits/stdc++.h>
using namespace std;

int sum(int n){
    if(n <= 0) return 0;
    //if(n == 1) return 1;

    return sum(n-1)+n;
}


int main(){

    int n;
    cout<< "Enter the val of N : ";
    cin>>n;

    cout<<"Sum of "<< n << "th term : "<< sum(n) << endl;


    return 0;
}
