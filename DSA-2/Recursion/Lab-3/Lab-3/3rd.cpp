#include<bits/stdc++.h>
using namespace std;

int newseriessum(int n){
    //2+6+10+14....+n
    if(n <= 0) return 0;
    if(n == 1) return 2;

    return newseriessum(n-1) + (4*n-2);


}

int main(){

    cout<<newseriessum(4)<<endl;


    return 0;
}
