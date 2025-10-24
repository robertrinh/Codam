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

std::ostream &operator<<(std::ostream &out, const vect2 &src)
{
	out << "{" << src._elements[0] << ", " << src._elements[1] << "}" << std::endl;
	return out;
}