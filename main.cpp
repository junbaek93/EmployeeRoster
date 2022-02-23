#include <iostream>
#include <fstream>
#include <sstream>

#include "roster.h"
#include "rosterEdit.h"
#include "jobPostiton.h"


//Function Prototype
companyPosition companyConversion (std::string conversionInput);
void mainMenu();
void clearBuffer();
std::string stringToUpper(std::string str);

int main(){
    editRoster RosterEdit;



    /*
        Retrieve from database
    */

    std::ifstream myFile;
    myFile.open ("employeeRoster.txt");

    std::string line;

    int employeeID;
    std::string employeeName;
    companyPosition jobTitle;
    int salary;
    std::string phoneNumber;

    while(getline (myFile, line)){
        int index = 0;

        std::istringstream sline(line);
        std::string parse;
        while(getline (sline, parse,',')){
            if(index == 0){
                employeeID = stoi(parse);
            }
            else if(index == 1){
                employeeName = parse ;
            }
            else if(index == 2){
                jobTitle = companyConversion(stringToUpper(parse));
            }
            else if(index == 3){
                salary = stoi(parse);
            }
            else if(index == 4){
                phoneNumber = parse;
                RosterEdit.add(employeeID, employeeName, jobTitle, salary, phoneNumber);
            }
            index++; 
        }
    }

    bool exitProgram = false;
    while(exitProgram == false){

        std::cout << "Jun's Company Employee Roster" << std::endl;
        mainMenu(); //Displays the main menu of employee roster
        
        int option;
        bool repeatOption = true;

        while(repeatOption){
            std::cin >> option;
            if (option == 1){
                RosterEdit.view();
                std::cout << std::endl;
                repeatOption = false;
            }
            else if (option == 2){
                RosterEdit.viewDepartments();
                std::cout << std::endl;
                repeatOption = false;
            }
            else if (option == 3){
                std::cout << std::endl;
                RosterEdit.viewContact();
                std::cout << std::endl;
                repeatOption = false;

            }
            else if (option == 4){
                std::cout << std::endl;
                RosterEdit.addEmployeeToRoster();
                std::cout << std::endl;
                repeatOption = false;
            }
            else if (option == 5){
                std::cout << std::endl;
                RosterEdit.DeleteEmployeeFromRoster();
                std::cout << std::endl;
                repeatOption = false;
            }    
            else if (option == 6){
                std::cout << "6" << std::endl;
                exitProgram = true;
                repeatOption = false;
            }
            else{
                std::cout << "Please try again: ";
            }
        }
    }
    return 0;
}

void mainMenu(){
    std::cout << "1. View Employee Roster" << std::endl
            << "2. View Departments" << std::endl
            << "3. View Contacts Only" << std::endl
            << "4. Add Employee to Roster" << std::endl
            << "5. Delete Employee to Roster" << std::endl
            << "6. Exit Program" << std::endl
            << "Please choose option (1-6): ";
}

void clearBuffer(){
    std::cin.clear();
    std::cin.ignore(256, '\n');
}

std::string stringToUpper(std::string str){
    std::string newStr;
    for(int i = 0; i < str.length(); i++){
        str[i] = toupper(str[i]);
    }
    return str;            
}
companyPosition companyConversion (std::string conversionInput){
    if(conversionInput == "CEO")
        return CEO;
    else if(conversionInput == "CFO")
        return CFO;
    else if(conversionInput == "CIO")
        return CIO;
    else if(conversionInput == "OPERATIONS MANAGER")
        return OPERATIONS_MANAGER;
    else if(conversionInput == "OPERATIONS ASSOCIATE")
        return OPERATIONS_ASSOCIATE;
    else if(conversionInput == "OPERATIONS SUPERVISOR")
        return OPERATIONS_SUPERVISOR;
    else if(conversionInput == "HR MANAGER")
        return HR_MANAGER;
    else if(conversionInput == "HR SUPERVISOR")
        return HR_SUPERVISOR;
    else if(conversionInput == "HR ASSISTANT")
        return HR_ASSISTANT;
    else if(conversionInput == "CUSTOMER SERVICE")
        return CUSTOMER_SERVICE;
    else if(conversionInput == "CUSTOMER SERVICE SUPERVISOR")
        return CUSTOMER_SERVICE_SUPERVISOR;
    else if(conversionInput == "CUSTOMER SERVICE MANAGER")
        return CUSTOMER_SERVICE_MANAGER;
    else if(conversionInput == "LAWYER")
        return LAWYER;
    else if(conversionInput == "LITIGATOR")
        return LITIGATOR;
    else if(conversionInput == "LAW CLERK")
        return LAW_CLERK;        
}