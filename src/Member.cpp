#include "Member.h"
#include "Book.h"
#include <algorithm>

Member::Member(const std::string& name, const std::string& memberId, int maxBooksAllowed)
    : name_(name), memberId_(memberId), maxBooksAllowed_(maxBooksAllowed) {}

std::string Member::getName() const { return name_; }
std::string Member::getMemberId() const { return memberId_; }
int Member::getMaxBooksAllowed() const { return maxBooksAllowed_; }
const std::vector<Book*>& Member::getBorrowedBooks() const { return borrowedBooks_; }

bool Member::canBorrowMore() const {
    return static_cast<int>(borrowedBooks_.size()) < maxBooksAllowed_;
}

bool Member::borrowBook(Book* book) {
    if (!canBorrowMore() || book == nullptr) {
        return false;
    }
    borrowedBooks_.push_back(book);
    return true;
}

bool Member::returnBook(Book* book) {
    auto it = std::find(borrowedBooks_.begin(), borrowedBooks_.end(), book);
    if (it == borrowedBooks_.end()) {
        return false;
    }
    borrowedBooks_.erase(it);
    return true;
}
