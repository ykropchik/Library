//
// Created by YKROPCHIK on 02.05.2020.
//
#include <iostream>
#include "library.h"

bool Book::operator !=(const Book &book) {
    return (this->author != book.author) || (this->name != book.name);

}

Reader::Reader (uint32_t id) {
    this->id = id;
    this->books = {};
}

void Reader::addBook(Book *book) {
    books.push_back(book);
}

void Reader::returnBook(Book *book) {
    for (int i = 0; i < books.size(); ++i) {
        if (books[i] == book) {
            books.erase(books.begin() + i);
            return;
        }
    }
}

void Reader::printRange() {
    for (int i = 0; i < books.size(); ++i) {
        std::cout << books[i]->author << " - "
                  << books[i]->name << std::endl;
    }

    std::cout << std::endl;
}


Library::Library(const std::vector<const Book*> &books) {
    this->books = books;
}

void Library::addBook(const Book *bookLink) {
    books.push_back(bookLink);
}

const Book* Library::findBook(const std::string &author, const std::string &name) {
    for (int i = 0; i < books.size(); ++i) {
        if ((books[i]->name == name) && (books[i]->author == author)) {
            return books[i];
        }
    }

    return nullptr;
}

std::vector<const Book*> Library::findBook(const std::string &desired, bool isName) {
    std::vector<const Book*> foundBook;
    if (isName){
        for (int i = 0; i < books.size(); ++i) {
            if (books[i]->name == desired) {
                foundBook.push_back(books[i]);
            }
        }
    } else {
        for (int i = 0; i < books.size(); ++i) {
            if (books[i]->author == desired) {
                foundBook.push_back(books[i]);
            }
        }
    }

    return foundBook;
}

void Library::takeBook(Reader reader, Book *book) {
    book->stock = false;
    reader.addBook(book);
}

void Library::returnBook(Reader reader, Book *book) {
    book->stock = true;
    reader.returnBook(book);
}

void Library::printRange(){
    for (int i = 0; i < books.size(); ++i) {
        std::cout << books[i]->author << " - "
        << books[i]->name << " - "
        << (books[i]->stock ? "(В наличии)" : "(Нет в наличии)") << std::endl;
    }

    std::cout << std::endl;
}
