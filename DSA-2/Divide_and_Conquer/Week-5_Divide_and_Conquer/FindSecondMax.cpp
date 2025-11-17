#include<bits/stdc++.h>
using namespace std;
struct FindSecondMax
{
    int m1 ;
    int m2 ;
};

FindSecondMax FindMax(int a[],int i,int j){
    if(i==j) {
        FindSecondMax m;
        m.m1 = a[i];
        m.m2 = INT_MIN;
        return m;
    }
    if(i==j-1){
        FindSecondMax m;
        if(a[i]>a[j]){
            m.m1=a[i];
            m.m2=a[j];
        }
        else{
            m.m1=a[j];
            m.m2=a[i];
        }
        return m;
    }
    int mid=(i+j)/2;
    
    FindSecondMax temp1 = FindMax(a,i,mid);
    FindSecondMax temp2 = FindMax(a,mid+1,j);

    FindSecondMax temp;

    if(temp1.m1 > temp2.m1){
        temp.m1 = temp1.m1;
        temp.m2 = max(temp1.m2,temp2.m1);
    }
    else{
        temp.m1 = temp2.m1;
        temp.m2 = max(temp1.m1,temp2.m2);
    }

    return temp;
}
int main(){
    int a[]={14,3,6,32,7,87,9,55,34,65,23,55,67,4,886};
    int n=sizeof(a)/sizeof(a[0]);
    FindSecondMax ans = FindMax(a,0,n-1);

    cout<<"First Max : "<<ans.m1<<", Second Max : "<<ans.m2<<endl;
}
