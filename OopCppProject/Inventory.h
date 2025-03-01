#pragma once
#include "Book.h"
#include "Author.h"
#include <fstream>

class BookInventory {

private:

    int bookid;
    int quantity;
    float price; 
    Book book;
    Author author;

    //check method for inventory to check book id already exist or not

    int check()
    {
        try {

            ifstream fin("Inventory.txt");

            int tempId, tempAId, tempQuantity,count=0;
            string tempTitle, tempAuthorName;
            float tempPrice;
            ;
            while (fin >> tempId >> tempTitle >> tempAId >> tempAuthorName  >> tempQuantity >> tempPrice)
            {

                if (tempId == bookid)
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

    //default Constructor

    BookInventory()
    {
        bookid = 0;
        quantity = 0;
        price = 0.0;
        
    }

    //parameterized constructor

    BookInventory(int bookid, string title,int quantity,float price,int aid,string aname, string aemail,string contact,string aaddress) 
    {
        this->bookid = bookid;
        this->quantity = quantity;
        this->price = price;
        book.settitle(title);
        book.setauthor(aid, aname, aemail, contact, aaddress);
    }

    //copy constructor

    BookInventory(int id, int quantity, float price, const Book& b, const Author& a)
    {
        this->bookid = id;
        this->quantity = quantity;
        this->price = price;
        book=b;
        author = a;
    }

    //deep copy constructor

    BookInventory(const BookInventory& obj)
    {
        this->bookid = obj.bookid;
        this->quantity = obj.quantity;
        this->price = obj.price;
        book = obj.book;
        author = obj.author;
    }

    // Destructor

    ~BookInventory() {}  

    //setter methods

    void setbookid(int id)
    {
        bookid = id;
    }

    void setQuantity(int q)
    {
        quantity = q;
    }

    void setprice(float p)
    {
        price = p;
    }

    void setBook(int bookid, string title, float price, int id, string name)
    {
        this->bookid = bookid;
        book.settitle(title);
        author.setid(id);
        author.setName(name);
        this->price = price;
    }

    //getter methods

    int getBookid()
    {
        return bookid;
    }

    int getquantity()
    {
        return quantity;
    }

    float getprice()
    {
        return price;
    }

    Book getbook()
    {
        return book;
    }

    //increase quantity method to increase book quantity

    void increaseQuantity(int amount)
    {
        quantity += amount; 
    }

    //decrease quantity method to decrease book quantity

    void decreaseQuantity(int amount) 
    {
        quantity -= amount; 
    }

    //set inventory details through use input

    void setdetails()
    {
        cout << "Book ID: "; cin>>bookid;
        cin.ignore();
        string t,n;
        int aid;
        cout << "Book Title: "; getline(cin, t);
        book.settitle(t);
        cout << "Book Author id: "; cin>>aid;
        author.setid(aid);
        cout << "Book Author Name: "; getline(cin, n);
        author.setName(n);
        cout << "Book Price: "; cin>>price;
    }

    //getinventory details and display details to user

    void getdetails()
    {
        cout << "\nBook ID: " << bookid;
        cout << "\nBook Title: " << book.gettitle();
        cout << "\nAuthor ID: " << author.getid();
        cout << "\nAuthor Name: " << author.getName();
        cout << "\nActual Price: " << price;
    }

    //tostring function for Sales class

    string tostringSale()
    {
        return to_string(bookid) + "\t" + book.gettitle() + "\t" + to_string(author.getid()) + "\t" + author.getName() + "\t" + to_string(price) + "\n\n";
            
    }
   
    //to string function for Inventory class

    string tostring()
    {
        return  to_string(bookid) +"\t"+
        book.gettitle()+ "\t" +
        to_string(author.getid())+ "\t" +
        author.getName()+ "\t" +
        to_string(quantity) + "\t" +
        to_string(price) +"\n\n";
      
    }

    // output Stream operator overloading
    
    friend std::ostream& operator<<(std::ostream& os, const BookInventory& item)
    {
        os << "\nBook ID: " << item.bookid << "\nBook Title: " << item.book.gettitle() << "\nAuthor ID: " << item.author.getid()
            << "\nAuthor Name: " << item.author.getName() << "\nBook Quantity: " << item.quantity << "\nBook Price: " << item.price<<"\n";
        return os;
    }

    // input stream operator overloading

    friend istream& operator>>(istream& in, BookInventory& item) {
        cout << "\nBookID: "; in >> item.bookid;
        item.book.setdetails();
        cout << "\nBook Price: "; in >> item.price;
        cout << "\nBook Quantity: "; in >> item.quantity;
        return in;
    }
  
    //add book to inventory method

    void addBookToFile() {
        try {
            ofstream fout("Inventory.txt", ios::app);
            if (check() == 0)
            {
                fout << tostring();
                cout << "\nBook added to Inventory successfully!";
            }
            else {
                cout << "\nBook Id Already Exist!!!";
            }
            fout.close();
            
            
        }
        catch (const exception& ex) {
            cerr << "\nError: " << ex.what() << endl;
        }
    }

    //view all books of inventory method

    static void viewAllBooks() {
        try {
            ifstream fin("Inventory.txt");
            int tempId, tempAId, tempQuantity;
            string tempTitle, tempAuthorName;
            float tempPrice;

            while (fin >> tempId >> tempTitle >> tempAId >> tempAuthorName >> tempQuantity >> tempPrice)
            {
                cout << "Book ID: " << tempId << "\n"
                    << "Book Title: " << tempTitle << "\n"
                    << "Author ID: " << tempAId << "\n"
                    << "Author Name: " << tempAuthorName << "\n"
                    << "Book Quantity: " << tempQuantity << "\n"
                    << "Book Price: " << tempPrice << "\n\n";
               
            }
            fin.close();
            
        }
        catch (const exception& ex) {
            cerr << "\nError: " << ex.what() << endl;
        }
    }

    //search book from inventory file method

   int searchBooks(int id) {
        try {
            ifstream fin("Inventory.txt");
            int tempId, tempAId, tempQuantity, count=0;
            string tempTitle, tempAuthorName;
            float tempPrice;

            while (fin >> tempId >> tempTitle >> tempAId >> tempAuthorName >> tempQuantity >> tempPrice)
            {
                if (tempId == id)
                {
                    cout << "Book ID: " << tempId << "\n"
                        << "Book Title: " << tempTitle << "\n"
                        << "Author ID: " << tempAId << "\n"
                        << "Author Name: " << tempAuthorName << "\n"
                        << "Book Quantity: " << tempQuantity << "\n"
                        << "Book Price: Rs " << tempPrice << "\n\n";
                    count = 1;
                    setBook(tempId, tempTitle, tempPrice, tempAId, tempAuthorName);
                    return count;
                }
            }
            fin.close();
            if (count == 0)
            {
                cout << "\nBook not found!!!";
                return count;
            }
        }
        catch (const exception& ex) {
            cerr << "\nError: " << ex.what() << endl;
        }
    }

   //update inventory details method

    void updateInventory(int oldId) {
        try {
           
                ifstream fin("Inventory.txt");
                ofstream fout("temp.txt");

                int tempId, tempAId, tempQuantity;
                string tempTitle, tempAuthorName;
                float tempPrice;
                int count = 0;
                while (fin >> tempId >> tempTitle >> tempAId >> tempAuthorName >> tempQuantity >> tempPrice)
                {

                    if (tempId == oldId)
                    {
                        
                        if (check() == 0 || check() == 1)
                        {
                            fout << tostring();
                            count = 1;
                        }
                        else
                        {
                            count = 2;
                            fout << tempId << "\t" << tempTitle << "\t" << tempAId << "\t" << tempAuthorName << "\t"
                                << tempQuantity << "\t" << tempPrice << "\n\n";
                        }
                    }
                    else {
                        fout << tempId << "\t" << tempTitle << "\t" << tempAId << "\t" << tempAuthorName << "\t"
                            << tempQuantity << "\t" << tempPrice << "\n\n";
                    }
                }
            
            fin.close();
            fout.close();
            remove("Inventory.txt");
            rename("temp.txt", "Inventory.txt");
            if (count==1) {
                cout << "\nInventory updated successfully!\n";
            }
            else if(count==0){
                cout << "\nBook with ID '" << oldId << "' not found\nOr Book Id Already Exists in Inventory.\n";
            }
        }
        catch (const exception& ex) {
            cerr << "Error: " << ex.what() << endl;
        }
    }

    //update book quantity in inventory file

void updateQuantity(int id,int num) {
        
        
        try {
            
            ifstream fin("Inventory.txt");
            ofstream fout("temp.txt");

            int tempId, tempAId, tempQuantity;
            string tempTitle, tempAuthorName;
            float tempPrice;

            while(fin >> tempId >> tempTitle >> tempAId >> tempAuthorName >> tempQuantity >> tempPrice)
            {
                
                if(tempId==id)
                {
                    tempQuantity = tempQuantity - num;
                    
                    fout << tempId << "\t" << tempTitle << "\t" << tempAId << "\t" << tempAuthorName 
                        << "\t" << tempQuantity << "\t" << tempPrice << "\n\n";
                    
                }
                else
                {
                    fout << tempId<< "\t" << tempTitle << "\t" << tempAId << "\t" << tempAuthorName << "\t"
                         << tempQuantity << "\t" << tempPrice<<"\n\n";
                }
               
            }
           
            fin.close();
            fout.close();
            
            remove("Inventory.txt");
            rename("temp.txt", "Inventory.txt");
           
        }
        catch (const exception& ex) {
            cerr << "Error: " << ex.what() << endl;
        }
    }

//check available book quantity in inventory file

int checkQuantity()
{
    try {

        ifstream fin("Inventory.txt");

        int tempId, tempAId, tempQuantity, count = 0;
        string tempTitle, tempAuthorName;
        float tempPrice;
        ;
        while (fin >> tempId >> tempTitle >> tempAId >> tempAuthorName >> tempQuantity >> tempPrice)
        {

            if (tempQuantity == 0)
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

//Delete Book details from inventory file also from book file 

void deleteBook(string title) {
    try {

        ifstream fin("Inventory.txt");
        ofstream fout("temp.txt");

        int tempId, tempAId, tempQuantity;
        string tempTitle, tempAuthorName;
        float tempPrice;
        bool found = false;

        while (fin >> tempId >> tempTitle >> tempAId >> tempAuthorName >> tempQuantity >> tempPrice)
        {

            if (tempTitle == title)
            {
                book.deleteBook(title);
                found = true;
                continue;
            }
            else
            {
                fout << tempId << "\t" << tempTitle << "\t" << tempAId << "\t" << tempAuthorName << "\t"
                    << tempQuantity << "\t" << tempPrice << "\n\n";
            }

        }

        fin.close();
        fout.close();

        remove("Inventory.txt");
        rename("temp.txt", "Inventory.txt");
        if (found) {
            cout << "\nBook deleted successfully!\n";
        }
        else {
            cout << "\nBook with Title '" << title << "' not found.\n";
        }
    }
    catch (const exception& ex) {
        cerr << "Error: " << ex.what() << endl;
    }
}

};
