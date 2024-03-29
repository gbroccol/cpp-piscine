/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbroccol <gbroccol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/17 21:48:04 by gbroccol          #+#    #+#             */
/*   Updated: 2021/01/18 20:02:39 by gbroccol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

class Fixed
{
private:
	
	int					value; 							// to store the fixed point value
	static const int	bits; 							// to store the number of fractional bits. This constant will always be the litteral 8.

public:
	
	Fixed( void );										// CONONICAL FORM
	Fixed( Fixed const & new_fixed );					// CONONICAL FORM
	~Fixed( void );										// CONONICAL FORM

	int			getRawBits(void) const; 				// returns the raw value of the fixed point value
	void		setRawBits( int const raw );			// sets the raw value of the fixed point value.
	Fixed		& operator=(Fixed const & src);			// CONONICAL FORM
};

#endif
