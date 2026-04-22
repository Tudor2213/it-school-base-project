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
    void addBook(string title, string author)
    {
        books[title] = Book(title, author);
    }

    void addMember(string name, string id)
    {
        members[name] = Member(name, id);
    }

    void borrowBook(string memberName, string bookTitle)
    {
        if (!members.count(memberName))
        {
            cout << "Member not found\n";
            return;
        }

        if (!books.count(bookTitle))
        {
            cout << "Book not found\n";
            return;
        }

        if (books[bookTitle].borrowed)
        {
            cout << "Book already borrowed\n";
            return;
        }

        books[bookTitle].borrowed = true;
        history.push_back(Transaction(memberName, bookTitle, "borrowed"));
    }

    void returnBook(string memberName, string bookTitle)
    {
        if (!books.count(bookTitle))
        {
            cout << "Book not found\n";
            return;
        }

        books[bookTitle].borrowed = false;
        history.push_back(Transaction(memberName, bookTitle, "returned"));
    }

    void listBooks() const
    {
        cout << "\nBooks:\n";
        for (const auto &b : books)
        {
            cout << b.second.title << " - " << b.second.author;
            if (b.second.borrowed)
                cout << " (borrowed)";
            cout << "\n";
        }
    }

    void listMembers() const
    {
        cout << "\nMembers:\n";
        for (const auto &m : members)
        {
            cout << m.second.name << " - " << m.second.id << "\n";
        }
    }

    void transactionsReport() const
    {
        cout << "\nTransactions:\n";
        for (const auto &t : history)
        {
            cout << t.member << " " << t.type << " " << t.book << "\n";
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

        cout << "\nTotal books: " << books.size() << "\n";
        cout << "Borrowed books: " << borrowedCount << "\n";
    }

    void membersReport() const
    {
        cout << "\nTotal members: " << members.size() << "\n";
    }
};

int main()
{
    Library library;

    library.addBook("Matilda", "Roald Dahl");
    library.addBook("1984", "George Orwell");

    library.addMember("Ion", "Popescu");
    library.addMember("Ana", "Ionescu");

    library.borrowBook("Ion", "Matilda");

    library.listBooks();
    library.listMembers();
    library.booksReport();
    library.membersReport();
    library.transactionsReport();

    return 0;
}