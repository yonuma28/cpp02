/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonuma <yonuma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/06 12:52:36 by yonuma            #+#    #+#             */
/*   Updated: 2025/12/26 15:19:28 by yonuma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Fixed.hpp"

Fixed::Fixed(void) : fixed_point_number_(0)
{
	fixed_point_number_ = 0;
	std::cout << "Default constructor called" << std::endl;
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;
}

int	Fixed::getRawBits(void)	const
{
	std::cout << "getRawBits member function called" << std::endl;
	return fixed_point_number_;
}

void	Fixed::setRawBits(int const raw)
{
	fixed_point_number_ = raw;
}


Fixed::Fixed(const Fixed& copy)
{
	std::cout << "Copy constructor called" << std::endl;
<<<<<<< HEAD
	fixed_point_number_ = copy.getRawBits();
=======
	*this = copy;
>>>>>>> 5f0d622 (modified: 要件に合わせるためにの微細な修正)
}

Fixed&	Fixed::operator=(const Fixed& other)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other)
		fixed_point_number_ = other.getRawBits();
	return *this;
}
