#ifndef REGULAR_MEMBER_H
#define REGULAR_MEMBER_H

#include "Member.h"

// RegularMember: can borrow up to 3 books at a time.
class RegularMember : public Member {
public:
    static const int MAX_BOOKS_REGULAR = 3;

    RegularMember(const std::string& name, const std::string& memberId);

    std::string getMembershipType() const override;
};

#endif // REGULAR_MEMBER_H
