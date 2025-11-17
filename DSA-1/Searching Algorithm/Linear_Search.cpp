#include<bits/stdc++.h>
using namespace std;

int linear_search(int a[],int n,int item){
    for(int i=0;i<n;i++){
        if(a[i]==item)
            return i;
    }
    return -1;
}
int main(){
    int arr[10],n,i,item;
    cout<<"Enter an integer : ";
    cin>>n;

    for(i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<"Enter the searched item : ";
    cin>>item;

    int res = linear_search(arr,n,item);
    if(res<0){
        cout<<item<<" is not found";
    }
    else{
        cout<<item<<" is found at index "<<res;
    }
    return 0;
}
