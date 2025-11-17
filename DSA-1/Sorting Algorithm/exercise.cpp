//Sorting with the product of two elements
#include<bits/stdc++.h>
using namespace std;
struct product{
    int w;
    int p;
};
int main(){
    int n;
    product prod[10];
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>prod[i].w>>prod[i].p;
    }
    for(int i=0;i<n;i++){

        for(int j=0;j<n-i-1;j++){
            
            if(prod[j].p/prod[j].w<prod[j+1].p/prod[j+1].w){
                product tmp = prod[j];
                prod[j] = prod[j+1];
                prod[j+1] = tmp;
            }
        }
    }
    cout<<"----------Sorted Array--------"<<endl;
    for(int i=0;i<n;i++){
        cout<<prod[i].w<<" "<<prod[i].p<<endl;
    }
    return 0;
}
