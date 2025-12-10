/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonuma <yonuma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/06 18:43:58 by yonuma            #+#    #+#             */
/*   Updated: 2025/12/10 15:09:42 by yonuma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Fixed.hpp"

int main(void)
{
	Fixed		a;
	std::cout << "足し算" << std::endl;
	std::cout << "5.05 + 2 = ";
	Fixed const b( Fixed( 5.05f ) + Fixed( 2 ));
	std::cout << b << std::endl;	
	std::cout << "引き算" << std::endl;
	std::cout << "5.05 - 2 = ";
	Fixed const c( Fixed( 5.05f ) - Fixed( 2 ));
	std::cout << c << std::endl;	
	std::cout << c << std::endl;	
	std::cout << "掛け算" << std::endl;
	std::cout << "5.05 * 2 = " ;
	Fixed const d( Fixed( 5.05f ) * Fixed( 2 ));
	std::cout << d << std::endl;	
	std::cout << "割り算" << std::endl;
	std::cout << "5.05 / 2 = ";
	Fixed const e( Fixed( 5.05f ) / Fixed( 2 ));
	std::cout << e << std::endl;

	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;

	std::cout << b << std::endl;
	std::cout << Fixed::max( a, b ) << std::endl;

	return (0);
}
