#include "string.h"
using namespace std;

bool Mystring::operator==(const Mystring& other) const {
    return Equal(other);
}

bool Mystring::operator!=(const Mystring& other) const {
    return !Equal(other);
}
Mystring& Mystring::operator+=(const Mystring& str) {
    *this = *this + str;
    return *this;
}

Mystring& Mystring::operator+=(const char* str) {
    *this = *this + str;
    return *this;
}

Mystring::Mystring() : len(0), cap(1), Cs(new char[1]) {
    Cs[0] = '\0';
}

Mystring::Mystring(const char* p) {
    len = 0;
    while (p[len] != '\0') len++;
    cap = len + 1;
    Cs = new char[cap];
    for (int i = 0; i < len; i++) Cs[i] = p[i];
    Cs[len] = '\0';
}

Mystring::Mystring(int n, char c) {
    len = n;
    cap = len + 1;
    Cs = new char[cap];
    for (int i = 0; i < len; i++) Cs[i] = c;
    Cs[len] = '\0';
}


Mystring::Mystring(int num) {
    *this = InttoStr(num);
}

const char* Mystring::c_str() const {
    return Cs;
}

Mystring::Mystring(const Mystring& s) : len(s.len), cap(s.cap) {
    Cs = new char[cap];
    for (int i = 0; i <= len; i++) Cs[i] = s.Cs[i];
}

Mystring::~Mystring() {
    delete[] Cs;
}

Mystring& Mystring::operator=(const Mystring& s) {
    if (this != &s) {
        delete[] Cs;
        len = s.len;
        cap = s.cap;
        Cs = new char[cap];
        for (int i = 0; i <= len; i++) Cs[i] = s.Cs[i];
    }
    return *this;
}

Mystring Mystring::operator+(const Mystring& str2) const {
    int newLen = len + str2.len;
    char* temp = new char[newLen + 1];

    for (int i = 0; i < len; i++) {
        temp[i] = Cs[i];
    }
    for (int i = 0; i < str2.len; i++) {
        temp[len + i] = str2.Cs[i];
    }

    temp[newLen] = '\0';
    Mystring result(temp);
    delete[] temp;
    return result;
}

Mystring Mystring::operator+(const char* str2) const {
    int Len = 0;
    while (str2[Len] != '\0') Len++;

    int newLen = len + Len;
    char* temp = new char[newLen + 1];

    for (int i = 0; i < len; i++) {
        temp[i] = Cs[i];
    }
    for (int i = 0; i < Len; i++) {
        temp[len + i] = str2[i];
    }

    temp[newLen] = '\0';
    Mystring result(temp);
    delete[] temp;
    return result;
}


void Mystring::Print() const {
    cout << Cs;
}

int Mystring::Length() const {
    return len;
}

void Mystring::Clear() {
    delete[] Cs;
    len = 0;
    cap = 1;
    Cs = new char[cap];
    Cs[0] = '\0';
}

void Mystring::Replace_first(char c) {
    if (Cs) Cs[0] = c;
}

Mystring Mystring::Concat(const Mystring& s) const {
    Mystring result(len + s.len, '\0');
    for (int i = 0; i < len; i++) result.Cs[i] = Cs[i];
    for (int i = 0; i < s.len; i++) result.Cs[len + i] = s.Cs[i];
    result.Cs[len + s.len] = '\0';
    return result;
}

bool Mystring::Equal(const Mystring& s) const {
    if (len != s.len) {
        return false;
    }

    for (int i = 0; i < len; i++) {
        if (Cs[i] != s.Cs[i]) {
            return false;
        }
    }
    return true;
}

bool Mystring::Less(const Mystring& s) const {
    if (len < s.len) {
        return true;
    }
    else if (len > s.len) {
        return false;
    }
    else if (len == s.len) {
        for (int i = 0; i < len; i++) {
            if (Cs[i] < s.Cs[i]) return true;
            if (Cs[i] > s.Cs[i]) return false;
        }
    }
    return false;
}

bool Mystring::Greater(const Mystring& s) const {
    if (len > s.len) {
        return true;
    }
    else if (len < s.len) {
        return false;
    }
    else if (len == s.len) {
        for (int i = 0; i < len; i++) {
            if (Cs[i] > s.Cs[i]) return true;
            if (Cs[i] < s.Cs[i]) return false;
        }
    }
    return false;
}

int Mystring::StrtoInt() const {
    return atoi(Cs);
}

