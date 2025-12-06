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
		int		raw_;
};

# endif // MY_FIRST_CLASS