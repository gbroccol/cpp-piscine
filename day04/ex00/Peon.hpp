/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Peon.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbroccol <gbroccol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 11:55:47 by gbroccol          #+#    #+#             */
/*   Updated: 2021/01/25 13:35:08 by gbroccol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PEON_HPP
#define PEON_HPP

#include <iostream>
#include <iomanip>
#include "Victim.hpp"

class Peon : public Victim
{
private:

	Peon(void);												// CONONICAL FORM

public:
	
	Peon( std::string name);	
	Peon( Peon const & ClassToCopy );						// CONONICAL FORM
	virtual ~Peon();										// CONONICAL FORM

	virtual void			getPolymorphed() const;

	/* overload */
	Peon					&operator=(Peon const & src);		// CONONICAL FORM

};

#endif