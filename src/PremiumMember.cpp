#include "PremiumMember.h"

PremiumMember::PremiumMember(const std::string& name, const std::string& memberId)
    : Member(name, memberId, MAX_BOOKS_PREMIUM) {}

std::string PremiumMember::getMembershipType() const {
    return "Premium";
}
