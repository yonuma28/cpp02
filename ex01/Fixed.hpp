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
		int	toInt() const;
		float toFloat() const;
	private:
		int					fixed_point_number_;
		static const int	fractal_bits_ = 8;
};

std::ostream &operator<<(std::ostream &out, const Fixed &fixed);