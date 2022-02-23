#ifndef ROSTER_H
#define ROSTER_H

#include <vector>
#include "jobPostiton.h"

class checkSalary{
    void ifSalary();
};

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

        int checkSalary(int check){
            if(check > 30){
                check = check * (8 * (260-25));
            }
            return check;
        }

    private:
        //Variables used to input pointer objects
        int Id;
        std::string Name;
        companyPosition Title;
        int Salary;
        int check;
        std::string PhoneNumber;

};



#endif