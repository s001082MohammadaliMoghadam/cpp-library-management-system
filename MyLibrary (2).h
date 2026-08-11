#ifndef MY_LIBRARY_H
#define MY_LIBRARY_H

#include <vector>
#include <string>
#include "AbstractLibrary.h"
#include "BookRepository.h"
#include "Member.h"

// MyLibrary is the concrete, tangible library.
// Composition: MyLibrary owns a BookRepository (built and destroyed with it).
// Association: MyLibrary keeps loose references (pointers) to Member objects
//              that are created and owned elsewhere (e.g. in main()); members
//              can exist and move between libraries independently.
class MyLibrary : public AbstractLibrary {
private:
    BookRepository bookRepository_;      // composition
    std::vector<Member*> registeredMembers_; // association

public:
    void registerMember(Member* member);

    void addBook(const Book& book) override;
    bool borrowBook(const std::string& isbn, Member& member) override;
    bool returnBook(const std::string& isbn, Member& member) override;

    void printCatalog() const;
    std::size_t getBookCount() const;
};

#endif // MY_LIBRARY_H
