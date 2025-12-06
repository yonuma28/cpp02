# ifndef MY_FIRST_CLASS

# include <iostream>
# include <string>

class	Fixed
{
	public:
		Fixed();
		~Fixed();
		int 	getRawBits( void ) const;
		void 	setRawBits( int const raw );
		Fixed(const Fixed& copy);
		Fixed&	operator=(const Fixed& other);
	private:
		int					fixed_point_number_;
		static const int	fractal_bits_ = 8;
};

# endif // MY_FIRST_CLASS