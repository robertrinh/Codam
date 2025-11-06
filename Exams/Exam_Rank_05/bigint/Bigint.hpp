#pragma once

#include <string>
#include <iostream>

class Bigint {
private:
    std::string _digits;  //* stored REVERSED (123 -> "321")
    
    void _trim();  //* remove leading zeros
public:
    Bigint();
    Bigint(int n);
    
    //* arithmetic
    Bigint operator+(const Bigint& other) const;
    Bigint& operator+=(const Bigint& other);
    
    //* increment
    Bigint& operator++();       //* prefix (++a)
    Bigint operator++(int);     //* postfix (a++)
    
    //* digit shifts (NOT bit shifts!)
    Bigint operator<<(int shift) const;
    Bigint& operator<<=(int shift);
    Bigint operator>>(int shift) const;
    Bigint& operator>>=(int shift);
    
    //* comparison
    bool operator==(const Bigint& other) const;
    bool operator!=(const Bigint& other) const;
    bool operator<(const Bigint& other) const;
    bool operator>(const Bigint& other) const;
    bool operator<=(const Bigint& other) const;
    bool operator>=(const Bigint& other) const;
    
    friend std::ostream& operator<<(std::ostream& os, const Bigint& b);
};