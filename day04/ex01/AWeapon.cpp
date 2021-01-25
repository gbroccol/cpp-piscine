/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AWeapon.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbroccol <gbroccol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 14:01:21 by gbroccol          #+#    #+#             */
/*   Updated: 2021/01/25 19:54:22 by gbroccol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AWeapon.hpp"

AWeapon::AWeapon(void) {}

AWeapon::AWeapon(std::string const & name, int apcost, int damage) : _Name(name), _Damage(damage), _APCost(apcost)
{
	
}

AWeapon::AWeapon( AWeapon const & ClassToCopy )
{
	*this = ClassToCopy;
	return ;
}

AWeapon::~AWeapon()
{
	
}

/*
** get
*/

int 					AWeapon::getAPCost() const { return (_APCost); }
int						AWeapon::getDamage() const { return (_Damage); }
std::string				AWeapon::getName() const { return (_Name); }

/*
**	overload
*/

AWeapon					&AWeapon::operator=(AWeapon const &src)
{
	_Name = src.getName();
	_APCost = src.getAPCost();
	_Damage = src.getDamage();
	return *this;
}
