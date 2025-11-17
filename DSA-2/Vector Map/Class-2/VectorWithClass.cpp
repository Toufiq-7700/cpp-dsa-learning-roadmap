#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Employee{
    string name;
    double salary;

public:
    int id;

    Employee(string n, int i, double s):name(n), id(i), salary(s){
    }

    void display(){
       cout<< "Name = "<<name<< ", ID = "<<id<< ", Salary = "<<salary<<endl;
    }

    double getSalary(){
        return salary;
    }
    void increment(double per){
        salary += salary * per/100;
    }

};

void Print(vector<Employee> emps){
//    for(int i=0; i<emps.size(); i++){
//        emps[i].display();
//    }

      for(auto e: emps){
        e.display();
      }
}
bool CompareId(Employee e1, Employee e2){
    return e1.id < e2.id; //Ascending
}
bool CompareSalary(Employee e1, Employee e2){
     return e1.getSalary() > e2.getSalary(); // Descending
}



int main(){

    vector<Employee> emp = {Employee("Rahim", 2, 8000), Employee("Karim",1,15000)};

    Employee e1("Abir",4,9000);
    emp.push_back(e1);

    emp.push_back(Employee("Roni",3,18000));
    emp.push_back(Employee("Sadid",10,100000));

    cout<< "---Printing the Employees---"<<endl;
    Print(emp);


    cout<<endl;
    cout<< "---Update Abir id---"<<endl;
    emp[2].id = 6;
    emp[2].display();


    cout<<endl;
    cout<< "---Employees with salary more than 10000---"<<endl;
    for(auto e : emp){
        if(e.getSalary() >= 10000){
            e.display();
        }
    }

    cout<<endl;
    cout<< "--- Update Salary ---"<<endl;
    for(auto &e : emp){
        if(e.getSalary() >= 15000){
            e.increment(15);
        }
        else{
            e.increment(10);
        }
    }
    Print(emp);


    cout<<endl;
    cout<< "--- Sorting the Employee with their ID ---"<<endl;
    sort(emp.begin(), emp.end(), CompareId);
    Print(emp);

    cout<<endl;
    cout<< "--- Sorting(descending) Employee with their salary ---"<<endl;
    sort(emp.begin(), emp.end(), CompareSalary);
    Print(emp);


   return 0;
}
