# include "Fixed.hpp"

int	Fixed::getRawBits(void)	const
{
	std::cout << "getRawBits member function called" << std::endl;
	return fractal_bits_;
}

void Fixed::setRawBits(int const raw) {
    fixed_point_number_ = raw;
}


Fixed  Fixed::operator*(const Fixed& other) const
{
    long long tmp = (long long)fixed_point_number_ * ;
}

