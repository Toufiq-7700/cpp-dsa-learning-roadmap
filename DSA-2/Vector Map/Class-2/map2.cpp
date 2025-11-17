#include<bits/stdc++.h>
#include<vector>
#include<map>
using namespace std;

int main(){
    string s,t;
    cin>>s>>t;
    unordered_map<char,char> mp1,mp2;

    for(int i; i<s.length(); i++){
        char c1=s[i],c2=t[i];

        if(mp1.count(c1) && mp1[c1] != c2){
            cout<<"Not Isomorphoic"<<endl;
            break;
        }
        if(mp2.count(c2) && mp2[c2] != c1){
            cout<<"Not Isomorphoic"<<endl;
            break;
        }

        mp1[c1] = c2;
        mp1[c2] = c1;
    }


    cout<<"Isomorphoic"<<endl;
    

    

    return 0;
}