Mystring Mystring::InttoStr(int num) {
    char buffer[20];
    int i = 0, sign = num < 0 ? -1 : 1;
    if (num < 0) num = -num;
    do {
        buffer[i++] = (num % 10) + '0';
        num /= 10;
    } while (num);
    if (sign == -1) buffer[i++] = '-';
    buffer[i] = '\0';

    for (int j = 0, k = i - 1; j < k; j++, k--) {
        char temp = buffer[j];
        buffer[j] = buffer[k];
        buffer[k] = temp;
    }

    return Mystring(buffer);
}


Mystring& Mystring::Trim() {
    int start = 0;
    int end = len - 1;
    while (Cs[start] == ' ' || Cs[start] == '\t' || Cs[start] == '\n') {
        start++;
    }
    while (Cs[end] == ' ' || Cs[end] == '\t' || Cs[end] == '\n') {
        end--;
    }
    int newlen = end - start + 1;
    char* newcs = new char[newlen + 1];
    for (int i = 0; i < newlen; i++) {
        newcs[i] = Cs[start + i];
    }
    newcs[newlen] = '\0';

    delete[] Cs;
    Cs = newcs;
    this->len = newlen;

    return *this;
}

void Mystring::to_upper() {
    for (int i = 0; i < len; i++) if (Cs[i] >= 'a' && Cs[i] <= 'z') Cs[i] -= 32;
}

void Mystring::to_lower() {
    for (int i = 0; i < len; i++) if (Cs[i] >= 'A' && Cs[i] <= 'Z') Cs[i] += 32;
}

int Mystring::FindFirst(char ch) const {
    for (int i = 0; i < len; i++) if (Cs[i] == ch) return i;
    return -1;
}

int Mystring::FindLast(char ch) const {
    for (int i = len - 1; i >= 0; i--) if (Cs[i] == ch) return i;
    return -1;
}

int* Mystring::FindAll(char ch, int& count) const {
    count = 0;

    for (int i = 0; i < len; i++) {
        if (Cs[i] == ch) {
            count++;
        }
    }

    int* idx = new int[count];
    int j = 0;
    for (int i = 0; i < len; i++) {
        if (Cs[i] == ch) {
            idx[j++] = i;
        }
    }
    return idx;
}


void Mystring::RemoveAt(int i) {
    if (i < 0 || i >= len) {
        return;
    }
    for (int j = i; j < len - 1; j++) {
        Cs[j] = Cs[j + 1];
    }
    Cs[--len] = '\0';
}

void Mystring::InsertAt(int i, char ch) {
    if (i < 0 || i > len) return;
    char* temp = new char[len + 2];

    for (int j = 0; j < i; j++) {
        temp[j] = Cs[j];
    }

    temp[i] = ch;

    for (int j = i; j < len; j++) {
        temp[j + 1] = Cs[j];
    }
    temp[len + 1] = '\0';

    delete[] Cs;
    Cs = temp;
    len++;
    cap = len + 1;
}

void Mystring::Insert_At(int i, const Mystring& sub) {
    if (i < 0 || i > len) return;
    int newlen = len + sub.len;
    char* temp = new char[newlen + 1];

    for (int j = 0; j < i; j++) {
        temp[j] = Cs[j];
    }

    for (int j = 0; j < sub.len; j++) {
        temp[i + j] = sub.Cs[j];
    }

    for (int j = i; j < len; j++) {
        temp[i + sub.len + j - i] = Cs[j];
    }
    temp[newlen] = '\0';

    delete[] Cs;
    Cs = temp;
    len = newlen;
    cap = len + 1;
}

void Mystring::Remove_First(char ch) {
    int idx = FindFirst(ch);
    if (idx != -1) {
        RemoveAt(idx);
    }
}

void Mystring::Remove_Last(char ch) {
    int idx = FindLast(ch);
    if (idx != -1) {
        RemoveAt(idx);
    }
}

void Mystring::Remove_All(char ch) {
    int i = 0;
    while (i < len) {
        if (Cs[i] == ch) {
            RemoveAt(i);
        }
        else {
            i++;
        }
    }
}

int Mystring::Find_First(const Mystring& sub) const {
    for (int i = 0; i <= len - sub.len; i++) {
        bool found = true;
        for (int j = 0; j < sub.len; j++) {
            if (Cs[i + j] != sub.Cs[j]) {
                found = false;
                break;
            }
        }
        if (found) {
            return i;
        }
    }
    return -1;
}

