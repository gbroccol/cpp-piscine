/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbroccol <gbroccol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/17 21:47:52 by gbroccol          #+#    #+#             */
/*   Updated: 2021/01/18 19:49:14 by gbroccol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int Fixed::bits = 8;

Fixed::Fixed(void) : value(0)
{
	std::cout << "\x1b[31mDefault constructor called\x1b[0m" << std::endl;
	return ;
}

Fixed::Fixed(Fixed const & new_fixed)
{
	std::cout << "\x1b[31mCopy constructor called\x1b[0m" << std::endl;
	*this = new_fixed;
	return ;
}

Fixed::~Fixed(void)
{
	std::cout << "\x1b[31mDestructor called\x1b[0m" << std::endl;
	return ;
}

Fixed			&Fixed::operator=(Fixed const &new_fixed)
{
	std::cout << "\x1b[36mAssignation operator called\x1b[0m" << std::endl;
	this->value = new_fixed.getRawBits();
	return *this;
}

int 			Fixed::getRawBits( void ) const{
	std::cout << "\x1b[32mgetRawBits member function called\x1b[0m" << std::endl;
	return this->value;
}

void			Fixed::setRawBits( int const raw)
{
	std::cout << "\x1b[32msetRawBits member function called\x1b[0m" << std::endl;
	this->value = raw;
	return;
}
