#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Person {
private:
    string name;
    string email;
    string contactNumber;
    string address;

protected:

    virtual int check() = 0;

public:

    Person()
    {
        name = "";
        email = "";
        contactNumber = "";
        address = "";
    }

    Person(const string& name, const string& email, const string& contactNumber, const string& address) : name(name), email(email), contactNumber(contactNumber), address(address) {}

    void setName(string name) { this->name = name; }
    void setEmail(string email) { this->email = email; }
    void setContactNumber(string contactNumber) { this->contactNumber = contactNumber; }
    void setAddress(string address) { this->address = address; }

    string getName() const { return name; }
    string getEmail() const { return email; }
    string getContactNumber() const { return contactNumber; }
    string getAddress() const { return address; }

    virtual void setdetails()
    {
        cout << "Name: "; getline(cin, name);
        cout << "Email: "; getline(cin, email);
        cout << "ContactNO: "; getline(cin, contactNumber);
        cout << "Address: "; getline(cin, address);
    }
    virtual void setPerson(int id, string name, string email, string contact, string address) = 0;
    virtual string tostring() = 0;
    virtual void getDetails() = 0;
};