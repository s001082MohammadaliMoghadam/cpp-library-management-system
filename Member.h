#ifndef MEMBER_H
#define MEMBER_H

#include <string>
#include <vector>

class Book; // forward declaration for association

// Member is the base class of the inheritance hierarchy.
// It stores identity data and the books currently borrowed by this member.
class Member {
protected:
    std::string name_;
    std::string memberId_;
    int maxBooksAllowed_;
    std::vector<Book*> borrowedBooks_; // association: books currently held by this member

public:
    Member(const std::string& name, const std::string& memberId, int maxBooksAllowed);
    virtual ~Member() = default;

    // Getters
    std::string getName() const;
    std::string getMemberId() const;
    int getMaxBooksAllowed() const;
    const std::vector<Book*>& getBorrowedBooks() const;

    // Behaviour
    bool canBorrowMore() const;
    virtual bool borrowBook(Book* book);   // adds book to this member's list if allowed
    virtual bool returnBook(Book* book);   // removes book from this member's list

    // Polymorphic hook so each member type can describe its own borrowing policy.
    virtual std::string getMembershipType() const = 0;
};

#endif // MEMBER_H
