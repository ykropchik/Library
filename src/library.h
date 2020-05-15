//
// Created by YKROPCHIK on 02.05.2020.
//
#include <vector>
#include <string>
#include <set>

struct Book {
    std::string name;
    std::string author;
    bool stock;
    bool operator !=(const Book &book);
};

class Reader {
private:
    uint32_t id;
    std::vector<const Book*> books;

public:
    Reader(uint32_t id);
    void addBook(Book *book);
    void returnBook(Book *book);
    void printRange();
};

class Library {
private:
    std::vector<const Book*> books;

public:
    explicit Library (const std::vector<const Book*> &books);
    void addBook(const Book *bookLink);
    const Book* findBook(const std::string &author, const std::string &name);
    std::vector<const Book*> findBook(const std::string &desired, bool isName);
    void takeBook(Reader reader, Book *book);
    void returnBook(Reader reader, Book *book);
    void printRange();
};




