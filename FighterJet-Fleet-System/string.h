#ifndef STRING_H
#define STRING_H

#include <iostream>

using namespace std;

class Mystring {
private:
    int len;
    int cap;
    char* Cs;

public:
    Mystring();
    Mystring(const char* p);
    Mystring(int n, char c);
    Mystring(int num);
    Mystring(const Mystring& s);
    ~Mystring();

    bool operator==(const Mystring& other) const;
    bool operator!=(const Mystring& other) const;
    Mystring& operator+=(const Mystring& str);
    Mystring& operator+=(const char* str);
    Mystring& operator=(const Mystring& s);
    char operator[](int i) const;
    char& operator[](int i);
    Mystring operator+(const Mystring& str2) const;
    Mystring operator+(const char* str2) const;
    void Print() const;
    int Length() const;
    void Clear();
    void Replace_first(char c);
    Mystring Concat(const Mystring& s) const;

    int StrtoInt() const;
    static Mystring InttoStr(int num);
    Mystring& Trim();
    bool Equal(const Mystring& s) const;
    bool Less(const Mystring& s) const;
    bool Greater(const Mystring& s) const;

    int FindFirst(char ch) const;
    int FindLast(char ch) const;
    int* FindAll(char ch, int& count) const;
    int Find_First(const Mystring& sub) const;
    int Find_Last(const Mystring& sub) const;
    int* Find_All(const Mystring& sub, int& count) const;
    int* AllSubStr(const char* substr, int& count) const;

    void RemoveAt(int i);
    void InsertAt(int i, char ch);
    void Insert_At(int i, const Mystring& sub);
    void Remove_First(char ch);
    void Remove_Last(char ch);
    void Remove_All(char ch);

    void to_upper();
    void to_lower();

    Mystring* Split(char delim, int& count) const;
    Mystring* Tokenize(const char* delim, int& count) const;

    const char* c_str() const;
    void input();

    friend ostream& operator<<(ostream& os, const Mystring& str);
    friend istream& operator>>(istream& is, Mystring& str);
    friend Mystring operator+(const char* lhs, const Mystring& rhs);
    friend istream& getline(istream& is, Mystring& str);
};
inline istream& getline(istream& is, Mystring& str) {
    char buffer[1024];
    is.getline(buffer, 1024);
    str = buffer;
    return is;
}

#endif