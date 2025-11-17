#include<bits/stdc++.h>
using namespace std;

int seriesSum(int n){
    if(n <= 0) return 0;
    if(n == 1) return 1;

    return seriesSum(n-3)+n;
}


int main(){
    int n;
    cout<< "Enter the val of N series : ";
    cin>>n;

    cout<<"Sum of "<< n << "th series : "<< seriesSum(n) << endl;





    return 0;
}
