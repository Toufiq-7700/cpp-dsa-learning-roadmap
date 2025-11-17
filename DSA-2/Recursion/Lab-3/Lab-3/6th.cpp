#include<bits/stdc++.h>
using namespace std;

//1,2,5,8,......
int findnthterm(int n){
    if(n <= 0) return 0;
    if(n == 1) return 1;
    if(n == 2) return 2;

    return findnthterm(n-1) + 3;

}

int main(){

    cout<<findnthterm(5)<<endl;

    return 0;
}


