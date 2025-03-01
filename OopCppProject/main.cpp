#include <iostream>
#include <string>
#include "Inventory.h"
#include "Sales.h"
#include "Customer.h"
#include "Person.h"
#include "Author.h"
#include "Book.h"

using namespace std;

void menu(); //main menu method
void Inventorymenu();//Inventory menu method
void Salesmenu();//sales menu method
void manageSales();//manage sales menu method to perform specific task on sales file
void performSales();//perform sales method to display option for buy book
void Customermenu();//customer menu method that diplay option to perform with customr file

int main()// main function
{
	string res;
	int resint;
	while(true)
	{
		menu();
		cout << "\nEnter: "; cin >> res;
		resint = stoi(res);
		switch (resint)
		{
			case 0:
				exit(0);
				break;
			case 1:
				
				//calling inventory menu method
				do {
					system("cls");
					Inventorymenu();
					cout << "\nEnter: "; cin >> res;
					resint = stoi(res);
					switch (resint)
					{
						case 0:
							system("cls");
							
							break;
						case 1:
						{//setting details of inventory and adding to file
							int id, quantity = 0;
							float price = 0;
							string title;
							cout << "\nEnter:-\n\nBookId: "; cin >> id;
							cin.ignore();
							cout << "Book Title: "; getline(cin, title);
							Author a;
							a.setdetails();
							cout << "Book Quantity: "; cin >> quantity;
							cout << "Book Price: "; cin >> price;
							Book b(title, a);
							b.addBookToFile();
							a.addAuthorToFile();
							BookInventory bi(id, quantity, price, b, a);
							bi.addBookToFile();
							cout << endl;
							system("pause");
							system("cls");
						}
						break;
						case 2://search and view inventory details
							cout << endl;
							BookInventory::viewAllBooks();
							cout << "\nPress 1 to search Book\nPress any key to continue\nEnter: "; cin >> res;
							if (res == "1")
							{
								cout << "Enter ID to Search: "; cin >> res;
								cout << endl;
								int id = stoi(res);
								BookInventory bi;
								bi.searchBooks(id);
								cout << endl;
							}system("pause");
							break;
							
						case 3:
						{//update function for updating inventory records
							
							int oldid,newid,aid, quantity = 0;
							float price = 0;
							string oldtitle,newtitle;
							cout << endl;
							BookInventory::viewAllBooks();
							cout << "\n\nEnter Old BookId, BookTitle, AuthorId to Update:-\n\nBookId: "; cin >> oldid;
							cin.ignore();
							cout << "Book Title: "; getline(cin, oldtitle);
							cout << "Book AuthorId: "; cin >> aid;
							cout << "\nEnter New details:-\n\n";
							cout << "Book Id: "; cin >> newid;
							cin.ignore();
							cout << "Book Title: "; getline(cin, newtitle);
							Author a;
							a.setdetails();
							cout << "Book Quantity: "; cin >> quantity;
							cout << "Book Price: "; cin >> price;
							Book b(newtitle, a);
							b.updateBook(oldtitle);
							a.updateAuthor(aid);
							BookInventory bi(newid, quantity, price, b, a);
							bi.updateInventory(oldid);
							cout << endl<<endl;
						}system("pause");
						break;
						case 4:
						{//delete method to delete records from inventory
							string title;
							BookInventory bi;
							cout << endl;
							bi.viewAllBooks();
							cin.ignore();
							cout << "\nEnter Book Title to Delete: "; getline(cin, title);
							bi.deleteBook(title);
							cout << endl;
						}system("pause");
						break;
						case 5://search and view Author details
							cout << endl;
							Author::viewAllAuthor();
							cout << "\nPress 1 to search Author\nPress any key to continue\nEnter: "; cin >> res;
							if (res == "1")
							{
								cout << "Enter ID to Search: "; cin >> res;
								int id = stoi(res);
								cout << endl;
								Author a;
								a.SearchAuthor(id);
								cout << endl;
							}system("pause");
							break;
						default:
							cout << "\nInvalid Choice!!!\n";
							system("pause");
							break;

					}
					
				} while (res != "0");
				break;

			case 2:
				
				do {
					system("cls");
					
					//calling Sales menu method
					Salesmenu();
					cout << "\nEnter: "; cin >> res;
					resint = stoi(res);
					switch (resint)
					{
					case 0:
						system("cls");
						
						break;
					case 1:
					{ 
						system("cls");
						//calling manage sales method
							manageSales();
							cout << "\nEnter: "; cin >> res;
							resint = stoi(res);
							switch (resint)
							{
							case 0:
								system("cls");
								break;
							case 1://callin view and search methods of sales 
								cout << endl;
								Sales::viewAllSales();
								cout << "\nPress 1 to search Sale Record\nPress any key to continue\nEnter: "; cin >> res;
								if (res == "1")
								{
									cout << "Enter ID to Search: "; cin >> res;
									int sid = stoi(res);
									Sales::searchSales(sid); cout << endl;
								}system("pause");
								break;
							case 2://calling delete method of sales to delete sales records
								Sales s;
								Sales::viewAllSales();

								cout << "\nEnter Id to Delete: "; cin >> res;
								int sid = stoi(res);
								s.deleteSales(sid); cout << endl; system("pause");
								break;
								
							}
						
					}
					break;
					case 2:
					{
						system("cls");
						//calling perform sales menu method
							performSales();
							cout << "\nEnter: "; cin >> res;
							resint = stoi(res);
							switch (resint)
							{
							case 0:
								system("cls");
								break;
							case 1://calling method to buy book
								BookInventory b;
								cout << endl;
								b.viewAllBooks();
								int check;
								int id;
								while (true)
								{
										
										cout << "Enter Book ID to Buy: "; cin >> res;
										id = stoi(res);
										cout << endl;
										check = b.searchBooks(id);
										if (check == 1)
										{
											break;
										}
										else if (check == 0)
										{
											cout << "\n\nPress 1 to Go Back";
											cout << "\nPress Any key to Continue";
											cout << "\nEnter: "; cin >> res;
											cout << endl;
											if (res == "1")
											{
												system("pause");
												break;
											}
											else
											{
												continue;
											}

										}
									}
									if (check == 1)
									{
										int cid;
										cout << "\nCustomer Details:-\n\n";
										Customer c;
										c.viewAllCustomer();
										while (true)
										{
											int check;
											cout << "\nEnter Customer Id to Add details: "; cin >> res;
											cid = stoi(res);
											cout << endl;
											check = c.SearchCustomer(cid);
											if (check == 1)
											{
												int q;
												cout << "Enter quantity you want to buy: "; cin >> res;
												q = stoi(res);
												Sales s(c, b, q);
												s.addSalesToFile();
												system("pause");
												break;
											}
											else if (check == 0)
											{
												cout << "\n\nDo you want to Add Customer or Go Back";
												cout << "\n\nPress 1 to Add Customer";
												cout << "\nPress Any key to Go Back";
												cout << "\nEnter: "; cin >> res;
												if (res == "1")
												{
													cout << "\nAdd Customer Details:-\n";
													Customer c;
													cin >> c;
													c.addCustomerToFile();
													cout << endl;
													continue;
												}
												else
												{
													cout << endl;
													system("pause");
													break;
												}


											}


									}
								}
							}
						
					}
					break;
					
					}
					} while (res != "0");
					break;

			case 3:
				
				do {
					system("cls");
					
					//caling customer menu method
					Customermenu();
					cout << "\nEnter: "; cin >> res;
					resint = stoi(res);
					switch (resint)
					{
						case 0:
							system("cls");
							break;
						case 1:
						{//add customer details to file
							Customer c;
							cin >> c;
							c.addCustomerToFile();
							cout << endl;
						}system("pause");
						break;
						case 2://viewing and searching details of customer
							cout << endl;
							Customer::viewAllCustomer();
							cout << "\nPress 1 to search Customer\nPress any key to continue\nEnter: "; cin >> res;
							if (res == "1")
							{
								cout << "\nEnter ID to Search: "; cin >> res;
								int id = stoi(res);
								Customer c;
								cout << endl;
								c.SearchCustomer(id);
							}cout << endl;
							system("pause");
							break;
						case 3:
						{//updating customer details
							int id;
							Customer c;
							cout << endl;
							c.viewAllCustomer();
							cout << "\nEnter Customer ID to Update: "; cin >> res;
							id = stoi(res);
							cout << endl;
							cin >> c;
							c.updateCustomer(id);
							cout << endl;							
						}system("pause");
						break;
						case 4:
						{//deleting customer details
							int id;
							Customer c;
							cout << endl;
							c.viewAllCustomer();
							cout << "\nEnter Customer ID to Delete: "; cin >> res;
							id = stoi(res);
							cout << endl;
							c.deleteCustomer(id);
							cout << endl;
						}system("pause");
						break;
						default:
							cout << "\nInvalid Choice!!!\n"; system("pause");
							break;

					}

				} while (res != "0");
				break;
								
			default:
				cout << "\nInvalid Choice!!!\n";
				system("pause");
				break;
		}

	}
	return 0;
}

