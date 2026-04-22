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

int main()
{
    map<string, Book> books;
    map<string, Member> members;
    vector<Transaction> history;

    books["Matilda"] = Book("Matilda", "Roald Dahl");
    members["Ion"] = Member("Ion", "Popescu");

    if (members.count("Ion") && books.count("Matilda"))
    {
        books["Matilda"].borrowed = true;
        history.push_back(Transaction("Ion", "Matilda", "borrowed"));
    }

    cout << "Books:\n";
    for (const auto &b : books)
    {
        cout << b.second.title << " - " << b.second.author;
        if (b.second.borrowed)
            cout << " (borrowed)";
        cout << "\n";
    }

    cout << "\nMembers:\n";
    for (const auto &m : members)
    {
        cout << m.second.name << " - " << m.second.id << "\n";
    }

    cout << "\nTransactions:\n";
    for (const auto &t : history)
    {
        cout << t.member << " " << t.type << " " << t.book << "\n";
    }

    return 0;
}