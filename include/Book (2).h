#ifndef BOOK_H
#define BOOK_H

#include <string>

class Member; // forward declaration for association

// Book models a single library item.
// Encapsulation: all attributes are private, accessed only via getters/setters.
class Book {
private:
    std::string title_;
    std::string author_;
    std::string isbn_;
    bool isAvailable_;
    Member* borrowedBy_; // association: which member currently holds this book (nullptr if none)

public:
    Book(const std::string& title, const std::string& author, const std::string& isbn);

    // Getters
    std::string getTitle() const;
    std::string getAuthor() const;
    std::string getIsbn() const;
    bool isAvailable() const;
    Member* getBorrowedBy() const;

    // Setters
    void setTitle(const std::string& title);
    void setAuthor(const std::string& author);
    void setIsbn(const std::string& isbn);
    void setAvailable(bool available);
    void setBorrowedBy(Member* member);
};

#endif // BOOK_H
