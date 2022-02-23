#ifndef ROSTEREDIT_H
#define ROSTEREDIT_H

#include <vector>
#include "roster.h"
#include "jobPostiton.h"

class editRoster{
    public:
        int rosterCounter = 0;
        void add(int fileID, std::string fileEmployeeName, companyPosition fileJobTitle, int fileSalary, std::string filePhoneNumber);
        void view();
        void viewDepartments();
        void viewContact();
        void addEmployeeToRoster();
        void DeleteEmployeeFromRoster();
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
        employeeRoster* employeeRosterArray[20] = {nullptr};

        companyPosition conversionToENUM (std::string conversionInput){
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

        std::string conversionToString (companyPosition conversionInput){
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
};

#endif