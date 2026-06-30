#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Base Class

class Book
{
protected:
    int id;
    string title;
    string author;
    bool issued;

public:
    Book(int i, string t, string a)
    {
        id = i;
        title = t;
        author = a;
        issued = false;
    }

    virtual void display()
    {
        cout << "Book ID : " << id<<endl;
        cout << "Title   : " << title<<endl;
        cout << "Author  : " << author<<endl;
        cout << "Status  : ";

        if (issued)
            cout << "Issued";
        else
            cout << "Available";

        cout << endl;
    }

    int getID()
    {
        return id;
    }

    bool isIssued()
    {
        return issued;
    }

    void issueBook()
    {
        issued = true;
    }

    void returnBook()
    {
        issued = false;
    }

    string getTitle()
    {
        return title;
    }

    virtual ~Book() {}
};

// Derived Class

class PrintedBook : public Book
{
private:
    int pages;

public:
    PrintedBook(int id, string title, string author, int p)
        : Book(id, title, author)
    {
        pages = p;
    }

    void display() override
    {
        Book::display();
        cout << "Pages   : " << pages << endl;
    }
};

// Library Class

class Library
{
private:
    vector<PrintedBook> books;

public:
    void addBook()
    {
        int id, pages;
        string title, author;

        cout << "Enter Book ID : "<<endl;
        cin >> id;

        // cin.ignore();

        cout << "Enter Title : ";
        getline(cin, title);

        cout << "Enter Author : ";
        getline(cin, author);

        cout << "Enter Pages : ";
        cin >> pages;

        books.push_back(PrintedBook(id, title, author, pages));

        cout << "Book Added Successfully."<<endl;
    }

    void displayBooks()
    {
        if (books.empty())
        {
            cout << "No Books Available."<<endl;
            return;
        }

        for (auto &book : books)
        {
            cout << endl;
            book.display();
        }
    }

    void searchBook()
    {
        int id;

        cout << "Enter Book ID : "<<endl;
        cin >> id;

        for (auto &book : books)
        {
            if (book.getID() == id)
            {
                book.display();
                return;
            }
        }

        cout << "Book Not Found."<<endl;
    }

    void issueBook()
    {
        int id;

        cout << "Enter Book ID : "<<endl;
        cin >> id;

        for (auto &book : books)
        {
            if (book.getID() == id)
            {
                if (book.isIssued())
                {
                    cout << "Already Issued."<<endl;
                }
                else
                {
                    book.issueBook();
                    // book.returnBook();   <<-- Incorrect function call for interntional bug
                    cout << "Book Issued Successfully."<<endl;
                }
                return;
            }
        }

        cout << "Book Not Found."<<endl;
    }

    void returnBook()
    {
        int id;

        cout << "Enter Book ID : "<<endl;
        cin >> id;

        for (auto &book : books)
        {
            if (book.getID() == id)
            {
                if (!book.isIssued())
                {
                    cout << "Book was not issued."<<endl;
                }
                else
                {
                    book.returnBook();
                    cout << "Book Returned Successfully."<<endl;
                }

                return;
            }
        }

        cout << "Book Not Found."<<endl;
    }
};

// Main

int main()
{
    Library library;
    int choice;
    do
    {
        cout << endl;
        cout << "Library Management System : "<<endl;
        cout << endl;
        cout << "1. Add Book"<<endl;
        cout << "2. Display Books"<<endl;
        cout << "3. Search Book"<<endl;
        cout << "4. Issue Book"<<endl;
        cout << "5. Return Book"<<endl;
        cout << "6. Exit"<<endl;
        cout << "Enter Choice : ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            library.addBook();
            break;

        case 2:
            library.displayBooks();
            break;

        case 3:
            library.searchBook();
            break;

        case 4:
            library.issueBook();
            break;

        case 5:
            library.returnBook();
            break;

        case 6:
            cout << "Thank You!"<<endl;
            break;

        default:
            cout << "Invalid Choice"<<endl;
        }

    } while (choice != 6);

    return 0;
}