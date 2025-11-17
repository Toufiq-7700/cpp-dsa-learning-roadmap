//Search odd digits in a Array
#include<bits/stdc++.h>
using namespace std;
bool is_odd(int num){
    int digits = 0;
    while(num){
        digits++;
        num = num/10;
    }

    if(digits%2==0)
    {
        return false;
    }
    else
    {
        return true;
    }
}
int linear_search(int a[],int n){
    int cnt = 0;
    for(int i=0;i<n;i++){
        if(is_odd(a[i]))
            cnt++;
    }
    return cnt;
}
int main(){
    int arr[10],n,i;
    cin>>n;

    for(i=0;i<n;i++){
        cin>>arr[i];
    }
    int res = linear_search(arr,n);
    cout<<"Odd numbers "<<res;
    return 0;
}

