#include <iostream>
#include <map>
#include <vector>
#include <string>

class Book
{
public:
    std::map<std::string, std::string> books;

    void addBook(std::string t, std::string a)
    {
        books[t] = a;
    }

    bool exists(std::string t)
    {
        return books.count(t);
    }

    void list()
    {
        for (auto &b : books)
            std::cout << b.first << " " << b.second << "\n";
    }

    void report()
    {
        std::cout << "Total books: " << books.size() << "\n";
    }
};

class Member
{
public:
    std::map<std::string, std::string> members;

    void addMember(std::string n, std::string id)
    {
        members[n] = id;
    }

    bool exists(std::string n)
    {
        return members.count(n);
    }

    void list()
    {
        for (auto &m : members)
            std::cout << m.first << " " << m.second << "\n";
    }

    void report()
    {
        std::cout << "Total members: " << members.size() << "\n";
    }
};

class Transaction
{

    std::vector<std::string> history;

public:
    void borrow(Member &m, Book &b, std::string mem, std::string book)
    {

        if (!m.exists(mem) || !b.exists(book))
        {
            std::cout << "invalid\n";
            return;
        }

        history.push_back(mem + " borrowed " + book);
    }

    void returnBook(std::string mem, std::string book)
    {
        history.push_back(mem + " returned " + book);
    }

    void list()
    {
        for (auto &t : history)
            std::cout << t << "\n";
    }
};

int main()
{

    Book books;
    Member members;
    Transaction t;

    books.addBook("Matilda", "Roald Dahl");
    members.addMember("Ion", "Popescu");

    t.borrow(members, books, "Ion", "Matilda");

    books.report();
    members.report();
    t.list();
}