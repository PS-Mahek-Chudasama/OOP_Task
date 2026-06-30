# Library Management System

A simple C++ application to manage library books.
Built as a Object-Oriented Programming (OOP) assignment.

---

# Problem Statement

Managing library books manually is difficult. It becomes hard to keep track of
available books, issued books, and returned books.

This application provides a simple menu-driven system to manage library books
using Object-Oriented Programming concepts.

---

# Project Objective

Build a beginner-friendly C++ application that demonstrates core OOP concepts:

- Classes and Objects
- Encapsulation
- Inheritance
- Polymorphism
- Functions
- Debugging

---

# Features

1. Add Book
2. Display All Books
3. Search Book by ID
4. Issue Book
5. Return Book
6. Exit

---

# Technologies Used

- Language : C++
- Compiler : g++
- Storage : In-Memory Array

---

# Project Structure

```
LibraryManagementSystem/

│
├── main.cpp              → Complete source code
├── README.md             → Project documentation
├── DebuggingReport.md    → Debugging report
└── .gitignore
```

---

# Explanation of Classes

## Book

The Book class stores information about a single book.

Data Members:

- Book ID
- Title
- Author
- Issued Status

Functions:

- display()
- issueBook()
- returnBook()
- getID()
- isIssued()

This class demonstrates Encapsulation because the data members are protected
and accessed through member functions.

---

## PrintedBook

PrintedBook is a derived class of Book.

It inherits all data members and functions from the Book class.

It also stores:

- Number of Pages

The display() function is overridden to print the page count.

This class demonstrates:

- Inheritance
- Polymorphism

---

## Library

The Library class manages all books.

Functions:

- addBook()
- displayBooks()
- searchBook()
- issueBook()
- returnBook()

This class performs all library operations.

---

# OOP Concepts Demonstrated

## Classes and Objects

Classes used:

- Book
- PrintedBook
- Library

Object created:

```cpp
Library library;
```

---

## Encapsulation

Book details are stored inside the Book class.

Only public member functions are used to access or modify the data.

Example:

```cpp
protected:
    int id;
    string title;
    string author;
    bool issued;
```

---

## Inheritance

PrintedBook inherits from Book.

Example:

```cpp
class PrintedBook : public Book
```

---

## Polymorphism

The display() function is declared as virtual in the Book class and overridden
in the PrintedBook class.

Example:

```cpp
virtual void display();

void display() override;
```

---

## Functions

The project uses the following functions:

- addBook()
- displayBooks()
- searchBook()
- issueBook()
- returnBook()
- display()

---

## Debugging

One intentional logic bug was introduced in the Issue Book function.

The bug was identified, analyzed, and fixed.

See DebuggingReport.md for complete details.

---

# How Each Assignment Requirement is Satisfied

| Requirement | Implementation |
|-------------|----------------|
| Functions | addBook(), displayBooks(), searchBook(), issueBook(), returnBook() |
| Classes | Book, PrintedBook, Library |
| Objects | Library object created in main() |
| Encapsulation | Data members inside Book class |
| Inheritance | PrintedBook inherits Book |
| Polymorphism | display() function overridden |
| Debugging | Logic bug introduced and fixed |

---

# Project Workflow

```
Start Program
      ↓
Display Menu
      ↓
User Selects Option
      ↓
Library Function Executes
      ↓
Result Displayed
      ↓
Menu Repeats Until Exit
```

---

# Compilation

Compile using g++:

```bash
g++ main.cpp -o LibraryManagementSystem
```

---

# Run

Windows

```bash
LibraryManagementSystem.exe
```

Linux / Mac

```bash
./LibraryManagementSystem
```

---

# Sample Output

```
Library Management System

1. Add Book
2. Display Books
3. Search Book
4. Issue Book
5. Return Book
6. Exit

Enter Choice : 1

Enter Book ID : 101
Enter Title : C++ Programming
Enter Author : Bjarne Stroustrup
Enter Pages : 450

Book Added Successfully.
```

---

# Future Improvements

- Prevent duplicate Book IDs
- Save data into a file
- Add Delete Book option
- Add Update Book Details option
- Add Fine Calculation
- Add Student Record Management
