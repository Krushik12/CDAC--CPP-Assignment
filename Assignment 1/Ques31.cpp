//Question 3 — HR Payroll Engine
#include<iostream>
using namespace std;


class Employee{
    int empId;
    string name;
    string department;
    char grade;
    double basicSalary;
    bool isActive = true;
    static int employeeCount;

public: 


     
    Employee(){
        employeeCount = employeeCount +1;
        empId = 1000 + employeeCount;
    }


    
    void setName(const string& n){
        if(n != ""){
            name = n;
        }else{
            cout<<"Name cannot be empty!"<<endl;
        }
    }

    void setDepartment(const string& dept){
        if(dept == "Engineering" ||dept == "HR" || dept == "Finance" ||  dept == "Operations"){
            department = dept;
        }else{
            cout<<"Enter department from above listed ones!!"<<endl;
        }
    }
    void setGrade(char g){
        if(g == 'A' || g == 'B' || g == 'C' || g == 'D'){
            grade = g;
        }else{
            cout<<"ERROR: Invalid grade '"<<g <<"'. Accepted values: A, B, C, D." << endl;
        }
    }
    void setBasicSalary(double salary){
        if(salary > 10000 && salary < 500000){
            basicSalary = salary;
        }else{
             cout<<"Enter basic salary between 10,000 to 5,00,000 !!"<<endl;
        }
    }

    void deactivate(){
        isActive = false;
    }

 
    int getEmpId() const{
        return empId;
    }
    string getName() const{
        return name;
    }
    string getDepartment() const{
        return department;
    }
    char getGrade() const{
        return grade;
    }
    double getBasicSalary() const{
        return basicSalary;
    }
    bool getIsActive() const{
        return isActive;
    }

    static int getEmployeeCount() {
        return employeeCount;
    }



    
    double computeAllowances() const{
        if(grade == 'A'){
            return basicSalary * 0.40;
        }else if(grade == 'B'){
            return basicSalary * 0.30;
        }else if(grade == 'C'){
            return basicSalary * 0.20;
        }else{
            return basicSalary * 0.10;
        }
    }

    double computeGrossSalary() const{
        
        return basicSalary + computeAllowances();
    }

    double computeTax() const{
        
        double grossSalary = computeGrossSalary();
        if(grossSalary <= 50000){
            return 0;
        }else if(grossSalary >= 50001 && grossSalary <= 100000){
            double amount = grossSalary - 50000;
            return (amount * 10 / 100);
        }else{
            double amount = grossSalary - 100000;
            return (amount * 20 / 100) + 5000;
        }
    }

    double computeNetSalary() const{
        
        double GS = computeGrossSalary();
        double CT = computeTax();
        return GS - CT;
    }

    void printPayslip() const{
        char grade = getGrade();
        int choice = 0;
        if(grade == 'A'){
            choice = 40;
        }else if(grade == 'B'){
            choice = 30;
        }else if(grade == 'C'){
            choice = 20;
        }else{
            choice = 10;
        }


        cout<< "============================================" << endl;
        cout << "EMPLOYEE PAYSLIP - AUG 2026" <<endl;
        cout<< "============================================" << endl;
        cout<<"Emp ID : "<< getEmpId()<<endl;
        cout<< "Name : " << getName() << endl;
        cout<<"Department : "<< getDepartment() << endl;
        cout<< "Grade : " << getGrade()  << endl;
        cout<< "Status:  " << (getIsActive() ? "Active" : "InActive") << endl;
        cout<< "--------------------------------------------" << endl;
        cout<< "Basic Salary : Rs. " << getBasicSalary()<<endl;
        cout<< "Allowances ("<< choice << "%) : Rs. " << computeAllowances() <<endl;
        cout<< "Gross Salary : Rs. " <<computeGrossSalary() <<endl;
        cout<< "--------------------------------------------" << endl;
        cout<< "Tax Deduction : Rs." << computeTax()<<endl;
        cout<< "Net Salary : Rs. " << computeNetSalary()<<endl;
        cout<< "============================================" << endl;
    }

    void acceptDetails() {

        string n, dept;
        char g;
        double salary;

        cout << "Enter name: ";
        cin >> n;
        setName(n);

        cout << "Enter department:  Engineering, HR, Finance, Operations from this ";
        cin>>dept;
        setDepartment(dept);

        cout << "Enter grade: ";
        cin >> g;
        setGrade(g);

        cout << "Enter basic salary: ";
        cin >> salary;
        setBasicSalary(salary);
    }

};

int Employee::employeeCount = 0;

int main(){

    Employee e1;
    Employee* e2 = new Employee();
    Employee* e3 = new Employee();

    e1.acceptDetails();
    e2->acceptDetails();
    e3->acceptDetails();



    // empId and basicSalary are private data members,so they cannot be accessed or modified directly from main().
    // This protects the data and we must use public setter functions to modify them safely.

    // e1.empId = 999;
    // e1.basicSalary = -1000;


    e1.printPayslip();
    e2->printPayslip();
    e3->printPayslip();

    e3->deactivate();
    if (!e3->getIsActive())
        cout << e3->getName() << " is no longer active. Payroll skipped." << endl;
    
    cout << "Total Employees : " << Employee::getEmployeeCount() << endl;
    delete e2;
    delete e3;

    return 0;
}
