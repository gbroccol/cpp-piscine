/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   A.cpp                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbroccol <gbroccol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/08 14:56:23 by gbroccol          #+#    #+#             */
/*   Updated: 2021/02/09 13:54:05 by gbroccol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "A.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

A::A()
{
}

// A::A( const A & src )
// {
// }


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

A::~A()
{
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

// A &				A::operator=( A const & rhs )
// {
// 	//if ( this != &rhs )
// 	//{
// 		//this->_value = rhs.getValue();
// 	//}
// 	return *this;
// }

// std::ostream &			operator<<( std::ostream & o, A const & i )
// {
// 	//o << "Value = " << i.getValue();
// 	return o;
// }


/*
** --------------------------------- METHODS ----------------------------------
*/

std::string			A::getType(void) { return ("A"); }

/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */