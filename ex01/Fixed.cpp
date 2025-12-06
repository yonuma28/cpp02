# include "Fixed.hpp"

Fixed::Fixed()
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const int	input) : fixed_point_number_(input << Fixed::fractal_bits_)
{
	std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float input) 
{
    float scale = (1 << Fixed::fractal_bits_);
    float scaled_and_rounded = roundf(input * scale);
    fixed_point_number_ = (int)scaled_and_rounded;
}

Fixed::Fixed(const Fixed& copy) : fixed_point_number_(copy.fixed_point_number_) 
{
    std::cout << "Copy constructor called" << std::endl;
}

int	Fixed::getRawBits(void) const
{
	return fixed_point_number_;
}

Fixed& Fixed::operator=(const Fixed& other)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other)
		fixed_point_number_ = other.getRawBits();
	return *this;
}

int	Fixed::toInt(void) const
{
	return (int)fixed_point_number_ >> Fixed::fractal_bits_;
}

float Fixed::toFloat(void)	const
{
	float scale = (float)(1 << Fixed::fractal_bits_);
	return (float)fixed_point_number_ / scale;
}

std::ostream &operator<<(std::ostream &out, const Fixed &fixed) {
    out << fixed.toFloat();
    return out;
}
