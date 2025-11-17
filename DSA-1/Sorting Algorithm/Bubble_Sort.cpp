#include<bits/stdc++.h>
using namespace std;
void bubble_sort(int a[],int n){
    int i,j,cnt=0,flag;
    for(i=0;i<n;i++){
        flag = 0;
        //cout<<"Iteration #"<<i+1<<":"<<endl;

        for(j=0;j<n-1-i;j++){
            cnt++;

            if(a[j]>a[j+1]){
                flag = 1;
                swap(a[j],a[j+1]);
            }
            // for(int k = 0; k<n;k++){
            //     cout<<a[k]<<" ";
            // }
            //cout<<endl;
        }
        if(flag==0)break;
    }
    cout<<" No of iterations: "<<cnt<<endl;
}
int main(){
    int n, arr[10];
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    bubble_sort(arr,n);

    cout<<"---------- Sorted Array----------"<<endl;
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}
