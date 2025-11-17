#include<iostream>
#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

class Person{
    public:
    int age;
    string name;

    bool operator<(const Person &other)const{
        return age < other.age;
    }

};

int main(){
    set<Person> s;

    Person p1,p2,p3;
    p1.name = "Toufiq", p1.age = 10;
    p2.name = "Imroz", p2.age = 20;
    p3.name = "Topu", p3.age = 30;

    s.insert(p1);
    s.insert(p2);
    s.insert(p3);


    for(auto it = s.begin(); it != s.end(); it++){
        cout<<it->name<<" "<<it->age<<endl;
    }

    
    cout<<endl;

    return 0;
}
