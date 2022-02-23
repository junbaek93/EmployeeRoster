#include <iostream>
#include <iomanip>
#include <string>
#include <vector>

#include "jobPostiton.h"
#include "rosterEdit.h"
#include "roster.h"

//function prototype
companyPosition ComapnyConversion;

void editRoster::add(int fileID, std::string fileEmployeeName, companyPosition fileJobTitle, int fileSalary, std::string filePhoneNumber){
    employeeRosterArray[rosterCounter] = new employeeRoster(fileID, fileEmployeeName, fileJobTitle, fileSalary, filePhoneNumber);
    rosterCounter++;

}


void editRoster::view(){
    for(int i = 0; i < rosterCounter; i++){
        employeeRosterArray[i]->print();
    }
 
}



void editRoster::viewDepartments(){
    int numberOfEmployees = 0;
    
    std::cout << std::endl << "CURRENT DEPARTMENTS:" << std::endl;
    std::cout << "----------------------------" << std::endl;
    std::cout << "EXECUTIVE MANAGEMENT:" << std::endl;

    for(int i = 0; i < rosterCounter; i++){
        if(employeeRosterArray[i]->getJobTitle() == CEO || employeeRosterArray[i]->getJobTitle() == CFO || employeeRosterArray[i]->getJobTitle() == CIO){
            std::cout << "EMPLOYEE NAME: " << std::left << std::setw(20) << employeeRosterArray[i]->getEmployeeName() << "EMPLOYEE JOB TITLE: " << conversionToString(employeeRosterArray[i]->getJobTitle()) << std::endl; 
            numberOfEmployees++;
            }
    }
    

    numberOfEmployees = 0;
    std::cout << "----------------------------" << std::endl;
    std::cout << "ADMINISTRATION:" << std::endl;

    for(int i = 0; i < rosterCounter; i++){
        if(employeeRosterArray[i]->getJobTitle() == HR_MANAGER || employeeRosterArray[i]->getJobTitle() == HR_SUPERVISOR || employeeRosterArray[i]->getJobTitle() == HR_ASSISTANT){
            std::cout << "EMPLOYEE NAME: " << std::left << std::setw(20) << employeeRosterArray[i]->getEmployeeName() << "EMPLOYEE JOB TITLE: " << conversionToString(employeeRosterArray[i]->getJobTitle()) << std::endl; 
            numberOfEmployees++;
        }
    }

    std::cout << "----------------------------" << std::endl;
    std::cout << "OPERATIONS:" << std::endl;

    for(int i = 0; i < rosterCounter; i++){
        if(employeeRosterArray[i]->getJobTitle() == OPERATIONS_MANAGER || employeeRosterArray[i]->getJobTitle() == OPERATIONS_SUPERVISOR || employeeRosterArray[i]->getJobTitle() == OPERATIONS_ASSOCIATE){
            std::cout << "EMPLOYEE NAME: " << std::left << std::setw(20) << employeeRosterArray[i]->getEmployeeName() << "EMPLOYEE JOB TITLE: " << conversionToString(employeeRosterArray[i]->getJobTitle()) << std::endl; 
            numberOfEmployees++;
        }
    }

    numberOfEmployees = 0;
    std::cout << "----------------------------" << std::endl;
    std::cout << "LEGAL TEAM:" << std::endl;

    for(int i = 0; i < rosterCounter; i++){
        if(employeeRosterArray[i]->getJobTitle() == LAWYER || employeeRosterArray[i]->getJobTitle() == LITIGATOR || employeeRosterArray[i]->getJobTitle() == LAW_CLERK){
            std::cout << "EMPLOYEE NAME: " << std::left << std::setw(20) << employeeRosterArray[i]->getEmployeeName() << "EMPLOYEE JOB TITLE: " << conversionToString(employeeRosterArray[i]->getJobTitle()) << std::endl; 
            numberOfEmployees++;
        }
    }

    numberOfEmployees = 0;
    std::cout << "----------------------------" << std::endl;
    std::cout << "CUSTOMER SERVICE:" << std::endl;

    for(int i = 0; i < rosterCounter; i++){
        if(employeeRosterArray[i]->getJobTitle() == CUSTOMER_SERVICE || employeeRosterArray[i]->getJobTitle() == CUSTOMER_SERVICE_SUPERVISOR || employeeRosterArray[i]->getJobTitle() == CUSTOMER_SERVICE_MANAGER){
            std::cout << "EMPLOYEE NAME: " << std::left << std::setw(20) << employeeRosterArray[i]->getEmployeeName() << "EMPLOYEE JOB TITLE: " << conversionToString(employeeRosterArray[i]->getJobTitle()) << std::endl; 
            numberOfEmployees++;
        }
    }

}

void editRoster::viewContact(){
    
    viewDepartments();
    std::string inputName;
    clearBuffer();

    std::cout << "Enter name to view contact info: ";
    std::getline(std::cin,inputName);

    for(int i = 0; i < rosterCounter; i++){
        if(employeeRosterArray[i]->getEmployeeName().compare(inputName) == 0){
            std::cout << employeeRosterArray[i]->getEmployeeName() << "'s Phone Number: " << employeeRosterArray[i]->getPhoneNumber() << std::endl;
        }
    }    
}

void editRoster::addEmployeeToRoster(){
    std::string firstName;
    std::string lastName;
    companyPosition jobTitle;
    int salary;
    std::string phoneNumber;

    std::cout << "Please enter name of new employee" << std::endl 
            << "First name: ";
    std::cin >> firstName;
    std::cout << "Last name: ";
    std::cin >> lastName;

    clearBuffer();
    std::string getTitle;
    std::cout << "Please enter new employee job title: ";
    std::getline(std::cin, getTitle);
    jobTitle = conversionToENUM(getTitle);

    std::cout << "Please enter new employee salary: $";
    std::cin >> salary;

    std::cout << "Please enter new employee phone number: ";
    std::cin >> phoneNumber;

    std::string fullName = firstName + " " + lastName;

    int newEmployeeNumber = rosterCounter + 1;
    for(int i = 0; i < rosterCounter; i++){
        if(employeeRosterArray[i]->getEmployeeID() == newEmployeeNumber){
            newEmployeeNumber++;
        }
    }
    add(newEmployeeNumber, fullName, jobTitle, salary, phoneNumber);

}

void editRoster::DeleteEmployeeFromRoster(){
    std::string name;
    std::string answer;

    clearBuffer();
    std::cout << "Please enter employee name you wish to delete: ";
    std::getline(std::cin, name);
    std::cout << "Do you want to continue deleting " << name << "off of the employee roster? (yes/no): ";
    std::cin >> answer;

    int index = 0;
    if(stringToUpper(answer) == "YES"){
        for(int i = 0; i < rosterCounter; i++){
            if(employeeRosterArray[i]->getEmployeeName() == name){
                for(int j = i; j < rosterCounter - index; j++){
                    employeeRosterArray[j] = employeeRosterArray[j+1];
                    std::cout << employeeRosterArray[j]->getEmployeeName() << std::endl;
                }
            }
            if(i == rosterCounter - 1){
                employeeRosterArray[i] = {nullptr};
                rosterCounter--;
            }
            index++;
        }
    }

}
