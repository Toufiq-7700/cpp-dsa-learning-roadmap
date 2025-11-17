#include<bits/stdc++.h>
using namespace std;

int main(){
    vector<int> stck;
    /*
        1. size
        2. push-> push_back
        3. pop-> pop_back
        4. peek-> back
        5. traversing
        6. empty
    */

    stck.push_back(7);
    stck.push_back(5);
    stck.push_back(3);
    cout<<stck.size()<<endl;
    stck.pop_back();
    cout<<stck.back()<<endl;

    /*for(int i=0;i<stck.size();i++){
        cout<<stck[i]<<" ";
    }*/
   
    for(int i:stck){
        cout<<i<<" ";
    }
}
