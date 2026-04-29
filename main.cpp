#include <iostream>
#include <map>
#include <vector>
#include <string>

using namespace std;

class Book
{
public:
    string title;
    string author;
    bool borrowed;

    Book() : borrowed(false) {}

    Book(string t, string a) : title(t), author(a), borrowed(false) {}
};

class Member
{
public:
    string name;
    string id;

    Member() {}

    Member(string n, string i) : name(n), id(i) {}
};

class Transaction
{
public:
    string member;
    string book;
    string type;

    Transaction(string m, string b, string t) : member(m), book(b), type(t) {}
};

class Library
{
private:
    map<string, Book> books;
    map<string, Member> members;
    vector<Transaction> history;

public:
    void addBook()
    {
        string title, author;

        cout << "Title: ";
        getline(cin, title);

        cout << "Author: ";
        getline(cin, author);

        if (books.count(title))
        {
            cout << "Book already exists" << endl;
            return;
        }

        books[title] = Book(title, author);
        cout << "Book added " << endl;
    }

    void removeBook()
    {
        string title;

        cout << "Title: ";
        getline(cin, title);

        if (books.count(title))
        {
            books.erase(title);
            return;
        }
        else
        {
            cout << "Book doesn't exist" << endl;
        }
    }

    void listBooks() const
    {
        cout << endl
             << "Books:" << endl;

        for (const auto &b : books)
        {
            cout << b.second.title << " - " << b.second.author;
            if (b.second.borrowed)
                cout << " (borrowed)";
            cout << endl;
        }
    }

    void booksReport() const
    {
        int borrowedCount = 0;

        for (const auto &b : books)
        {
            if (b.second.borrowed)
                borrowedCount++;
        }

        cout << endl
             << "Total books: " << books.size() << endl;
        cout << "Borrowed books: " << borrowedCount << endl;
    }

    void addMember()
    {
        string name, id;

        cout << "Name: ";
        getline(cin, name);

        cout << "ID: ";
        getline(cin, id);

        for (const auto &m : members)
        {
            if (m.second.id == id)
            {
                cout << "There is already a member with this ID" << endl;
                return;
            }
        }
        members[name] = Member(name, id);
        cout << "Member added" << endl;
    }

    void removeMember()
    {
        string name;

        cout << "Name: ";
        getline(cin, name);

        members.erase(name);
    }

    void listMembers() const
    {
        cout << endl
             << "Members:" << endl;

        for (const auto &m : members)
        {
            cout << m.second.name << " - " << m.second.id << endl;
        }
    }

    void membersReport() const
    {
        cout << endl
             << "Total members: " << members.size() << endl;
    }

    void borrowBook()
    {
        cout << "Before borowing the book make sure that the member is added to the list!" << endl;
        string memberName, bookTitle;

        cout << "Member name: ";
        getline(cin, memberName);

        cout << "Book title: ";
        getline(cin, bookTitle);

        if (!members.count(memberName))
        {
            cout << "Member not found" << endl;
            cout << "Before borowing the book make sure that the member is added to the list!" << endl;
            return;
        }

        if (!books.count(bookTitle))
        {
            cout << "Book not found" << endl;
            return;
        }

        if (books[bookTitle].borrowed)
        {
            cout << "Book already borrowed" << endl;
            return;
        }

        books[bookTitle].borrowed = true;
        history.push_back(Transaction(memberName, bookTitle, "borrowed"));
        cout << "Book borrowed successfully" << endl;
    }

    void returnBook()
    {
        string memberName, bookTitle;

        cout << "Member name: ";
        getline(cin, memberName);

        cout << "Book title: ";
        getline(cin, bookTitle);

        if (!books.count(bookTitle))
        {
            cout << "Book not found" << endl;
            return;
        }

        books[bookTitle].borrowed = false;
        history.push_back(Transaction(memberName, bookTitle, "returned"));
        cout << "Book returned" << endl;
    }

    void transactionsReport() const
    {
        cout << endl
             << "Transaction history:" << endl;

        for (const auto &t : history)
        {
            cout << t.member << " " << t.type << " " << t.book << endl;
        }
    }

    void menu()
    {
        int op;

        while (true)
        {
            cout << endl
                 << "===== LIBRARY MENU =====" << endl;
            cout << "1 Add Book" << endl;
            cout << "2 Remove Book" << endl;
            cout << "3 List Books" << endl;
            cout << "4 Add Member" << endl;
            cout << "5 Remove Member" << endl;
            cout << "6 List Members" << endl;
            cout << "7 Borrow Book" << endl;
            cout << "8 Return Book" << endl;
            cout << "9 Books Report" << endl;
            cout << "10 Members Report" << endl;
            cout << "11 Transactions Report" << endl;
            cout << "0 Exit" << endl;
            cout << "Option: ";

            cin >> op;
            cin.ignore();

            switch (op)
            {
            case 1:
                addBook();
                break;
            case 2:
                removeBook();
                break;
            case 3:
                listBooks();
                break;
            case 4:
                addMember();
                break;
            case 5:
                removeMember();
                break;
            case 6:
                listMembers();
                break;
            case 7:
                borrowBook();
                break;
            case 8:
                returnBook();
                break;
            case 9:
                booksReport();
                break;
            case 10:
                membersReport();
                break;
            case 11:
                transactionsReport();
                break;
            case 0:
                return;
            default:
                cout << "Invalid option" << endl;
                ;
            }
        }
    }
};

int main()
{
    Library library;
    library.menu();
    return 0;
}