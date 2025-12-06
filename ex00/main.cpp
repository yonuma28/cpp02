/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonuma <yonuma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/06 12:46:24 by yonuma            #+#    #+#             */
/*   Updated: 2025/12/06 12:46:24 by yonuma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Fixed.hpp"

int main(void)
{
	std::cout << "  create Fixed a" << std::endl;
	Fixed	a;

	std::cout << "  create Fixed b" << std::endl;
	Fixed	b( a );

	std::cout << "  create Fixed c" << std::endl;
	Fixed	c;

	std::cout << "  action : c = b" << std::endl;
	c = b;

	std::cout << "  print getRawBits" << std::endl;
	std::cout << a.getRawBits() << std::endl;
	std::cout << b.getRawBits() << std::endl;
	std::cout << c.getRawBits() << std::endl;

	return (0);
}
