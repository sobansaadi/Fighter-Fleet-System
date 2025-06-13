#ifndef USER_H
#define USER_H

#include "string.h"
using namespace std;

class User {
private:
    Mystring username;
    Mystring password;
    Mystring role;

public:
    User();
    User(const Mystring& user, const Mystring& pass, const Mystring& role);
    Mystring getUsername() const;
    Mystring getPassword() const;
    bool authenticate(const Mystring& input) const;
    Mystring getRole() const;
};

#endif