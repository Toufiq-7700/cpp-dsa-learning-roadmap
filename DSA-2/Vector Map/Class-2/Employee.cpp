#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Employee{
    string name;
    double salary;
public:
    int id;
    Employee(string n, int id, double s):name(n), id(id), salary(s) {
        //constructor body
    }
    void display(){
        cout<<"name:"<<name<<" id:"<<id<<" salary:"<<salary<<endl;
    }
    double getSalary(){
        return salary;
    }
    void Increment(double percentage){
        salary += salary * percentage/100;
    }
};

void Print(vector<Employee> employees){
    //using index
    /*for(int i = 0 ; i < employees.size() ; i++){
        employees[i].display();
    }*/
    for(Employee e : employees)
        e.display();
}

bool CompareID(Employee e1, Employee e2){
    return e1.id < e2.id;//ascending
    //return e1.id > e2.id;//descending
}

bool CompareSalary(Employee e1, Employee e2){
    return e1.getSalary() > e2.getSalary() ;
}

int main(){
    vector<Employee> emp = { Employee("Rahim", 2, 8000),
                                Employee("Karim", 1, 15000)
     };
     Employee e1("Abir", 4, 9000);
     emp.push_back(e1);
     emp.push_back( Employee("Roni", 3, 18000) );
     cout<<"Printing the Employees:"<<endl;
     Print(emp);
     //update the id at index 2
     emp[2].id = 6;
     cout<<"after updating the id:" << endl;
     emp[2].display();
     cout<<"Employees with salary>=10000:"<<endl;
     for(Employee e : emp ){
        if( e.getSalary() >= 10000 ){
            e.display();
        }
     }

     for(Employee &e : emp){
        if( e.getSalary() >= 15000 ){
            e.Increment(15);
        }else{
            e.Increment(10);
        }
     }
     cout<<"After updating salary:"<<endl;
     Print(emp);
     //sort the employees in ascending of id
     sort(emp.begin(), emp.end(), CompareID);
     cout<<"After sorting in ascending order of id:"<<endl;
     Print(emp);
     //sort in descending order of salary
     sort(emp.begin(), emp.end(), CompareSalary);
     cout<<"After sorting in descending order of salary:"<<endl;
     Print(emp);

}
