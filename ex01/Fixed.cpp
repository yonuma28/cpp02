# include "Fixed.hpp"

const int Fixed::fractal_bits_ = 8;

Fixed::Fixed() : fixed_point_number_(0)
{
	fixed_point_number_ = 0;
	std::cout << "Default constructor called" << std::endl;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const int	input)
{
	std::cout << "Int constructor called" << std::endl;
	fixed_point_number_ = input << fractal_bits_;
}

Fixed::Fixed(const float input) 
{
	std::cout << "Float constructor called" << std::endl;
    float scale = (1 << fractal_bits_);
    float scaled_and_rounded = roundf(input * scale);
    fixed_point_number_ = (int)scaled_and_rounded;
}

Fixed::Fixed(const Fixed& copy)
{
	std::cout << "Copy constructor called" << std::endl;
	fixed_point_number_ = copy.getRawBits();
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
