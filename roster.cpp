#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <iomanip>

#include "roster.h"
#include "rosterEdit.h"
#include "jobPostiton.h"

//function prototype
std::string companyConversion (companyPosition conversionInput);

employeeRoster::employeeRoster(int ID, std::string NAME, companyPosition TITLE, int SALARY, std::string PHONE){
    this-> Id = ID;
    this-> Name = NAME;
    this-> Title = TITLE;
    this-> Salary = SALARY;
    this-> PhoneNumber = PHONE;

    setEmployeeID(this-> Id);
    setEmployeeName(this-> Name);
    setJobTitle(this-> Title);
    setSalary(this-> Salary);
    setPhoneNumber(this-> PhoneNumber);
}

void employeeRoster::setEmployeeID(int employeeID){
    this-> Id = employeeID;
}

void employeeRoster::setEmployeeName(std::string employeeName){
    this-> Name = employeeName;
}

void employeeRoster::setJobTitle(companyPosition jobTitle){
    this-> Title = jobTitle;
}

void employeeRoster::setSalary(int salary){
    this-> Salary = salary;
}

void employeeRoster::setPhoneNumber(std::string phoneNumber){
    this-> PhoneNumber = phoneNumber;
}

int employeeRoster::getEmployeeID() const{
    return Id;
}
std::string employeeRoster::getEmployeeName() const{
    return Name;
}
companyPosition employeeRoster::getJobTitle() const{
    return Title;
}
int employeeRoster::getSalary() const{
    return Salary;
}
std::string employeeRoster::getPhoneNumber() const{
    return PhoneNumber;
}

void employeeRoster::print(){
    std::cout << "EMPLOYEE NUMBER: " << std::left << std::setw(5) << getEmployeeID() << "EMPLOYEE NAME: " << std::left << std::setw(18) << getEmployeeName() << "JOB TITLE: " << std::left << std::setw(30) << companyConversion(getJobTitle()) << "SALARY: $" << std::left << std::setw(10) << getSalary() << "EMPLOYEE PHONE NUMBER: #" << getPhoneNumber() <<  std::endl;
}

std::string companyConversion (companyPosition conversionInput){
    if(conversionInput == CEO)
        return "CEO";
    else if(conversionInput == CFO)
        return "CFO";
    else if(conversionInput == CIO)
        return "CIO";
    else if(conversionInput == OPERATIONS_MANAGER)
        return "OPERATIONS MANAGER";
    else if(conversionInput == OPERATIONS_ASSOCIATE)
        return "OPERATIONS ASSOCIATE";
    else if(conversionInput == OPERATIONS_SUPERVISOR)
        return "OPERATIONS SUPERVISOR";
    else if(conversionInput == HR_MANAGER)
        return "HR MANAGER";
    else if(conversionInput == HR_SUPERVISOR)
        return "HR SUPERVISOR";
    else if(conversionInput == HR_ASSISTANT)
        return "HR ASSISTANT";
    else if(conversionInput == CUSTOMER_SERVICE)
        return "CUSTOMER SERVICE";
    else if(conversionInput == CUSTOMER_SERVICE_SUPERVISOR)
        return "CUSTOMER SERVICE SUPERVISOR";
    else if(conversionInput == CUSTOMER_SERVICE_MANAGER)
        return "CUSTOMER SERVICE MANAGER";
    else if(conversionInput == LAWYER)
        return "LAWYER";
    else if(conversionInput == LITIGATOR)
        return "LITIGATOR";
    else if(conversionInput == LAW_CLERK)
        return "LAW CLERK";        
}