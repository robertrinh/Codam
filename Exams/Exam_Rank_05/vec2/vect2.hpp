#pragma once

#include <iostream>

class vect2 {
private:
	int _elements[2];
public:
	vect2();
	vect2(int x, int y);
	vect2(const vect2& src) = default;
	vect2& operator=(const vect2& src) = default;
	
	//arithmetic
	vect2 operator+(const vect2& src) const;
	// vect2 operator-(const vect2& src) const;
	// vect2 operator*(int scalar) const;
	
	// vect2 operator-() const;

	// // (in)(de)crementing
	// vect2& operator++();
	// vect2 operator++(int);
	// vect2& operator--();
	// vect2 operator--(int);

	// // compound
	// vect2& operator+=(const vect2& src);
	// vect2& operator-=(const vect2& src);
	// vect2& operator*=(int scalar);

	// int& operator[](int index);
	// const int& operator[](int index) const;

	// bool operator==(const vect2& src) const;
	// bool operator!=(const vect2& src) const;

	friend std::ostream& operator<<(std::ostream& out, const vect2& src);
};

