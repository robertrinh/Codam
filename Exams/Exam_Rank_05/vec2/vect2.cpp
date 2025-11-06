#include "vect2.hpp"

vect2::vect2()
{
	_elements[0] = 0;
	_elements[1] = 0;
}

vect2::vect2(int x, int y)
{
	_elements[0] = x;
	_elements[1] = y;
}

vect2 vect2::operator+(const vect2 &src) const
{
	return vect2(_elements[0] + src._elements[0], _elements[1] + src._elements[1]);
}

vect2 vect2::operator-(const vect2& src) const
{
	return vect2(_elements[0] - src._elements[0], _elements[1] - src._elements[1]);
}

vect2 vect2::operator*(int scalar) const
{
	return vect2(_elements[0] * scalar, _elements[1] * scalar);
}

vect2 vect2::operator-() const
{
	return vect2(-_elements[0], -_elements[1]);
}

//* prefix (++v)
vect2& vect2::operator++()
{
	++(_elements[0]);
	++(_elements[1]);
	return *this;
}

//* postfix (v++)
vect2 vect2::operator++(int)
{
	vect2 temp(*this);
	++(*this);
	return temp;
}

//* prefix (--v)
vect2& vect2::operator--()
{
	--(_elements[0]);
	--(_elements[1]);
	return *this;
}

vect2 vect2::operator--(int)
{
	vect2 temp(*this);
	--(*this);
	return temp;
}

vect2& vect2::operator+=(const vect2& src)
{
	_elements[0] += src._elements[0];
	_elements[1] += src._elements[1];
	return *this;
}

vect2& vect2::operator-=(const vect2& src)
{
	_elements[0] -= src._elements[0];
	_elements[1] -= src._elements[1];
	return *this;
}

vect2& vect2::operator*=(int scalar)
{
	_elements[0] *= scalar;
	_elements[1] *= scalar;
	return *this;
}

int& vect2::operator[](int index)
{
	return _elements[index];
}

const int& vect2::operator[](int index) const
{
	return _elements[index];
}

bool vect2::operator==(const vect2& src) const
{
	return (_elements[0] == src._elements[0] &&
			_elements[1] == src._elements[1]);
}

bool vect2::operator!=(const vect2& src) const
{
	return !(*this != src);
}

vect2 operator*(int scalar, const vect2& src)
{
	return src * scalar;
}

std::ostream &operator<<(std::ostream &out, const vect2 &src)
{
	out << "{" << src._elements[0] << ", " << src._elements[1] << "}" << std::endl;
	return out;
}