int Mystring::Find_Last(const Mystring& sub) const {
    for (int i = len - sub.len; i >= 0; i--) {
        bool found = true;
        for (int j = 0; j < sub.len; j++) {
            if (Cs[i + j] != sub.Cs[j]) {
                found = false;
                break;
            }
        }
        if (found) {
            return i;
        }
    }
    return -1;
}

char Mystring::operator[](int i) const {
    if (i >= 0 && i < len) {
        return Cs[i];
    }
    return '\0';
}

char& Mystring::operator[](int i) {
    return Cs[i];
}

int* Mystring::AllSubStr(const char* substr, int& count) const {
    count = 0;
    int sublen = 0;
    while (substr[sublen] != '\0') {
        sublen++;
    }

    for (int i = 0; i <= len - sublen; i++) {
        bool match = true;
        for (int j = 0; j < sublen; j++) {
            if (Cs[i + j] != substr[j]) {
                match = false;
                break;
            }
        }
        if (match) {
            count++;
        }
    }

    int* indices = new int[count];
    int idx = 0;
    for (int i = 0; i <= len - sublen; i++) {
        bool match = true;
        for (int j = 0; j < sublen; j++) {
            if (Cs[i + j] != substr[j]) {
                match = false;
                break;
            }
        }
        if (match) {
            indices[idx++] = i;
        }
    }
    return indices;
}


int* Mystring::Find_All(const Mystring& sub, int& count) const {
    count = 0;
    for (int i = 0; i <= len - sub.len; i++) {
        bool found = true;
        for (int j = 0; j < sub.len; j++) {
            if (Cs[i + j] != sub.Cs[j]) {
                found = false;
                break;
            }
        }
        if (found) {
            count++;
        }
    }

    if (count == 0) {
        return nullptr;
    }

    int* indices = new int[count];
    int idx = 0;
    for (int i = 0; i <= len - sub.len; i++) {
        bool found = true;
        for (int j = 0; j < sub.len; j++) {
            if (Cs[i + j] != sub.Cs[j]) {
                found = false;
                break;
            }
        }
        if (found) {
            indices[idx++] = i;
        }
    }
    return indices;
}

Mystring* Mystring::Split(char delim, int& count) const {
    count = 1;

    for (int i = 0; i < len; i++) {
        if (Cs[i] == delim) {
            count++;
        }
    }

    Mystring* result = new Mystring[count];
    int start = 0;
    int idx = 0;

    for (int i = 0; i <= len; i++) {
        if (Cs[i] == delim || Cs[i] == '\0') {
            int sublen = i - start;
            char* temp = new char[sublen + 1];

            for (int j = 0; j < sublen; j++) {
                temp[j] = Cs[start + j];
            }
            temp[sublen] = '\0';

            result[idx] = Mystring(temp);
            delete[] temp;
            start = i + 1;
            idx++;
        }
    }
    return result;
}

void Mystring::input() {
    char buffer[256];
    cin.ignore();
    cin.getline(buffer, 256);
    *this = buffer;
}

Mystring* Mystring::Tokenize(const char* delim, int& count) const {
    count = 1;

    for (int i = 0; i < len; i++) {
        for (int j = 0; delim[j] != '\0'; j++) {
            if (Cs[i] == delim[j]) {
                count++;
                break;
            }
        }
    }

    Mystring* result = new Mystring[count];
    int start = 0;
    int idx = 0;

    for (int i = 0; i <= len; i++) {
        bool found = false;
        for (int j = 0; delim[j] != '\0'; j++) {
            if (Cs[i] == delim[j] || Cs[i] == '\0') {
                found = true;
                break;
            }
        }

        if (found) {
            int sublen = i - start;
            if (sublen > 0) {
                char* temp = new char[sublen + 1];
                for (int j = 0; j < sublen; j++) {
                    temp[j] = Cs[start + j];
                }
                temp[sublen] = '\0';
                result[idx] = Mystring(temp);
                delete[] temp;
            }
            start = i + 1;
            idx++;
        }
    }

    return result;
}

ostream& operator<<(ostream& os, const Mystring& str) {
    os << str.c_str();
    return os;
}

istream& operator>>(istream& is, Mystring& str) {
    char buffer[1024];
    is >> buffer;
    str = buffer;
    return is;
}

inline Mystring operator+(const char* lhs, const Mystring& rhs) {
    return Mystring(lhs) + rhs;
}
