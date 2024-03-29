/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbroccol <gbroccol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 20:21:00 by gbroccol          #+#    #+#             */
/*   Updated: 2021/01/21 16:20:01 by gbroccol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(void)
{
	this->_hit = 100;
	this->_hit_max = 100;
	this->_energy = 50;
	this->_energy_max = 50;
	this->_level = 1;
	this->_name = "DEFAULT NAME";
	this->_melee_damage = 20;
	this->_ranged_damage = 15;
	this->_armor_damage_reduction = 3;

	std::cout << this->_name << ": " << "\x1b[0m";
	std::cout << "Nice to meet you all. If anyone tries to capture me, I'll incinerate their brain" << std::endl;

	this->printData("Create robot", _name);
}

ScavTrap::ScavTrap(std::string name)
{
	this->_hit = 100;
	this->_hit_max = 100;
	this->_energy = 50;
	this->_energy_max = 50;
	this->_level = 1;
	this->_name = name;
	this->_melee_damage = 20;
	this->_ranged_damage = 15;
	this->_armor_damage_reduction = 3;
	std::cout << this->_name << ": " << "\x1b[0m";
	std::cout << "Should we band together, we'll survive this. Our enemies will not" << std::endl;

	this->printData("Create robot", _name);
}

ScavTrap::ScavTrap( ScavTrap const & ClassToCopy )
{
	std::cout << this->_name << ": " << "\x1b[0m";
	std::cout << "I am here" << std::endl;
	*this = ClassToCopy;
	this->printData("Create robot", _name);
	return ;
}

ScavTrap::~ScavTrap()
{
	std::cout << this->_name_color << this->_name << ": " << "\x1b[0m";
	std::cout << "Bye. See you later" << std::endl;
}

/*
**	get
*/

int					ScavTrap::getHit(void) const
{
	return (this->_hit);
}

int					ScavTrap::getHitMax(void) const
{
	return (this->_hit_max);
}

int					ScavTrap::getEnergy(void) const
{
	return (this->_energy);
}

int					ScavTrap::getEnergyMax(void) const
{
	return (this->_energy_max);
}

int					ScavTrap::getLevel(void) const
{
	return (this->_level);
}

std::string			ScavTrap::getName(void) const
{
	return (this->_name);
}

int					ScavTrap::getMeleeDamage(void) const
{
	return (this->_melee_damage);
}

int					ScavTrap::getRangedDamage(void) const
{
	return (this->_ranged_damage);
}

int					ScavTrap::getArmorDamageReduction(void) const
{
	return (this->_armor_damage_reduction);
}

/*
**	set
*/

void				ScavTrap::setName(std::string name)
{
	std::string		old_name = this->_name;
	
	this->_name = name;
	std::cout << this->_name_color << this->_name << ": " << "\x1b[0m";
	std::cout << "The best name is " << this->_name << std::endl;
	this->printData("Change name", old_name);
	return ;
}

void				ScavTrap::setNameColor(std::string color)
{
	this->_name_color = color;
	return ;
}

/*
**	actions
*/

#include <iomanip>

void				ScavTrap::printData(std::string action, std::string target)
{
	std::cout << "▿▿▿▿▿▿▿▿▿▿▿▿▿▿▿▿▿▿▿▿▿▿▿▿▿▿▿▿▿▿▿▿▿▿▿▿▿▿▿▿▿▿▿▿▿▿▿▿▿▿▿▿▿▿▿▿▿▿▿▿▿▿▿▿▿▿▿▿▿▿▿▿▿▿▿▿▿▿▿▿▿▿▿▿▿▿" << std::endl;
	std::cout << "▹            NAME|          ACTION|          TARGET|   ENERGY POINTS|      HIT POINTS◃" << std::endl;
	std::cout << "▹";
	if (_name.length() > 16)
		std::cout << _name.substr(0, 15) << "." << "|";
	else
		std::cout << std::setw(16) << _name << "|";
	
	std::cout << "\x1b[32m";
	if (action.length() > 16)
		std::cout << action.substr(0, 15) << "." << "\x1b[0m|";
	else
		std::cout << std::setw(16) << action << "\x1b[0m|";
	
	if (target.length() > 16)
		std::cout << target.substr(0, 15) << "." << "|";
	else
		std::cout << std::setw(16) << target << "|";
	
	if (_energy > 99)
		std::cout << "             " << _energy << "|";
	else if (_energy > 9)
		std::cout << "              " << _energy << "|";
	else
		std::cout << "               " << _energy << "|";
	
	if (_hit > 99)
		std::cout << "             " << _hit << "◃";
	else if (_hit > 9)
		std::cout << "              " << _hit << "◃";
	else
		std::cout << "               " << _hit << "◃";
		
	std::cout << std::endl << "▵▵▵▵▵▵▵▵▵▵▵▵▵▵▵▵▵▵▵▵▵▵▵▵▵▵▵▵▵▵▵▵▵▵▵▵▵▵▵▵▵▵▵▵▵▵▵▵▵▵▵▵▵▵▵▵▵▵▵▵▵▵▵▵▵▵▵▵▵▵▵▵▵▵▵▵▵▵▵▵▵▵▵▵▵▵" << std::endl;
}

