/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonuma <yonuma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/06 12:52:36 by yonuma            #+#    #+#             */
/*   Updated: 2025/12/06 12:52:36 by yonuma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Fixed.hpp"

Fixed::Fixed(void)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;
}

int	Fixed::getRawBits(void)	const
{
	std::cout << "getRawBits member function called" << std::endl;
	return fractal_bits_;
}

void Fixed::setRawBits(int const raw) {
    fixed_point_number_ = raw;
}


Fixed::Fixed(const Fixed& copy)
{
	std::cout << "Copy constructor called" << std::endl;
	fixed_point_number_ = copy.fractal_bits_;
}

Fixed&	Fixed::operator=(const Fixed& other)
{
	std::cout << "Copy assignment operator called." << std::endl;
	if (this != &other)
		fixed_point_number_ = other.getRawBits();
	return *this;
}
