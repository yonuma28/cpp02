/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonuma <yonuma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/06 12:46:24 by yonuma            #+#    #+#             */
/*   Updated: 2025/12/27 15:11:33 by yonuma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "Fixed.hpp"

int	main(void)
{
	std::cout << "Fixed a;" << std::endl;
	Fixed a;
	std::cout << "\nFixed b(a);" << std::endl;
	Fixed b( a );
	std::cout << "\nFixed c; c = b;" << std::endl;
	Fixed c;

	c = b;

	std::cout << std::endl;

	std::cout << a.getRawBits() << std::endl;
	std::cout << b.getRawBits() << std::endl;
	std::cout << c.getRawBits() << std::endl;
	return 0;
}
