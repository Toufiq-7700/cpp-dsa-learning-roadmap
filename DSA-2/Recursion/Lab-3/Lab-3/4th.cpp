#include<bits/stdc++.h>
using namespace std;

int myfunc(int n){
    //3+5+7+9+11....+n
    if(n <= 0) return 0;
    if(n == 1) return 3;

    return myfunc(n-1) + (2*n + 1);

}

int main(){

    cout<<myfunc(5)<<endl;


    return 0;
}
