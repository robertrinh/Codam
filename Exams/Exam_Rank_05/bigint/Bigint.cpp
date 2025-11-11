#include "Bigint.hpp"
#include <algorithm>

//* MEMORY TIP: digits stored REVERSED (1337 → "7331")
//* This makes addition natural (left-to-right) and shifts trivial

void Bigint::_trim() {
    while (_digits.size() > 1 && _digits.back() == '0')
        _digits.pop_back();
}

Bigint::Bigint() : _digits("0") {}

Bigint::Bigint(int n) {
    if (n == 0) {
        _digits = "0";
        return;
    }
    while (n > 0) {
        _digits += (n % 10) + '0';
        n /= 10;
    }
}

Bigint Bigint::operator+(const Bigint& other) const {
    Bigint result;
    result._digits.clear();
    
    int carry = 0;
    size_t i = 0;
    
    while (i < _digits.size() || i < other._digits.size() || carry) {
        int sum = carry;
        if (i < _digits.size())
            sum += _digits[i] - '0';
        if (i < other._digits.size())
            sum += other._digits[i] - '0';
        
        result._digits += (sum % 10) + '0';
        carry = sum / 10;
        i++;
    }
    
    result._trim();
    return result;
}

Bigint& Bigint::operator+=(const Bigint& other) {
    *this = *this + other;
    return *this;
}

Bigint& Bigint::operator++() {
    *this += Bigint(1);
    return *this;
}

Bigint Bigint::operator++(int) {
    Bigint temp = *this;
    ++(*this);
    return temp;
}

Bigint Bigint::operator<<(int shift) const {
    if (_digits == "0")
        return *this;
    
    Bigint result = *this;
    //* shift left = multiply by 10 = add zeros at FRONT (but reversed)
    for (int i = 0; i < shift; i++)
        result._digits.insert(0, 1, '0');  //* insert at beginning
    
    return result;
}

Bigint& Bigint::operator<<=(int shift) {
    *this = *this << shift;
    return *this;
}

Bigint Bigint::operator>>(int shift) const {
    Bigint result = *this;
    
    //* shift right = divide by 10 = remove from FRONT (but reversed!)
    if (shift >= (int)result._digits.size()) {
        result._digits = "0";
    } else {
        result._digits.erase(0, shift);  //* remove from beginning
    }
    
    result._trim();
    return result;
}

Bigint& Bigint::operator>>=(int shift) {
    *this = *this >> shift;
    return *this;
}

bool Bigint::operator==(const Bigint& other) const {
    return _digits == other._digits;
}

bool Bigint::operator!=(const Bigint& other) const {
    return !(*this == other);
}

bool Bigint::operator<(const Bigint& other) const {
    //* different lengths: shorter is smaller
    if (_digits.size() != other._digits.size())
        return _digits.size() < other._digits.size();
    
    //* same length: compare from back (most significant digit)
    for (int i = _digits.size() - 1; i >= 0; i--) {
        if (_digits[i] != other._digits[i])
            return _digits[i] < other._digits[i];
    }
    return false;  //* equal
}

bool Bigint::operator>(const Bigint& other) const {
    return other < *this;
}

bool Bigint::operator<=(const Bigint& other) const {
    return !(other < *this);
}

bool Bigint::operator>=(const Bigint& other) const {
    return !(*this < other);
}

std::ostream& operator<<(std::ostream& os, const Bigint& b) {
    //* print reversed (most significant first)
    for (int i = b._digits.size() - 1; i >= 0; i--)
        os << b._digits[i];
    return os;
}
