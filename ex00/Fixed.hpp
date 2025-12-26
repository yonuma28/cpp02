#ifndef MY_FIRST_CLASS
# define MY_FIRST_CLASS

# include <iostream>

class	Fixed
{
	public:
		// OCM
		Fixed();
		~Fixed();
		Fixed(const Fixed& copy);
		Fixed&	operator=(const Fixed& other);

		/*
		 * @brief 固定小数点の生の値を返す
		 * @return int  生のビット値
		 */
		int 	getRawBits( void ) const;

		/**
		 * @brief 固定小数点数の生の値を設定する
		 * @param raw 設定する生のビット値
		*/
		void 	setRawBits( int const raw );

	private:
		int					fixed_point_number_;
		static const int	fractal_bits_ = 8;
};

#endif // MY_FIRST_CLASS
