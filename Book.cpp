#include "Book.h"

Book::Book(const std::string& title, const std::string& author, const std::string& isbn)
    : title_(title), author_(author), isbn_(isbn), isAvailable_(true), borrowedBy_(nullptr) {}

std::string Book::getTitle() const { return title_; }
std::string Book::getAuthor() const { return author_; }
std::string Book::getIsbn() const { return isbn_; }
bool Book::isAvailable() const { return isAvailable_; }
Member* Book::getBorrowedBy() const { return borrowedBy_; }

void Book::setTitle(const std::string& title) { title_ = title; }
void Book::setAuthor(const std::string& author) { author_ = author; }
void Book::setIsbn(const std::string& isbn) { isbn_ = isbn; }
void Book::setAvailable(bool available) { isAvailable_ = available; }
void Book::setBorrowedBy(Member* member) { borrowedBy_ = member; }
