#include <stdlib.h>
#include <iostream>
#include <iomanip>
#include "Database.h"
#include <boost/tokenizer.hpp>
#include <string>
#include <vector>
using namespace std;

int main(int argc, char *argv[])
{
    Database &db = Database::getInstance();
    Connection *con = db.getConnection();
    if (!con){
        cout << "Connection error!";
        return -1;
    }
    float i,sum;
    char s[5];
    size_t size;
    int selection,offset,x;
    string str1, str2, str3;
    PreparedStatement *pstmt;
    ResultSet *rset;
    while(1){
        cout<<"1. Print all books in stock"<<endl;
        cout<<"2. Print all open orders"<<endl;
        cout<<"3. Show all customers"<<endl;
        cout<<"4. Show all suppliers"<<endl;
        cout<<"5. Print all invoices between dates..."<<endl;
        cout<<"6. Print all books that are on sale"<<endl;
        cout<<"7. Check if book is in stock"<<endl;
        cout<<"8. List all the suppliers for a book"<<endl;
        cout<<"9. How many copies of a book sold since..."<<endl;
        cout<<"10. How many books did a customer purchase since..."<<endl;
        cout<<"11. Show the customer that purchased most books since..."<<endl;
        cout<<"12. Show the most frequently used supplier since..."<<endl;
        cout<<"13. Show all orders(from supplier) between dates..."<<endl;
        cout<<"14. Show all orders(from supplier) that was purchased by customers between dates..."<<endl;
        cout<<"15. Total amount of discount that a customer had since..."<<endl;
        cout<<"16. Store's total income in a quarter"<<endl;
        cout<<"17. Number of new customers since..."<<endl;
        cout<<"18. Total amount of orders from supplier between dates..."<<endl;
        cout<<"19. Total gross sales by a sales person between dates..."<<endl;
        cout<<"20. Top 10 most selling books between dates..."<<endl;
        cout<<"0. EXIT"<<endl;
        cin >> selection;
        switch (selection){
            case 1:
                offset = 0;
                pstmt = con->prepareStatement("SELECT * FROM book WHERE inStock = 1");
                rset = pstmt->executeQuery();
                size = rset->rowsCount();
                while (offset < size){
                    pstmt = con->prepareStatement("SELECT * FROM book WHERE inStock = 1 LIMIT 10 OFFSET ?");
                    pstmt->setInt(1, offset);
                    rset = pstmt->executeQuery();
                    rset->beforeFirst();
                    cout << std::setw(50) << std::left << "TITLE" << std::setw(30) << std::left << "AUTHOR" << endl;
                    while(rset->next()) {
                        str1 = rset->getString("title");
                        str2 = rset->getString("author");
                        cout << std::setw(50) << std::left << str1 << std::setw(30) << std::left << str2 << endl;
                    }
                    if (rset->rowsCount() == 10)
                    {
                        cout<<"\n1 - Next Page or 2 - Previous page"<<endl;
                        cin>>x;
                        if (x == 1){
                            offset += 10;
                        }
                        else if (x == 2){
                            offset -= 10;
                        }
                    }
                    else break;
                }
                break;
            case 2:
                pstmt = con->prepareStatement("SELECT title, _status FROM orders INNER JOIN book ON orders.book_id = book.book_id WHERE _status != 'sold'");
                rset = pstmt->executeQuery();
                size = rset->rowsCount();
                offset = 0;
                while (offset < size){
                    pstmt = con->prepareStatement("SELECT title, _status FROM orders INNER JOIN book ON orders.book_id = book.book_id WHERE _status != 'sold' LIMIT 10 OFFSET ?");
                    pstmt->setInt(1, offset);
                    rset = pstmt->executeQuery();
                    rset->beforeFirst();
                    cout << std::setw(50) << std::left << "TITLE" << std::setw(10) << std::left << "STATUS" << endl;
                    while (rset->next()) {
                        str1 = rset->getString("title");
                        str2 = rset->getString("_status");
                        cout << std::setw(50) << std::left << str1 << std::setw(10) << std::right << str2 << endl;
                    }
                    
                    if (rset->rowsCount() == 10)
                    {
                        cout<<"\n1 - Next Page or 2 - Previous page"<<endl;
                        cin>>x;
                        if (x == 1){
                            offset += 10;
                        }
                        else if (x == 2){
                            offset -= 10;
                        }
                    }
                    else break;
                }
                break;
            case 3:
                pstmt = con->prepareStatement("SELECT * FROM customer");
                rset = pstmt->executeQuery();
                size = rset->rowsCount();
                offset = 0;
                while (offset < size){
                    pstmt = con->prepareStatement("SELECT * FROM customer LIMIT 10 OFFSET ?");
                    pstmt->setInt(1, offset);
                    rset = pstmt->executeQuery();
                    rset->beforeFirst();
                    cout << std::setw(50) << std::left << "NAME" << std::setw(50) << std::left << "ADDRESS" << std::setw(10) << std::left << "PHONE" << endl;
                    while (rset->next()) {
                        str1 = rset->getString("customer_name");
                        str2 = rset->getString("customer_address");
                        str3 = rset->getString("customer_phone");
                        cout << std::setw(50) << std::left << str1 << std::setw(50) << std::left << str2 << std::setw(10) << std::left << str3 << endl;
                    }
                    if (rset->rowsCount() == 10)
                    {
                        cout<<"\n1 - Next Page or 2 - Previous page"<<endl;
                        cin>>x;
                        if (x == 1){
                            offset += 10;
                        }
                        else if (x == 2){
                            offset -= 10;
                        }
                    }
                    else break;
                }
                break;
            case 4:
                pstmt = con->prepareStatement("SELECT * FROM supplier");
                rset = pstmt->executeQuery();
                rset->beforeFirst();
                i = 0;
                cout << std::setw(50) << std::left << "NAME" << std::setw(50) << std::left << "ADDRESS" << std::setw(10) << std::left << "PHONE" << endl;
                while (rset->next()) {
                    str1 = rset->getString("supplier_name");
                    str2 = rset->getString("supplier_address");
                    str3 = rset->getString("supplier_phone");
                    cout << std::setw(50) << std::left << str1 << std::setw(50) << std::left << str2 << std::setw(10) << std::left << str3 << endl;
                    ++i;
                    if (i == 15){
                        i=0;
                        cout<<"\npress a key to continue...";
                        getchar();
                    }
                }
                cout<<"\npress a key to continue..."<<endl;
                getchar();
                getchar();
                break;
            case 5:
                cout<<"Enter start date(YYYY-MM-DD):"<<endl;
                cin>>str1;
                cout<<"Enter end date(YYYY-MM-DD):"<<endl;
                cin>>str2;
                pstmt = con->prepareStatement("SELECT * FROM purchase WHERE purchase_date BETWEEN ? AND ?");
                pstmt->setString(1, str1);
                pstmt->setString(2, str2);
                rset = pstmt->executeQuery();
                rset->beforeFirst();
                i = 0;
                cout << std::setw(15) << std::left << "PURCHASE ID" << std::setw(30) << std::left << "DATE" << endl;
                while (rset->next()) {
                    str1 = rset->getString("purchase_id");
                    str2 = rset->getString("purchase_date");
                    cout << std::setw(15) << std::left << str1 << std::setw(30) << std::left << str2 << endl;
                    ++i;
                    if (i == 15){
                        i=0;
                        cout<<"\npress a key to continue...";
                        getchar();
                    }
                }
                cout<<"\npress a key to continue..."<<endl;
                getchar();
                getchar();
                break;
            case 6:
                pstmt = con->prepareStatement("SELECT * FROM bookstore.disc_global WHERE NOW() BETWEEN start_date AND end_date");
                rset = pstmt->executeQuery();
                rset->beforeFirst();
                if (rset->rowsCount() >= 1)
                {
                    pstmt = con->prepareStatement("SELECT * FROM book WHERE discount = 1;");
                    rset = pstmt->executeQuery();
                    rset->beforeFirst();
                    i = 0;
                    cout << std::setw(50) << std::left << "TITLE" << std::setw(30) << std::left << "AUTHOR" << endl;
                    while (rset->next()) {
                        str1 = rset->getString("title");
                        str2 = rset->getString("author");
                        cout << std::setw(50) << std::left << str1 << std::setw(30) << std::left << str2 << endl;
                        ++i;
                        if (i == 15){
                            i=0;
                            cout<<"\npress a key to continue...";
                            getchar();
                        }
                    }
                }
                else
                    cout<<"There are no discounts at the moment.";
                cout<<"\npress a key to continue..."<<endl;
                getchar();
                getchar();
                break;
            case 7:
                cout<<"Enter book's name:"<<endl;
                cin.ignore();
                getline(std::cin,str1);
                pstmt = con->prepareStatement("SELECT * FROM book WHERE title = ?");
                pstmt->setString(1, str1);
                rset = pstmt->executeQuery();
                rset->beforeFirst();
                rset->next();
                if (rset->getBoolean("inStock"))
                    cout << str1 << " is IN STOCK"<<endl;
                else
                    cout << "NOT IN STOCK"<<endl;
                cout<<"\npress a key to continue..."<<endl;
                getchar();
                break;
            case 8:
                cout<<"Enter book's name:"<<endl;
                cin.ignore();
                getline(std::cin,str1);
                pstmt = con->prepareStatement("SELECT supplier_name FROM supplied_by INNER JOIN book ON book.book_id = supplied_by.book_id INNER JOIN supplier ON supplied_by.supplier_id = supplier.supplier_id WHERE title = ?");
                pstmt->setString(1, str1);
                rset = pstmt->executeQuery();
                rset->beforeFirst();
                i = 0;
                while (rset->next()) {
                    str1 = rset->getString("supplier_name");
                    cout << str1 << endl;
                    ++i;
                    if (i == 15){
                        i=0;
                        cout<<"\npress a key to continue...";
                        getchar();
                    }
                }
                cout<<"\npress a key to continue..."<<endl;
                getchar();
                break;
            case 9:
                cout<<"Enter book's name:"<<endl;
                cin.ignore();
                getline(std::cin,str1);
                
                pstmt = con->prepareStatement("SELECT * FROM book WHERE title = ?");
                pstmt->setString(1, str1);
                rset = pstmt->executeQuery();
                rset->beforeFirst();
                rset->next();
                str1 = rset->getString("book_id");
                cout<<"Enter date (YYYY-MM-DD):"<<endl;
                cin.ignore();
                getline(std::cin,str2);
                pstmt = con->prepareStatement("SELECT COUNT(1) FROM purchase RIGHT JOIN purchase_info ON purchase.purchase_id = purchase_info.purchase_id WHERE purchase.purchase_date > ? AND book_id = ? AND isCanceled = 0");
                pstmt->setString(1, str2);
                pstmt->setString(2, str1);
                rset = pstmt->executeQuery();
                rset->beforeFirst();
                rset->next();
                cout<<"Total books sold:"<<rset->getInt("COUNT(1)")<<endl;
                cout<<"\npress a key to continue..."<<endl;
                getchar();
                break;
            case 10:
                cout<<"Enter customer id:"<<endl;
                cin.ignore();
                getline(std::cin,str1);
                cout<<"Enter date (YYYY-MM-DD):"<<endl;
                cin.ignore();
                getline(std::cin,str2);
                pstmt = con->prepareStatement("SELECT COUNT(1) FROM purchase RIGHT JOIN purchase_info ON purchase.purchase_id = purchase_info.purchase_id WHERE purchase.purchase_date > ? AND customer_id=?");
                pstmt->setString(1, str2);
                pstmt->setString(2, str1);
                rset = pstmt->executeQuery();
                rset->beforeFirst();
                rset->next();
                cout<<"Total books sold:"<<rset->getInt("COUNT(1)")<<endl;
                cout<<"\npress a key to continue..."<<endl;
                getchar();
                break;
            case 11:
                cout<<"Enter date (YYYY-MM-DD):"<<endl;
                cin.ignore();
                getline(std::cin,str1);
                pstmt = con->prepareStatement("SELECT customer_id, COUNT(customer_id) as most FROM purchase RIGHT JOIN purchase_info ON purchase.purchase_id = purchase_info.purchase_id WHERE purchase.purchase_date > ? GROUP BY customer_id ORDER BY most DESC LIMIT 1");
                pstmt->setString(1, str1);
                rset = pstmt->executeQuery();
                rset->beforeFirst();
                rset->next();
                cout<<"Customer id:"<<rset->getInt("customer_id")<<endl;
                cout<<"\npress a key to continue..."<<endl;
                getchar();
                break;
            case 12:
                cout<<"Enter date (YYYY-MM-DD):"<<endl;
                cin.ignore();
                getline(std::cin,str1);
                pstmt = con->prepareStatement("SELECT supplier_id, COUNT(supplier_id) as most FROM orders WHERE order_date > ? GROUP BY supplier_id ORDER BY most DESC LIMIT 1");
                pstmt->setString(1, str1);
                rset = pstmt->executeQuery();
                rset->beforeFirst();
                rset->next();
                cout<<"Supplier id:"<<rset->getInt("supplier_id")<<endl;
                cout<<"\npress a key to continue..."<<endl;
                getchar();
                break;
            case 13:
                cout<<"Enter start date (YYYY-MM-DD):"<<endl;
                cin>>str1;
                cout<<"Enter end date (YYYY-MM-DD):"<<endl;
                cin>>str2;
                pstmt = con->prepareStatement("SELECT COUNT(order_id) FROM orders WHERE order_date BETWEEN ? AND ?");
                pstmt->setString(1, str1);
                pstmt->setString(2, str2);
                rset = pstmt->executeQuery();
                rset->beforeFirst();
                rset->next();
                cout<<"Total books ordered:"<<rset->getInt("COUNT(order_id)")<<endl;
                cout<<"\npress a key to continue..."<<endl;
                getchar();
                getchar();
                break;
            case 14:
                cout<<"Enter start date (YYYY-MM-DD):"<<endl;
                cin>>str1;
                cout<<"Enter end date (YYYY-MM-DD):"<<endl;
                cin>>str2;
                pstmt = con->prepareStatement("SELECT COUNT(order_id) FROM orders WHERE order_date BETWEEN ? AND ? AND _status = 'sold';");
                pstmt->setString(1, str1);
                pstmt->setString(2, str2);
                rset = pstmt->executeQuery();
                rset->beforeFirst();
                rset->next();
                cout<<"Total books sold:"<<rset->getInt("COUNT(order_id)")<<endl;
                cout<<"\npress a key to continue..."<<endl;
                getchar();
                getchar();
                break;
            case 15:
                cout<<"Enter customer id:"<<endl;
                cin>>str1;
                cout<<"Enter start date (YYYY-MM-DD):"<<endl;
                cin>>str2;
                pstmt = con->prepareStatement("SELECT book.title, book.price, purchase_info.disc FROM purchase_info INNER JOIN purchase ON purchase_info.purchase_id = purchase.purchase_id INNER JOIN book ON purchase_info.book_id = book.book_id WHERE customer_id = ? AND isCanceled = 0 AND purchase.purchase_date > ?");
                pstmt->setString(1, str1);
                pstmt->setString(2, str2);
                rset = pstmt->executeQuery();
                rset->beforeFirst();
                sum = 0;
                while (rset->next()) {
                    x = rset->getInt("price");
                    str1 = rset->getString("disc");
                    s[0] = str1[0];
                    s[1] = str1[1];
                    s[2] = str1[2];
                    s[3] = str1[3];
                    s[4] = '\0';
                    i = atof(s);
                    sum += (x*i);
                }
                cout<<"Total discount: "<<sum<<endl;
                cout<<"\npress a key to continue..."<<endl;
                getchar();
                getchar();
                break;
            case 16:
                cout<<"Choose start date (e.g. 2018-01-01):"<<endl;
                cin>>str1;
                cout<<"Choose end date (e.g. 2018-03-31):"<<endl;
                cin>>str2;
                pstmt = con->prepareStatement("SELECT SUM(book.price) FROM ((purchase_info INNER JOIN purchase ON purchase_info.purchase_id = purchase.purchase_id) INNER JOIN book ON purchase_info.book_id = book.book_id) WHERE purchase_date BETWEEN ? AND ? AND purchase_info.isCanceled = 0;");
                pstmt->setString(1, str1);
                pstmt->setString(2, str2);
                rset = pstmt->executeQuery();
                rset->beforeFirst();
                rset->next();
                cout<<"Total gross income:"<<rset->getInt("SUM(book.price)")<<endl;
                cout<<"\npress a key to continue..."<<endl;
                getchar();
                getchar();
                break;
            case 17:
                cout<<"Choose date (YYYY-MM-DD):"<<endl;
                cin>>str1;
                pstmt = con->prepareStatement("SELECT COUNT(customer_id) FROM customer WHERE join_date > ?");
                pstmt->setString(1, str1);
                rset = pstmt->executeQuery();
                rset->beforeFirst();
                rset->next();
                cout<<"Number of new customers:"<<rset->getInt("COUNT(customer_id)")<<endl;
                cout<<"\npress a key to continue..."<<endl;
                getchar();
                getchar();
                break;
            case 18:
                cout<<"Choose supplier id:"<<endl;
                cin>>str1;
                cout<<"Choose start date (YYYY-MM-DD):"<<endl;
                cin>>str2;
                cout<<"Choose end date (YYYY-MM-DD):"<<endl;
                cin>>str3;
                pstmt = con->prepareStatement("SELECT SUM(supplied_by.price) FROM orders INNER JOIN supplied_by ON orders.supplier_id = supplied_by.supplier_id AND orders.book_id = supplied_by.book_id WHERE orders.supplier_id = ? AND orders.order_date BETWEEN ? AND ?");
                pstmt->setString(1, str1);
                pstmt->setString(2, str2);
                pstmt->setString(3, str3);
                rset = pstmt->executeQuery();
                rset->beforeFirst();
                rset->next();
                cout<<"Total gross orders from supplier:"<<rset->getInt("SUM(supplied_by.price)")<<endl;
                cout<<"\npress a key to continue..."<<endl;
                getchar();
                getchar();
                break;
            case 19:
                cout<<"Choose employee id:"<<endl;
                cin>>str1;
                cout<<"Choose start date (YYYY-MM-DD):"<<endl;
                cin>>str2;
                cout<<"Choose end date (YYYY-MM-DD):"<<endl;
                cin>>str3;
                pstmt = con->prepareStatement("SELECT SUM(book.price) FROM ((purchase_info INNER JOIN purchase ON purchase_info.purchase_id = purchase.purchase_id) INNER JOIN book ON purchase_info.book_id = book.book_id) WHERE purchase_info.employee_id = ? AND purchase.purchase_date BETWEEN ? AND ?");
                pstmt->setString(1, str1);
                pstmt->setString(2, str2);
                pstmt->setString(3, str3);
                rset = pstmt->executeQuery();
                rset->beforeFirst();
                rset->next();
                cout<<"Total gross sales by employee:"<<rset->getInt("SUM(book.price)")<<endl;
                cout<<"\npress a key to continue..."<<endl;
                getchar();
                getchar();
                break;
            case 20:
                cout<<"Enter start date (YYYY-MM-DD):"<<endl;
                cin>>str1;
                cout<<"Enter end date (YYYY-MM-DD):"<<endl;
                cin>>str2;
                pstmt = con->prepareStatement("SELECT purchase_info.book_id, title, COUNT(purchase_info.book_id) as most FROM purchase RIGHT JOIN purchase_info ON purchase.purchase_id = purchase_info.purchase_id RIGHT JOIN book ON purchase_info.book_id = book.book_id WHERE purchase.purchase_date BETWEEN ? AND ? GROUP BY purchase_info.book_id ORDER BY most DESC LIMIT 10");
                pstmt->setString(1, str1);
                pstmt->setString(2, str2);
                rset = pstmt->executeQuery();
                rset->beforeFirst();
                i = 0;
                while (rset->next()) {
                    str1 = rset->getString("title");
                    cout << ++i <<"."<< str1 << endl;
                }
                cout<<"\npress a key to continue..."<<endl;
                getchar();
                getchar();
                break;
            default:
                return 1;
        }
    }

}
