#pragma once
#include "Person.h"
using namespace std;
class Customer : public Person {
private:

    int customerId;

protected:

    //check customer method to check customer is already exist or not

    int check(){

    try {
        ifstream fin("customer.txt");
        int tempId, count=0;
        string tempName, tempEmail, tempContact, tempAddress;

        while (fin >> tempId >> tempName >> tempEmail >> tempContact >> tempAddress)
        {

            if (tempId == customerId)
            {

                count++;
            }
        }
        return count;
        fin.close();
    }
    catch (const exception& ex) {
        cerr << "Error: " << ex.what() << endl;
    }
}

public:

    //default constructor

    Customer()
    {
        customerId = 0;
    }

    //parameterized constructor

    Customer(const string& name, const string& email, const string& contactNumber,
        const string& address, int customerId)
        : Person(name, email, contactNumber, address), customerId(customerId) {}

    //setter

    void setid(int id)
    {
        customerId = id;
    }

    //to string functions

    string tostring()
    {
        return to_string(customerId) + "\t" + getName() + "\t" + getEmail() + "\t" + getContactNumber() + "\t" + getAddress()+"\n\n";
    }

    //setcustomer details using parameters

    void setPerson(int id, string name, string email, string contact, string address)
    {
        customerId = id;
        setName(name);
        setEmail(email);
        setContactNumber(contact);
        setAddress(address);
    }

    //setting customer details from user input

    void setdetails()
    {
        cout << "CustomerID: "; cin >> customerId;
        cin.ignore();
        Person::setdetails();
    }

    //getting customer details to display

    void getDetails()
    {
        cout << "\nCustomerID: " << customerId;
        cout << "\nName: " << getName();
        cout << "\nEmail: " << getEmail();
        cout << "\nContactNO: " << getContactNumber();
        cout << "\nAddress: " << getAddress();
    }

    //getter

    int getid()const
    {
        return customerId;
    }

    //output stream operator overloading

    friend std::ostream& operator<<(std::ostream& os, const Customer& customer)
    {
        
        os << "Customer ID: " << customer.customerId << "\nName: " << customer.getName() << "\nEmail: "
            << customer.getEmail() << "\nContact Number: " << customer.getContactNumber() << "\nAddress: "
            << customer.getAddress() << endl;
        return os;
    }

    //input stream operator overloading

    friend istream& operator>>(istream& in, Customer& customer) {
        cout << "\nEnter Customer ID: "; in >> customer.customerId;
        in.ignore();
        customer.Person::setdetails();
        return in;
    }

    // addCustomerDetails method

    void addCustomerToFile() {
        try {
            ofstream fout("customer.txt", ios::app);
            if (check() == 0)
            {
                fout << tostring();
                cout << "\nCustomer added successfully!!!\n";
            }
            else {
                cout << "\nCustomer Id Already Exist!!!\n";
            }
            fout.close();


        }
        catch (const exception& ex) {
            cerr << "\nError: " << ex.what() << endl;
        }
    }

    //view Customer method

    static void viewAllCustomer() {
        try {
            ifstream fin("customer.txt");
            int tempId;
            string tempName, tempEmail, tempContact, tempAddress;
            
            while (fin >> tempId >> tempName >> tempEmail >> tempContact >> tempAddress)
            {
                cout << "Customer ID: " << tempId << "\n"
                     << "Customer Name: " << tempName << "\n"
                     << "Customer Email: " << tempEmail << "\n"
                     << "Customer Contact: " << tempContact << "\n"
                     << "Customer Address: " << tempAddress << "\n\n";
                
                
            }
            fin.close();
           
        }
        catch (const exception& ex) {
            cerr << "\nError: " << ex.what() << endl;
        }
    }

    //Search Customer method

    int SearchCustomer(int id) {
        try {
            ifstream fin("customer.txt");
            int tempId,count=0;
            string tempName, tempEmail, tempContact, tempAddress;

            while (fin >> tempId >> tempName >> tempEmail >> tempContact >> tempAddress)
            {
                if (tempId == id)
                {
                    cout << "Customer ID: " << tempId << "\n"
                        << "Customer Name: " << tempName << "\n"
                        << "Customer Email: " << tempEmail << "\n"
                        << "Customer Contact: " << tempContact << "\n"
                        << "Customer Address: " << tempAddress << "\n\n";
                    count = 1;
                    setPerson(tempId, tempName, tempEmail, tempContact, tempAddress);
                    return count;
                }
            }
            fin.close();
            if (count == 0)
            {
                cout << "\nCustomer not found!!!\n";
                return count;
            }
        }
        catch (const exception& ex) {
            cerr << "\nError: " << ex.what() << endl;
        }
    }

    //Update Customer method

    void updateCustomer(int id) {
        try {
            ifstream fin("customer.txt");
            ofstream fout("temp.txt");

            int tempId;
            string tempName, tempEmail, tempContact, tempAddress;
            int count = 0;
            while (fin >> tempId >> tempName >> tempEmail >> tempContact >> tempAddress)
            {

                if (tempId == id)
                {
                    
                    if (check() == 0)
                    {
                        fout << tostring();
                        count = 1;
                    }
                    else
                    {
                        count = 2;
                        cout << "\nCustomer with ID " << id << " Already exist\n";
                        fout << tempId << "\t" << tempName << "\t" << tempEmail << "\t" << tempContact << "\t" << tempAddress << "\n\n";
                    }
                   
                }
                else
                {
                   
                    fout << tempId << "\t" << tempName << "\t" << tempEmail << "\t" << tempContact << "\t" << tempAddress << "\n\n";
                }

            }
            fin.close();
            fout.close();
            remove("customer.txt");
            rename("temp.txt", "customer.txt");
            if (count==1) {
                cout << "\nCustomer updated successfully!\n";
            }
            else if(count==0){
                cout << "\nCustomer with ID '" << id << "' not found.\n";
            }
        }
        catch (const exception& ex) {
            cerr << "Error: " << ex.what() << endl;
        }
    }

   
    //Delete Customer method

    void deleteCustomer(int id) {
        try {

            ifstream fin("customer.txt");
            ofstream fout("temp.txt");

            int tempId;
            string tempName, tempEmail, tempContact, tempAddress;
            bool found = false;
            while (fin >> tempId >> tempName >> tempEmail >> tempContact >> tempAddress)
            {

                if (tempId == id)
                {
                    found = true;
                    continue;
                }
                else
                {
                    fout << tempId <<"\t"<<tempName << "\t" << tempEmail << "\t" << tempContact << "\t" << tempAddress << "\n\n";
                }

            }

            fin.close();
            fout.close();

            remove("customer.txt");
            rename("temp.txt", "customer.txt");
            if (found) {
                cout << "\nCustomer deleted successfully!\n";
            }
            else {
                cout << "\nCustomer with ID '" << id << "' not found.\n";
            }
        }
        catch (const exception& ex) {
            cerr << "Error: " << ex.what() << endl;
        }
    }

};