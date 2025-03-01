#pragma once
#include <fstream>
#include"Author.h"
using namespace std;

class Book {

    private:

        string title;
        Author author;

        //private check method to check book title already exist or not

        int check()
        {
            try {

                ifstream fin("book.txt");

                int tempAId, count = 0;
                string tempTitle, tempAuthorName;
                ;
                while (fin >> tempTitle >> tempAId >> tempAuthorName)
                {

                    if (tempTitle == title)
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

        //Default Conctructor

        Book()
        {
            title = "";
            Author();
        }

        //parameterized Constructor

        Book(string title,const Author& a)
        {
            this->title = title;
            author=a;
        }

        // Destructor

        ~Book() {}

        //Book setter

        void settitle(string t)
        {
            title = t;
        }

        //author setter

        void setauthor(int id, string name, string email, string contact, string address)
        {
            author.setid(id);
            author.setName(name);
        }

        //Book getter

        string gettitle()const
        {
            return title;
        }

    
        //set details from user input
        
        void setdetails()
        {
            cout << "Book Title: "; getline(cin, title);
        }

        //output Stream operator overloading

        friend ostream& operator<<(ostream& os, const Book& book) {
            os << "\nTitle: " << book.title << "\nAuthor ID: " << book.author.getid()
               << "\nName: " << book.author.getName() << "\nEmail: " << book.author.getEmail() << "\nContact Number: " << book.author.getContactNumber()
               << "\nAddress: " << book.author.getAddress() << endl;
            return os;
        }

        //input stream operator overloading

        friend istream& operator>>(istream& in, Book& book) {
            cout << "\nEnter Book Title"; in >> book.title;
            book.author.setdetails();
            return in;
        }

        //tostring function
        
        string tostring()
        {
            return title + "\t" + to_string(author.getid()) + "\t" +
                author.getName() + "\n\n" ;
        }

        //Add book to file method

        void addBookToFile() {
            try {
                ofstream fout("book.txt", ios::app);
                if (check() == 0)
                {
                    fout << tostring();
                    cout << "\nBook added successfully!";
                }
                else {
                    cout << "\nBook title Already Exist!!!";
                }
                fout.close();
            }
            catch (const exception& ex) {
                cerr << "\nError: " << ex.what() << endl;
            }
        }

        //view book method

       static void viewAllBooks() {
            try {
                ifstream fin("book.txt");
                string line;
                while (getline(fin, line)) {
                    cout << line << endl;
                }
                fin.close();
            }
            catch (const exception& ex) {
                cerr << "\nError: " << ex.what() << endl;
            }
        }

       //Search Book method

       int SearchBook(int id) {
           try {
               ifstream fin("book.txt");
               int tempId, count = 0;
               string tempName, temptitle;

               while (fin >> temptitle >> tempId >> tempName)
               {
                   if (tempId == id)
                   {
                       cout << "Book title: " << temptitle << "\n"
                           << "Author ID: " << tempId << "\n"
                           << "Author Name: " << tempName << "\n\n";
                       count = 1;
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

        //update Book method

        void updateBook(string oldtitle) {
            try {

                ifstream fin("book.txt");
                ofstream fout("temp.txt");

                int tempAId;
                string tempTitle, tempAuthorName;
                
                int count = 0;
                while (fin >> tempTitle >> tempAId >> tempAuthorName)
                {

                    if (tempTitle == oldtitle)
                    {
                        if (check() <= 1)
                        {
                            fout << tostring();
                            count = 1;
                        }
                        else
                        {
                            fout << tempTitle << "\t" << tempAId << "\t" << tempAuthorName << "\n\n";
                            count = 2;
                        }
                    }
                    else {
                        fout << tempTitle << "\t" << tempAId << "\t" << tempAuthorName << "\n\n";
                    }
                }

                fin.close();
                fout.close();
                remove("book.txt");
                rename("temp.txt", "book.txt");
                if (count == 1) {
                    cout << "\nBook updated successfully!\n";
                }
                else if(count==0){
                    cout << "\nBook with Title '" << oldtitle << "' not found or Book Id Already Exists.\n";
                }
            }
            catch (const exception& ex) {
                cerr << "Error: " << ex.what() << endl;
            }
        }

        //Delete Book method

        void deleteBook(string title) {
            try {

                ifstream fin("book.txt");
                ofstream fout("tempo.txt");

                int tempAId;
                string tempTitle, tempAuthorName;
                bool found = false;

                while (fin >> tempTitle >> tempAId >> tempAuthorName )
                {

                    if (tempTitle == title)
                    {
                        found = true;
                        continue;
                    }
                    else
                    {
                        fout << tempTitle << "\t" << tempAId << "\t" << tempAuthorName << "\n\n";
                            
                    }

                }

                fin.close();
                fout.close();

                remove("book.txt");
                rename("tempo.txt", "book.txt");
                if (found==true) {
                    cout << "\nBook deleted successfully!\n";
                }
                else if(found==false){
                    cout << "\nBook with Title '" << title << "' not found.\n";
                }
            }
            catch (const exception& ex) {
                cerr << "Error: " << ex.what() << endl;
            }
        }
};
    