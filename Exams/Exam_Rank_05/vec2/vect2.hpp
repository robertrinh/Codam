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
	vect2 operator-(const vect2& src) const;
	vect2 operator*(int scalar) const;
	
	vect2 operator-() const;

	// (in)(de)crementing
	vect2& operator++(); //* prefix (++v)
	vect2 operator++(int); //* postfix (v++)
	vect2& operator--(); //* prefix (--v)
	vect2 operator--(int); //* postfix (v--)

	// compound
	vect2& operator+=(const vect2& src);
	vect2& operator-=(const vect2& src);
	vect2& operator*=(int scalar);

	int& operator[](int index);
	const int& operator[](int index) const;

	bool operator==(const vect2& src) const;
	bool operator!=(const vect2& src) const;

	friend vect2 operator*(int scalar, const vect2& src);
	friend std::ostream& operator<<(std::ostream& out, const vect2& src);
};

