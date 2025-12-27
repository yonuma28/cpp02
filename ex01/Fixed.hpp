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
		int		getRawBits(void) const;
		void 	setRawBits( int const raw );
		int	toInt() const;
		float toFloat() const;
	private:
		int					fixed_point_number_;
		static const int	fractal_bits_;
};

std::ostream &operator<<(std::ostream &out, const Fixed &fixed);

#endif