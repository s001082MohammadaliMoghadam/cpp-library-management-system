#include "BookRepository.h"
#include <algorithm>

void BookRepository::addBook(const Book& book) {
    books_.push_back(book);
}

Book* BookRepository::findByIsbn(const std::string& isbn) {
    auto it = std::find_if(books_.begin(), books_.end(),
                            [&isbn](const Book& b) { return b.getIsbn() == isbn; });
    if (it == books_.end()) {
        return nullptr;
    }
    return &(*it);
}

const std::vector<Book>& BookRepository::getAllBooks() const {
    return books_;
}

std::size_t BookRepository::size() const {
    return books_.size();
}
