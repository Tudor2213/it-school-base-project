<!-- Overview

This project is a console-based library management system written in C++. It was built to simulate how a small library might handle books, members, and borrowing activity. The program runs entirely in the terminal and uses a menu system to guide the user through different actions.

A README like this is meant to act as a guide for anyone opening the project, explaining what it does and how to use it .

What the program does

The application allows you to manage a small collection of books and members. You can add or remove books, register members, and keep track of which books are currently borrowed.

It also stores a simple history of transactions, so you can see who borrowed or returned a book.

How it works

The program is built using a few core classes.

A Book stores the title, author, and whether it is currently borrowed.
A Member stores a name and an ID.
A Transaction records when a book is borrowed or returned.

All of these are managed inside a Library class, which handles the logic of the application. It uses maps to store books and members, and a vector to keep the history of transactions.

The user interacts with everything through a menu that runs in a loop until the program is closed.
===== LIBRARY MENU =====
1 Add Book
2 Remove Book
3 List Books
4 Add Member
5 Remove Member
6 List Members
7 Borrow Book
8 Return Book
9 Books Report
10 Members Report
11 Transactions Report
0 Exit

Example Workflow:
Add a member
Add a book
Borrow the book
Return the book
Check transaction history

Author:

Tudor Rotaru -->