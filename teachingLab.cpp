#include <iostream>
#include <string>
#include <fstream>
using namespace std;
/* employee Struct
>> employeeid(int) 
>> name(string)
>> salary(double)
*/
struct Employee
{
    int employeeID;
    string name;
    double salary;
};
const int SIZE = 5;
int loadEmployees(Employee[]);
int main()
{
    Employee emplist[SIZE];
    int noEmps=0,highestIndex=0;
    double highestSalary=0.0;
    ofstream outFile("employees.rpt");
    if(!outFile.is_open())
    {
        cout<<"Report file is not open please contact system to rectify this problem"<<endl;
        exit(-1);
    }
    noEmps = loadEmployees(emplist);
    for(int count=0;count<noEmps;count++)
    {
        if(highestSalary<emplist[count].salary)
        {
            highestSalary = emplist[count].salary;
            highestIndex = count;
        }
    }
    outFile<<emplist[highestIndex].name;
    system("pause");
}
int loadEmployees(Employee employees[])
{
    int length=0;
    for(;length<SIZE;length++)
    {
        cout<< "Please enter the employee id to begin or ctrl Z to end ";
        cin>>employees[length].employeeID;
        if(cin.fail())
        {
            break;
        }
        else{
            cout<< "Enter full name for employee no: "<<employees[length].employeeID<<">> ";
            getline(cin,employees[length].name);
            cin.ignore(80,'\n');
            cout<<"Enter salary for employee no: "<<employees[length].employeeID<<">> ";
            cin>>employees[length].salary;
        }
    }
    return length;
}