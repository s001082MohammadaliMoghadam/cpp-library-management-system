#include "RegularMember.h"

RegularMember::RegularMember(const std::string& name, const std::string& memberId)
    : Member(name, memberId, MAX_BOOKS_REGULAR) {}

std::string RegularMember::getMembershipType() const {
    return "Regular";
}