void				ScavTrap::rangedAttack(std::string const & target)
{
	int		cost = 10;

	if (_hit <= 0)
	{
		std::cout << this->_name_color << this->_name << ": " << "\x1b[0m";
		std::cout << "\x1b[31mSorry, but I'm dead\x1b[0m" << std::endl;
		return ;
	}
	else if (this->_energy < cost)
	{
		std::cout << this->_name_color << this->_name << ": " << "\x1b[0m";
		std::cout << "\x1b[31mI need more energy\x1b[0m" << std::endl;
	}
	else if (this->_energy >= cost)
	{
		std::cout << this->_name_color << this->_name << ": " << "\x1b[0m";
		std::cout << "Looks like my training is paying off!" << std::endl;
		this->_energy = this->_energy - cost;
		this->printData("Ranged attack", target);
	}
}

void				ScavTrap::meleeAttack(std::string const & target)
{
	int		cost = 10;

	if (_hit <= 0)
	{
		std::cout << this->_name_color << this->_name << ": " << "\x1b[0m";
		std::cout << "\x1b[31mSorry, but I'm dead\x1b[0m" << std::endl;
		return ;
	}
	else if (this->_energy < cost)
	{
		std::cout << this->_name_color << this->_name << ": " << "\x1b[0m";
		std::cout << "\x1b[31mI need more energy\x1b[0m" << std::endl;
	}
	else if (this->_energy >= cost)
	{
		std::cout << this->_name_color << this->_name << ": " << "\x1b[0m";
		std::cout << "Fear me, bitches!" << std::endl;
		this->_energy = this->_energy - cost;
		
		this->printData("Melee attack", target);
	}
}

void				ScavTrap::challengeNewcomer(std :: string const & target)
{
	int		cost = 10;

	std::cout << _name_color << _name << ": " << "\x1b[0m";
	if (_hit <= 0)
	{
		std::cout << "\x1b[31mI'm dead\x1b[0m" << std::endl;
		return ;
	}
	else if (_energy >= cost)
	{
		_energy -= cost;
		int				nmb;
		const int		com_nmb = 5;
		std::string		challenges[com_nmb] = 	{ "Ice Bucket Challenge",
													"Skate Boarding Challenge", 
													"Loud music Challenge",
													"No Lights Challenge",
													"Catch An Egg Challenge"};
		std::string		phrases[com_nmb] =		{"It will be funny",
													"Ha-ha-ha",
													"I enjoy that",
													"Wow that's cool",
													"Oh my god"};
		nmb = rand() % com_nmb;
		std::cout << phrases[nmb] << std::endl;
		std::cout << "Energy: " << cost << std::endl;
		printData(challenges[nmb], target);
	}
	else
		std::cout << "I can not challenge him, too few energy" << std::endl;
}

void				ScavTrap::takeDamage(unsigned int amount)
{
	int				amount_int = amount;

	std::cout << _name_color << _name << ": " << "\x1b[0m";
	if (_hit == 0)
	{
		_hit = 0;
		std::cout << "\x1b[31mWhat was that? I am dead\x1b[0m" << std::endl;
		return ;
	}
	else if (amount_int <= 0 || amount_int <= _armor_damage_reduction)
		std::cout << "\x1b[31mHa-ha-ha! It does not work\x1b[0m" << std::endl;
	else if ((_hit - amount_int + _armor_damage_reduction) <= 0)
	{
		_hit = 0;
		std::cout << "\x1b[31mOh no, critical hit\x1b[0m" << std::endl;
		std::cout << "Armor:  " << _armor_damage_reduction << std::endl;
		printData("Take damage", _name);
	}
	else
	{
		_hit = _hit - amount_int + _armor_damage_reduction;
		std::cout << "My servos... are seizing..." << std::endl;	
		std::cout << "Armor:  " << this->_armor_damage_reduction << std::endl;
		this->printData("Take damage", _name);
	}
}

void				ScavTrap::beRepaired(unsigned int amount)
{
	bool		repair = false;

	/* increase hit */
	std::cout << _name_color << _name << ": " << "\x1b[0m";
	if (amount > 0 && amount <= 100 && _hit < (int)_hit_max && (_hit + amount) <= _hit_max)
	{
		repair = true;
		_hit += amount;
		if (_hit > (int)_hit_max)
			_hit = _hit_max;
		std::cout << "I'd call this a successful operation" << std::endl;
	}
	else
		std::cout << "\x1b[31mIt is impossible\x1b[0m" << std::endl;
	
	/* increase energy */
	std::cout << _name_color << "           " << "\x1b[0m";
	if (amount > 0 && amount <= _energy_max && _energy < (int)_energy_max && (_energy + amount) <= _energy_max)
	{
		repair = true;
		_energy += amount;
		if (_energy > (int)_energy_max)
			_energy = _energy_max;
		std::cout << "Wow!!! To be honest, I can't believe I survived this long" << std::endl; // All systems green!
	}
	else
		std::cout << "\x1b[31mIt is impossible\x1b[0m" << std::endl; // Can not increase energy
	if (repair)
		printData("Repair", _name);
}

/*
**	overload
*/

ScavTrap			&ScavTrap::operator=(ScavTrap const &src)
{
	this->_hit = src.getHit();
	this->_hit_max = src.getHitMax();
	this->_energy = src.getEnergy();
	this->_energy_max = src.getEnergyMax();
	this->_level = src.getLevel();
	this->_name = src.getName();
	this->_melee_damage = src.getMeleeDamage();
	this->_ranged_damage = src.getRangedDamage();
	this->_armor_damage_reduction = src.getArmorDamageReduction();
	return *this;
}
