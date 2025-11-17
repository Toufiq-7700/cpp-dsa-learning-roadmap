#include<bits/stdc++.h>
using namespace std;


int sand(int a, int b){

    if(a < 2 || b < 3) return 0;


    return sand(a-2, b-3) + 1;

}



int main(){
    int n,m;
    cout<< "Enter n : ";
    cin>>n;
    cout<<endl;
    cout<< "Enter m : ";
    cin>>m;
    cout<<endl;

    int ans = sand(n,m);

    cout<< "Total Sandwiches : "<< ans <<endl;

    return 0;
}


