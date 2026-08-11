#include <iostream>
#include "Book.h"
#include "RegularMember.h"
#include "PremiumMember.h"
#include "MyLibrary.h"

int main() {
    MyLibrary library;

    library.addBook(Book("Clean Code", "Robert C. Martin", "ISBN-001"));
    library.addBook(Book("The Pragmatic Programmer", "Andrew Hunt", "ISBN-002"));
    library.addBook(Book("Effective C++", "Scott Meyers", "ISBN-003"));
    library.addBook(Book("Design Patterns", "Erich Gamma", "ISBN-004"));
    library.addBook(Book("Introduction to Algorithms", "Thomas Cormen", "ISBN-005"));
    library.addBook(Book("Database System Concepts", "Abraham Silberschatz", "ISBN-006"));

    RegularMember alice("Alice", "M-001");
    PremiumMember bob("Bob", "M-002");

    library.registerMember(&alice);
    library.registerMember(&bob);

    library.printCatalog();

    std::cout << "\n--- Borrowing books ---\n";
    library.borrowBook("ISBN-001", alice);
    library.borrowBook("ISBN-002", alice);
    library.borrowBook("ISBN-003", alice);
    library.borrowBook("ISBN-004", alice); // should fail: regular limit is 3

    library.borrowBook("ISBN-001", bob);   // should fail: already borrowed by Alice
    library.borrowBook("ISBN-004", bob);
    library.borrowBook("ISBN-005", bob);
    library.borrowBook("ISBN-006", bob);

    library.printCatalog();

    std::cout << "\n--- Returning a book ---\n";
    library.returnBook("ISBN-001", alice);
    library.borrowBook("ISBN-004", alice); // should fail: still borrowed by Bob

    library.printCatalog();

    return 0;
}
