#include<bits/stdc++.h>
using namespace std;

int makecar(int x, int y, int z){
    // rectangle 2, circle 3, triangle 1

    if(x < 2 || y < 3 || z < 1) return 0;

    return makecar(x-2, y-3, z-1) + 1;

}



int main(){
    int x, y , z;
    cout<< "Enter x : ";
    cin>>x;
    cout<<endl;
    cout<< "Enter y : ";
    cin>>y;
    cout<<endl;
    cout<< "Enter z : ";
    cin>>z;
    cout<<endl;

    int ans = makecar(x,y,z);

    cout<< "Total : "<< ans <<endl;

    return 0;
}


