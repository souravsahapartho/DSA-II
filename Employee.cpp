#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;


class Employee
{
    string name;
    double salary;
public:
    int id;

    Employee(string n, int id, double s): name(n), id (id), salary(s)
    {
        cout<<"A new employee is created"<<endl;
    }

    void display()
    {
        cout<<"name: "<<name<<" id: "<<id<<" salary: "<<salary<<endl;
    }
    double getSalary()
    {
        return salary;
    }



    void Increment (double percentage)
    {
        salary +=salary*percentage/100;
    }
};

void Print(vector<Employee> employees)
{
    for(Employee e: employees)
    {
        e.display();
    }
    /*for(int i=0; i<employees.size(); i++){
        employees[i].display();
    }*/
}

bool CompareID(Employee e1, Employee e2)
{
    return e1.id<e2.id;//ascending order
}


bool CompareSalary(Employee e1, Employee e2)
{
    return e1.getSalary()>e2.getSalary();//descending order
}

int main()
{
    vector<Employee> emp=
    {
        Employee("Rahim",2,8000), Employee("Karim",1,15000)
    };
    Employee e1("Abir",4,9000);
    emp.push_back(Employee("Rony",3,18000));
    cout<<"\nPrinting Employees "<<endl;
    Print(emp);
    //change the id of employee at index 2
    emp[2].id= 6;
    cout<<"\nAfter updating id: "<<endl;
    emp[2].display();

    cout<<"Employees with salary >=10000: "<<endl;
    for(Employee e: emp)
    {
        if(e.getSalary()>=10000)
        {
            e.display();
        }
    }

    //increase the salary of employee

    for(Employee &e: emp)
    {
        if(e.getSalary()>=15000)
        {
            e.Increment(15);
        }
        else
        {
            e.Increment(10);
        }
    }

    cout<<"\nAfter Increment: "<<endl;
    Print(emp);


    //sort the employees id in ascending order


    sort(emp.begin(),emp.end(),CompareID);
    cout<<"\nAfter sorting in ascending order of id: "<<endl;
    Print(emp);

    //sort the employees salary in descending order

    sort(emp.begin(),emp.end(), CompareSalary);
    cout<<"\nAfter sorting in descending order of salary: "<<endl;
    Print(emp);

    cout<<"\nEmployee with highest salary: "<<endl;
    emp[0].display();
    cout<<"\nEmployee with lowest salary: "<<endl;
    int n=emp.size();
    emp[n-1].display();

}







/* Question-------
1. Declare a class “Employee” and declare the following attributes
inside the class
a. name (string: private)
b. id (int: public)
c. salary (double: private)
2. Declare necessary constructor/getter-setter
3. Write a function “display” inside the class which will print all the
information of an employee
4. In main method, create a vector of “Employee” and insert the
following employees
 “Rahim”, 2, 8000
 “Karim”, 1, 15000
 “Abir”, 4, 9000
 “Roni”, 3, 18000
5. Find the employees whose salary >= 10000
6. Define a function “Increment(double percentage)” inside the class
which will increase the salary of an employee using the following
formula:
 salary += salary * percentage/100
In main, increase salary by 15% those have salary >= 15000, otherwise
increase salary by 10%.
7. Sort the employees in ascending order of id
8. Sort the employees in descending order of salary. Then print the
employee with the highest salary.
*/
