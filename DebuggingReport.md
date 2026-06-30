# Debugging Report

## Project Name

Library Management System

---

## Purpose

This report documents a bug that was intentionally introduced into the project
to demonstrate the debugging process as part of the Object-Oriented Programming (OOP) assignment.

---

## Bug Description

When the user selects **Option 4 – Issue Book**, the program displays the message
**"Book Issued Successfully."**, but the book status does not change to **Issued**.

The book remains **Available** even after issuing it.

---

## Expected Result

When the user issues a book, the status of the selected book should change from:

```
Available
```

to

```
Issued
```

---

## Actual Result (With Bug)

After selecting **Issue Book**, the program displays:

```
Book Issued Successfully.
```

However, when the user displays the book list, the status is still:

```
Available
```

instead of:

```
Issued
```

---

## Root Cause

The bug is inside the `issueBook()` function.

Instead of calling:

```cpp
book.issueBook();
```

the program incorrectly calls:

```cpp
book.returnBook();
```

Since `returnBook()` sets the book status to **Available**, the book is never marked as issued.

---

## Debugging Steps

### Step 1 – Identify the Bug

Opened `main.cpp` and located the `issueBook()` function.

The buggy code was:

```cpp
book.returnBook();   // BUG
```

---

### Step 2 – Run the Program

Compiled and executed the program.

Performed the following steps:

1. Added a new book.
2. Displayed the book list.
3. Selected **Issue Book**.
4. Entered the Book ID.
5. Displayed the book list again.

The program printed:

```
Book Issued Successfully.
```

but the book status remained **Available**.
---

### Step 3 – Fix the Bug

Changed the incorrect line:

```cpp
book.returnBook();
```

to:

```cpp
book.issueBook();
```

---

### Step 4 – Verify the Fix

Compiled and ran the program again.

Repeated the same steps:

1. Added a book.
2. Issued the book.
3. Displayed all books.

Now the status correctly changed to:

```
Issued
```
---

## Observations

- The program compiled successfully.
- There was no compile-time error.
- There was no runtime error.
- The problem was a **Logic Error** because the wrong function was called.
- The output was incorrect even though the program executed normally.

---

## Final Fix

### Before (Buggy)

```cpp
book.returnBook();
```

### After (Fixed)

```cpp
book.issueBook();
```

---

## Lessons Learned

1. Logic errors do not generate compile-time errors.
2. A program can run successfully but still produce incorrect results.
3. Testing every feature is important to verify the program's behavior.
4. Reading the code carefully helps identify incorrect function calls.
5. Debugging is an important step in software development.
