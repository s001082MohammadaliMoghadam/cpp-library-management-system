#ifndef ABSTRACT_LIBRARY_H
#define ABSTRACT_LIBRARY_H

#include <string>

class Book;
class Member;

// AbstractLibrary defines the general concept of "a library" (abstraction).
// It has no data of its own; concrete libraries decide HOW to store books
// and members and HOW borrowing/returning is carried out.
class AbstractLibrary {
public:
    virtual ~AbstractLibrary() = default;

    virtual void addBook(const Book& book) = 0;
    virtual bool borrowBook(const std::string& isbn, Member& member) = 0;
    virtual bool returnBook(const std::string& isbn, Member& member) = 0;
};

#endif // ABSTRACT_LIBRARY_H
