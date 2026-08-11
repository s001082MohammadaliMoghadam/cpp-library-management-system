#ifndef BOOK_REPOSITORY_H
#define BOOK_REPOSITORY_H

#include <vector>
#include <string>
#include "Book.h"

// BookRepository wraps a standard container (std::vector<Book>) and
// delegates storage/lookup to it. MyLibrary owns a BookRepository by
// composition: the repository has no meaning or lifetime outside the library.
class BookRepository {
private:
    std::vector<Book> books_;

public:
    void addBook(const Book& book);
    Book* findByIsbn(const std::string& isbn);
    const std::vector<Book>& getAllBooks() const;
    std::size_t size() const;
};

#endif // BOOK_REPOSITORY_H
