#ifndef ROSTER_H
#define ROSTER_H

#include <vector>
#include "jobPostiton.h"

class employeeRoster{

    public:
        //Mutators
        void setEmployeeID(int employeeID);
        void setEmployeeName(std::string employeeName);
        void setJobTitle(companyPosition jobTitle);
        void setSalary (int salary);
        void setPhoneNumber (std::string phoneNumber);
        
        //Accessors
        int getEmployeeID() const;
        std::string getEmployeeName() const;
        companyPosition getJobTitle() const;
        int getSalary() const;
        std::string getPhoneNumber() const;

        void print();
        employeeRoster(int ID, std::string NAME, companyPosition TITLE, int SALARY, std::string PHONE);
        ~employeeRoster();

    private:
        //Variables used to input pointer objects
        int Id;
        std::string Name;
        companyPosition Title;
        int Salary;
        std::string PhoneNumber;

};



#endif