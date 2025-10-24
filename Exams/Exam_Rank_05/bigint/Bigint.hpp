#ifndef Bigint_HPP
#define Bigint_HPP

#include <string>
#include <iostream>

class Bigint {
private:
    std::string digits;
    void removeLeadingZeros();

public:
    // Constructors (Rule of 3 satisfied with defaults)
    Bigint();                          // Default: 0
    Bigint(int n);                     // From integer
    Bigint(const std::string& s);      // From string
    
    // Arithmetic
    Bigint operator+(const Bigint& other) const;
    Bigint& operator+=(const Bigint& other);
    Bigint operator-(const Bigint& other) const;  // For completeness
    
    // Increment
    Bigint& operator++();              // Prefix: ++a
    Bigint operator++(int);            // Postfix: a++
    
    // Digit shift (NOT bit shift)
    Bigint operator<<(int shift) const;   // Multiply by 10^shift
    Bigint& operator<<=(int shift);
    Bigint operator>>(int shift) const;   // Divide by 10^shift
    Bigint& operator>>=(int shift);
    
    // Comparison
    bool operator==(const Bigint& other) const;
    bool operator!=(const Bigint& other) const;
    bool operator<(const Bigint& other) const;
    bool operator>(const Bigint& other) const;
    bool operator<=(const Bigint& other) const;
    bool operator>=(const Bigint& other) const;
    
    friend std::ostream& operator<<(std::ostream& os, const Bigint& num);
};

#endif