#pragma once
#include "Person.h"
using namespace std;
class Author : public Person {
private:

    int authorId;

protected:

    //Check function for Author to check id already exists

    int check() {
        try {
            ifstream fin("author.txt");
            int tempId, count = 0;
            string tempName, tempEmail, tempContact, tempAddress;

            while (fin >> tempId >> tempName >> tempEmail >> tempContact >> tempAddress)
            {

                if (tempId == authorId)
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

    //Drfault Constructor

    Author()
    {
        authorId = 0;
    }

    //Parameterized Constructor

    Author(const string& name, const string& email, const string& contactNumber,
        const string& address, int authorId)
        : Person(name, email, contactNumber, address), authorId(authorId) {}

    //setter

    void setid(int id)
    {
        authorId = id;
    }

    //getter

    int getid()const
    {
        return authorId;
    }

    //setPerson method using parameters

    void setPerson(int id, string name, string email, string contact, string address)
    {
        authorId = id;
        setName(name);
        setEmail(email);
        setContactNumber(contact);
        setAddress(address);
    }

    //To string functions

    string tostring()
    {
        return to_string(authorId) + " \t" + getName() + " \t" + getEmail() + " \t" + getContactNumber() + " \t" + getAddress()+"\n\n";
    }

    //To string functions

    void setdetails()
    {
        cout << "AuthorID: "; cin >> authorId;
        cin.ignore();
        Person::setdetails();
    }

    //To getdetails functions to get from user

    void getDetails()
    {
        cout << "AuthorID: " << authorId;
        cout << "Name: " << getName();
        cout << "Email: " << getEmail();
        cout << "ContactNO: " << getContactNumber();
        cout << "Address: " << getAddress();
    }

    //output stream operator overloading

    friend std::ostream& operator<<(std::ostream& os, const Author& author)
    {
        os << "Author ID: " << author.authorId << "\nName: " << author.getName() << "\nEmail: " 
            << author.getEmail() << "\nContact Number: " << author.getContactNumber() << "\nAddress: " 
            << author.getAddress() << endl;
        return os;
    }

    //input stream operator overloading

    friend istream& operator>>(istream& in, Author& author) {
        cout << "\nEnter Author ID: "; in >> author.authorId;
        in.ignore();
        author.Person::setdetails();
        return in;
    }

    // addAuthorDetails

    void addAuthorToFile() {
        try {
            ofstream fout("author.txt", ios::app);
            if (check() == 0)
            {
                fout << tostring();
                cout << "\nAuthor added successfully!";
            }
            else {
                cout << "\nAuthor Id Already Exist!!!";
            }
            fout.close();


        }
        catch (const exception& ex) {
            cerr << "\nError: " << ex.what() << endl;
        }
    }

    //view Author method

    static void viewAllAuthor() {
        try {
            ifstream fin("author.txt");
            int tempId;
            string tempName, tempEmail, tempContact, tempAddress;

            while (fin >> tempId >> tempName >> tempEmail >> tempContact >> tempAddress)
            {
                cout << "Author ID: " << tempId << "\n"
                    << "Author Name: " << tempName << "\n"
                    << "Author Email: " << tempEmail << "\n"
                    << "Author Contact: " << tempContact << "\n"
                    << "Author Address: " << tempAddress << "\n\n";
            }
            fin.close();
        }
        catch (const exception& ex) {
            cerr << "\nError: " << ex.what() << endl;
        }
    }

    //Search Author method

    int SearchAuthor(int id) {

        try {
            ifstream fin("author.txt");
            int tempId, count = 0;
            string tempName, tempEmail, tempContact, tempAddress;

            while (fin >> tempId >> tempName >> tempEmail >> tempContact >> tempAddress)
            {
                if (tempId == id)
                {
                    cout << "Author ID: " << tempId << "\n"
                         << "Author Name: " << tempName << "\n"
                         << "Author Email: " << tempEmail << "\n"
                         << "Author Contact: " << tempContact << "\n"
                         << "Author Address: " << tempAddress << "\n\n";
                    count = 1;
                    setPerson(tempId, tempName, tempEmail, tempContact, tempAddress);
                    return count;
                }
            }
            fin.close();
            if (count == 0)
            {
                cout << "\nAuthor not found!!!";
                return count;
            }
        }
        catch (const exception& ex) {
            cerr << "\nError: " << ex.what() << endl;
        }
    }

    //Update Author method

    void updateAuthor(int oldId) {
        try {
            ifstream fin("author.txt");
            ofstream fout("temp.txt");

            int tempId;
            string tempName, tempEmail, tempContact, tempAddress;
            int count = 0;
            while (fin >> tempId >> tempName >> tempEmail >> tempContact >> tempAddress)
            {

                if (tempId == oldId)
                {
                    if (check() <= 1)
                    {
                        fout << tostring();
                        count = 1;
                    }
                    else {
                       
                        fout << tempId << "\t" << tempName << "\t" << tempEmail << "\t" << tempContact << "\t" << tempAddress << "\n\n";
                        count = 2;
                    }
                }
                else
                {
                    fout << tempId << "\t" << tempName << "\t" << tempEmail << "\t" << tempContact << "\t" << tempAddress << "\n\n";
                }

            }
            fin.close();
            fout.close();
            remove("author.txt");
            rename("temp.txt", "author.txt");
            if (count==1) {
                cout << "\nAuthor updated successfully!\n";
            }
            else if(count==0){
                cout << "\nAuthor with ID '" << oldId << "' not found Or Author Id Already Exists.\n";
            }
        }
        catch (const exception& ex) {
            cerr << "Error: " << ex.what() << endl;
        }
    }


    //Delete Author method

    void deleteAuthor(int id) {
        try {

            ifstream fin("author.txt");
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
                    fout << tempId << "\t" << tempName << "\t" << tempEmail << "\t" << tempContact << "\t" << tempAddress << "\n\n";
                }

            }

            fin.close();
            fout.close();

            remove("author.txt");
            rename("temp.txt", "author.txt");
            if (found) {
                cout << "\nAuthor deleted successfully!\n";
            }
            else {
                cout << "\nAuthor with ID '" << id << "' not found.\n";
            }
        }
        catch (const exception& ex) {
            cerr << "Error: " << ex.what() << endl;
        }
    }

};
