//Create Employee Structure
#include<bits/stdc++.h>
using namespace std;
struct Employee{
    int ID;
    string name;
    float salary;
};
void check(Employee emp[], int n){
    for(int i=0;i<n;i++){
        if(emp[i].name[0]=='a' && emp[i].salary>500){
            cout<<emp[i].ID<<" ";
        }
    }
}
int main(){
    Employee e[10];
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>e[i].ID>>e[i].name>>e[i].salary;
    }

    cout<<"----------Employee Information-------"<<endl;
    for(int i=0;i<n;i++){
        cout<<e[i].ID<<" "<<e[i].name<<" "<<e[i].salary<<endl;
    }
    check(e,n);
}


