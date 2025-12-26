#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cmath>

class	Fixed
{
	public:
		Fixed();
		~Fixed();
		Fixed(const int);
		Fixed(const float);
		Fixed(const Fixed& copy);
		Fixed& operator=(const Fixed& other);
		int			getRawBits(void) const;
		int			toInt(void) const;
		float		toFloat(void) const;
	private:
		int					fixed_point_number_;
		static const int	fractal_bits_ = 8;
};

std::ostream &operator<<(std::ostream &out, const Fixed &fixed);

#endif