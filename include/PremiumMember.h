#ifndef PREMIUM_MEMBER_H
#define PREMIUM_MEMBER_H

#include "Member.h"

// PremiumMember: can borrow up to 5 books at a time.
class PremiumMember : public Member {
public:
    static const int MAX_BOOKS_PREMIUM = 5;

    PremiumMember(const std::string& name, const std::string& memberId);

    std::string getMembershipType() const override;
};

#endif // PREMIUM_MEMBER_H
