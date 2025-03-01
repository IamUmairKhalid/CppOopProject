#pragma once
#include "Customer.h"
#include "Inventory.h"
#include <fstream>
#include <iostream>

class Sales
{

private:
    
	static int saleid;
    int soldquantity;
    float soldprice;
	BookInventory invent;
	Customer customer;

    //check Sales id method check last sale id in sales file to generate new and unique sale id

    int check()
    {
        try {

            ifstream fin("sales.txt");

            int tempsid, tempId, tempAId, tempQuantity, tempcId;
            string tempTitle, tempAuthorName, tempcName, tempEmail, tempContact, tempAddress;
            float tempPrice, tempsPrice;
            int count = 1;
            while (fin >> tempsid >> tempcId >> tempcName >> tempEmail >> tempContact >> tempAddress >> tempId >> tempTitle
                >> tempAId >> tempAuthorName >> tempPrice >> tempQuantity >> tempsPrice)
            {
                count++;
            }
            if (count == 1)
            {
                return count;
            }
            else
            {
                return count;
            }
            fin.close();
        }
        catch (const exception& ex) {
            cerr << "Error: " << ex.what() << endl;
        }
    }

    //check book function to check that book is available or not

    int checkbookAvail()
    {
        try {

            ifstream fin("Inventory.txt");

            int tempId, tempAId, tempQuantity, count = 0;
            string tempTitle, tempAuthorName;
            float tempPrice;
            ;
            while (fin >> tempId >> tempTitle >> tempAId >> tempAuthorName >> tempQuantity >> tempPrice)
            {

                if (tempQuantity - soldquantity < 0)
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

    Sales()
    {
        BookInventory();
        Customer();
    }

   // parameterized constructor

	Sales(const string& name, const string& email, const string& contactNumber,
		const string& address, int customerId, int bookid, string title, int quantity,
		float price, int aid, string aname, string aemail, string contact, string aaddress)
	{
		
		BookInventory(bookid, title, quantity, price, aid, aname, aemail, contact, aaddress);
		Customer(name, email, contactNumber, address, customerId);
	}

    //copy constructor

	Sales(const Customer& c, const BookInventory& b,int quant)
	{
		
        
        customer = c;
        invent = b;
        soldquantity = quant;
	}

    //setter methods of sales class

    void setsoldQuantity(int q)
    {
        soldquantity = q;
    }

    void setsoldprice(float p)
    {
        soldprice = p;
    }

    //getter methods of sales class

    int getsoldQuantity()
    {
        return soldquantity;
    }

    float getsoldprice()
    {
        return soldprice;
    }

    //set deatils method for sales record using parameters

    void setdetails(int sid, int bId, string title,int aid,string aName,float Price,int cid, string cName,string cEmail,string Contact,string Address, int Quantity, float sPrice)
    {
        saleid = sid;
        invent.setBook(bId,title,Price,aid,aName);
        customer.setPerson(cid, cName, cEmail, Contact, Address);
        soldquantity = Quantity;
        soldprice = sPrice;
    }

    //total price calculator for sold books

    float totalprice()
    {
       return soldprice = invent.getprice() * soldquantity;
    }

    //get details method to display sales record to user

    void getdetails()
    {
        cout << "\nSales ID: " << saleid;
        customer.getDetails();
        invent.getdetails();
        cout << "\nTotal Sold: " << soldquantity;
        cout << "\nTotal Price: " << soldprice<<endl<<endl;
    }

	//tostring function


	string tostring()
	{
        saleid = check();
		return to_string(saleid)+ "\t" + customer.tostring() + "\t" + invent.tostringSale()+ "\t" + to_string(soldquantity) + "\t" + to_string(totalprice()) + "\n\n";
	}

    // addSalesDetails method

    void addSalesToFile() {
        try {
           
            ofstream fout("sales.txt", ios::app);
           
                 if (invent.checkQuantity()==0 && checkbookAvail()==0)
                 {
                     fout << tostring();
                     invent.updateQuantity(invent.getBookid(), soldquantity);
                     cout << "\nBook Sold successfully!!!\n\n";
                     getdetails();
                }
                 else
                 {
                     cout << "\nBook may be not Available Or the Amount you Enter is Not Avilable!!!";
                 }
                fout.close();
            }
           
        
        catch (const exception& ex) {
            cerr << "\nError: " << ex.what() << endl;
        }
    }

    //view all Sales method

    static void viewAllSales() {
        try {
            Sales s;
            ifstream fin("sales.txt");
            int tempsid,tempId, tempAId, tempQuantity,tempcId;
            string tempTitle, tempAuthorName, tempcName,tempEmail, tempContact, tempAddress;
            float tempPrice, tempsPrice;

            while (fin>> tempsid >> tempcId >> tempcName >> tempEmail >> tempContact >> tempAddress >> tempId >> tempTitle 
                >> tempAId >> tempAuthorName >> tempPrice >> tempQuantity >> tempsPrice )
            {
                s.setdetails(tempsid, tempId, tempTitle, tempAId, tempAuthorName, tempPrice, tempcId, tempcName, tempEmail,
                   tempContact, tempAddress, tempQuantity, tempsPrice);
                s.getdetails();
            }
            fin.close();
        }
        catch (const exception& ex) {
            cerr << "\nError: " << ex.what() << endl;
        }
    }

    //search sales method

    static int searchSales(int id) {
        try {
            Sales s;
            ifstream fin("sales.txt");
            int tempsid, tempId, tempAId, tempQuantity, tempcId, count = 0;
            string tempTitle, tempAuthorName, tempcName, tempEmail, tempContact, tempAddress;
            float tempPrice, tempsPrice;

            while (fin >> tempsid >> tempcId >> tempcName >> tempEmail >> tempContact >> tempAddress >> tempId >> tempTitle
                >> tempAId >> tempAuthorName >> tempPrice >> tempQuantity >> tempsPrice)
            {
                if (tempsid==id)
                {
                    s.setdetails(tempsid, tempId, tempTitle, tempAId, tempAuthorName, tempPrice, tempcId, tempcName, tempEmail,
                        tempContact, tempAddress, tempQuantity, tempsPrice);
                    s.getdetails();
                    count = 1;
                }
            }
            fin.close();
            if (count == 0)
            {
                cout << "\nSales Record not found!!!";
                return count;
            }
        }
        catch (const exception& ex) {
            cerr << "\nError: " << ex.what() << endl;
        }
    }

    //Delete Sales method

    void deleteSales(int id) {
        try {

            ifstream fin("sales.txt");
            ofstream fout("temp.txt");

            int tempsid, tempId, tempAId, tempQuantity, tempcId;
            string tempTitle, tempAuthorName, tempcName, tempEmail, tempContact, tempAddress;
            float tempPrice, tempsPrice;
            bool found = false;
            while (fin >> tempsid >> tempcId >> tempcName >> tempEmail >> tempContact >> tempAddress >> tempId >> tempTitle
                >> tempAId >> tempAuthorName >> tempPrice >> tempQuantity >> tempsPrice)
            {

                if (tempsid == id)
                {
                    found = true;
                    continue;
                }
                else
                {
                    fout << tempsid << "\t" << tempcId << "\t" << tempcName << "\t" << tempEmail << "\t" << tempContact << "\t" 
                        << tempAddress << "\t" << tempId << "\t" << tempTitle
                        << "\t" << tempAId << "\t" << tempAuthorName << "\t" << tempPrice << "\t" << tempQuantity << "\t" << tempsPrice << "\n\n";
                }

            }

            fin.close();
            fout.close();

            remove("sales.txt");
            rename("temp.txt", "sales.txt");
            if (found) {
                cout << "\nSales deleted successfully!\n";
            }
            else {
                cout << "\nSales with ID '" << id << "' not found.\n";
            }
        }
        catch (const exception& ex) {
            cerr << "Error: " << ex.what() << endl;
        }
    }

};
int Sales::saleid = 1; //static data member initializing