// main menu

void menu()
{
	cout << "\n\n\n\t\t\t\t\t\t\t\t***WELCOME TO BOOK SHOP MANAGMENT SYSTEM***\t\n\n\n";
	cout << "Press 0 to Exit";
	cout << "\nPress 1 to Manage Inventory Details";
	cout << "\nPress 2 to Manage Sales Details";
	cout << "\nPress 3 to Manage Customer Details";
}

//Inventory menu

void Inventorymenu()
{
	cout << "\n\n\n\t\t\t\t\t\t\t\t***WELCOME TO BOOK SHOP MANAGMENT SYSTEM***\t\n\n\n";
	cout << "Press 0 to go to Main menu";
	cout << "\nPress 1 to Add Book Details in Inventory";
	cout << "\nPress 2 to Search/View Books in Inventory";
	cout << "\nPress 3 to Update Inventory Details";
	cout << "\nPress 4 to Delete Inventory Details";
	cout << "\nPress 5 to view/search Author Details";
}

//Salesmenu

void Salesmenu()
{
	cout << "\n\n\n\t\t\t\t\t\t\t\t***WELCOME TO BOOK SHOP MANAGMENT SYSTEM***\t\n\n\n";
	cout << "Press 0 to go to Main menu";
	cout << "\nPress 1 to Open Sales Details";
	cout << "\nPress 2 to Sell Book";
}

//manage sales menu

void manageSales()
{
	cout << "\n\n\n\t\t\t\t\t\t\t\t***WELCOME TO BOOK SHOP MANAGMENT SYSTEM***\t\n\n\n";
	cout << "Press 0 to go to Main menu";
	cout << "\nPress 1 to Search/View Sales Details";
	cout << "\nPress 2 to Delete Sales Details";
}

//perform sales menu

void performSales()
{
	cout << "\n\n\n\t\t\t\t\t\t\t\t***WELCOME TO BOOK SHOP MANAGMENT SYSTEM***\t\n\n\n";
	cout << "Press 0 to go to Main menu";
	cout << "\nPress 1 to View Books\n";
}

//Customer menu

void Customermenu()
{

	cout << "\n\n\n\t\t\t\t\t\t\t\t***WELCOME TO BOOK SHOP MANAGMENT SYSTEM***\t\n\n\n";
	cout << "Press 0 to go to main menu";
	cout << "\nPress 1 to Add Customer Details";
	cout << "\nPress 2 to Search/View Customer Details";
	cout << "\nPress 3 to Update Customer Details";
	cout << "\nPress 4 to Delete Customer Details";
}