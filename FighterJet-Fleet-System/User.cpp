#include "User.h"
#include <iostream>
using namespace std;

User::User() : username(""), password(""), role("") {}

User::User(const Mystring& user, const Mystring& pass, const Mystring& role) : username(user), password(pass), role(role) {}

Mystring User::getUsername() const {
    return username;
}

Mystring User::getPassword() const {
    return password;
}

bool User::authenticate(const Mystring& input) const {
    return password == input;
}

Mystring User::getRole() const {
    return role;
}