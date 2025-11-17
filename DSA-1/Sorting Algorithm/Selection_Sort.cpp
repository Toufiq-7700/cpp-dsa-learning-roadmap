#include<bits/stdc++.h>
using namespace std;

void selection_sort(int a[],int n){

    for(int i=0;i<n;i++){
        int min = i;

        for(int j=i+1;j<n;j++){
            if(a[j]<a[min]){
                min = j;
            }
        }
        
        swap(a[i] , a[min]);
    }
}
int main(){
    int n, arr[10];
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    
    selection_sort(arr,n);

    cout<<"---------- Sorted Array----------"<<endl;
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}

