#include "MyLibrary.h"
#include <iostream>

void MyLibrary::registerMember(Member* member) {
    if (member != nullptr) {
        registeredMembers_.push_back(member);
    }
}

void MyLibrary::addBook(const Book& book) {
    bookRepository_.addBook(book);
}

bool MyLibrary::borrowBook(const std::string& isbn, Member& member) {
    Book* book = bookRepository_.findByIsbn(isbn);
    if (book == nullptr) {
        std::cout << "Book with ISBN " << isbn << " not found.\n";
        return false;
    }
    if (!book->isAvailable()) {
        std::cout << "Book \"" << book->getTitle() << "\" is currently unavailable.\n";
        return false;
    }
    if (!member.canBorrowMore()) {
        std::cout << member.getName() << " has reached the borrowing limit ("
                   << member.getMaxBooksAllowed() << ") for a "
                   << member.getMembershipType() << " member.\n";
        return false;
    }

    member.borrowBook(book);
    book->setAvailable(false);
    book->setBorrowedBy(&member);

    std::cout << member.getName() << " successfully borrowed \"" << book->getTitle() << "\".\n";
    return true;
}

bool MyLibrary::returnBook(const std::string& isbn, Member& member) {
    Book* book = bookRepository_.findByIsbn(isbn);
    if (book == nullptr) {
        std::cout << "Book with ISBN " << isbn << " not found.\n";
        return false;
    }
    if (book->getBorrowedBy() != &member) {
        std::cout << member.getName() << " did not borrow \"" << book->getTitle() << "\".\n";
        return false;
    }

    member.returnBook(book);
    book->setAvailable(true);
    book->setBorrowedBy(nullptr);

    std::cout << member.getName() << " returned \"" << book->getTitle() << "\".\n";
    return true;
}

void MyLibrary::printCatalog() const {
    std::cout << "\n--- Library Catalog (" << bookRepository_.size() << " books) ---\n";
    for (const Book& book : bookRepository_.getAllBooks()) {
        std::cout << "  \"" << book.getTitle() << "\" by " << book.getAuthor()
                  << " [ISBN " << book.getIsbn() << "] - "
                  << (book.isAvailable() ? "available" : "borrowed") << "\n";
    }
}

std::size_t MyLibrary::getBookCount() const {
    return bookRepository_.size();
}
