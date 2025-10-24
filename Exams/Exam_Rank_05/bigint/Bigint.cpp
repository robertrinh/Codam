#include "Bigint.hpp"
#include <algorithm>

// MEMORY TIP: digits stored REVERSED (1337 → "7331")
// This makes addition natural (left-to-right) and shifts trivial

void Bigint::removeLeadingZeros() {
    while (digits.size() > 1 && digits.back() == '0') {
        digits.pop_back();
    }
}

Bigint::Bigint() : digits("0") {}

Bigint::Bigint(int n) {
    if (n == 0) {
        digits = "0";
        return;
    }
    
    while (n > 0) {
        digits += (n % 10) + '0';  // Add digit to end (reverse order)
        n /= 10;
    }
}

Bigint::Bigint(const std::string& s) {
    // Reverse the input string
    digits = s;
    std::reverse(digits.begin(), digits.end());
    removeLeadingZeros();
}

// Addition
Bigint Bigint::operator+(const Bigint& other) const {
    Bigint result;
    result.digits.clear();
    
    int carry = 0;
    size_t maxLen = std::max(digits.size(), other.digits.size());
    
    for (size_t i = 0; i < maxLen || carry; i++) {
        int sum = carry;
        if (i < digits.size()) sum += digits[i] - '0';
        if (i < other.digits.size()) sum += other.digits[i] - '0';
        
        result.digits += (sum % 10) + '0';
        carry = sum / 10;
    }
    
    result.removeLeadingZeros();
    return result;
}

// Addition assignment
Bigint& Bigint::operator+=(const Bigint& other) {
    *this = *this + other;
    return *this;
}

// Subtraction (simplified - assumes this >= other)
Bigint Bigint::operator-(const Bigint& other) const {
    Bigint result;
    result.digits.clear();
    
    int borrow = 0;
    for (size_t i = 0; i < digits.size(); i++) {
        int diff = (digits[i] - '0') - borrow;
        if (i < other.digits.size()) diff -= (other.digits[i] - '0');
        
        if (diff < 0) {
            diff += 10;
            borrow = 1;
        } else {
            borrow = 0;
        }
        
        result.digits += diff + '0';
    }
    
    result.removeLeadingZeros();
    return result;
}

// Prefix increment: ++a
Bigint& Bigint::operator++() {
    *this += Bigint(1);
    return *this;
}

// Postfix increment: a++
Bigint Bigint::operator++(int) {
    Bigint temp = *this;
    ++(*this);
    return temp;
}

// Left shift: multiply by 10^shift (add zeros to the left in reverse storage)
Bigint Bigint::operator<<(int shift) const {
    if (digits == "0") return *this;
    
    Bigint result = *this;
    for (int i = 0; i < shift; i++) {
        result.digits.insert(result.digits.begin(), '0');
    }
    return result;
}

Bigint& Bigint::operator<<=(int shift) {
    *this = *this << shift;
    return *this;
}

// Right shift: divide by 10^shift (remove digits from the left in reverse storage)
Bigint Bigint::operator>>(int shift) const {
    Bigint result = *this;
    
    if (shift >= (int)result.digits.size()) {
        result.digits = "0";
    } else {
        result.digits.erase(result.digits.begin(), result.digits.begin() + shift);
    }
    
    result.removeLeadingZeros();
    return result;
}

Bigint& Bigint::operator>>=(int shift) {
    *this = *this >> shift;
    return *this;
}

// Equality
bool Bigint::operator==(const Bigint& other) const {
    return digits == other.digits;
}

bool Bigint::operator!=(const Bigint& other) const {
    return !(*this == other);
}

// Less than
bool Bigint::operator<(const Bigint& other) const {
    if (digits.size() != other.digits.size()) {
        return digits.size() < other.digits.size();
    }
    
    // Compare from most significant digit (end of string in reverse storage)
    for (int i = digits.size() - 1; i >= 0; i--) {
        if (digits[i] != other.digits[i]) {
            return digits[i] < other.digits[i];
        }
    }
    return false;  // Equal
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

// Output operator
std::ostream& operator<<(std::ostream& os, const Bigint& num) {
    // Print in reverse (most significant digit first)
    for (int i = num.digits.size() - 1; i >= 0; i--) {
        os << num.digits[i];
    }
    return os;
}