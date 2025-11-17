#include<iostream>
#include<bits/stdc++.h>
#include<algorithm>

using namespace std;
int main(){
    //set<int> s;
    set<int,greater<int>>s;
    s.insert(4);
    s.insert(6);
    s.insert(1);
    s.insert(3);
    s.insert(100);

    s.erase(1);

    if(s.find(3) != s.end()) cout<<"present"<<endl;
    else cout<<"Not in Set"<<endl;

    if(s.count(1))cout<<"Yes"<<endl;
    else cout<<"NO"<<endl;


    for(auto x : s){
        cout<<x<<" ";
    }
    cout<<endl;

    return 0;
}
