/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbroccol <gbroccol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/29 15:43:51 by gbroccol          #+#    #+#             */
/*   Updated: 2021/02/04 17:09:57 by gbroccol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Form::Form() : _Name("Form default"), _SignGrade(HIGHEST_GRADE), _ExecuteGrade(LOWEST_GRADE), _Value(false) {}

Form::Form(std::string name, int sign, int execute) : _Name(name), _SignGrade(sign), _ExecuteGrade(execute), _Value(false)
{
	if (sign > LOWEST_GRADE || execute > LOWEST_GRADE)
		throw GradeTooLowException();
	else if (sign < HIGHEST_GRADE || execute < HIGHEST_GRADE)
		throw GradeTooHighException();
}

Form::Form( const Form & src ) : _Name(src.getName()), _SignGrade(src.getSignGrade()), _ExecuteGrade(src.getExecuteGrade()), _Value(src.getValue())
{
	if (this == nullptr)
		throw NullException();
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Form::~Form() {}

/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Form &				Form::operator=( Form const & rhs )
{
	if (this == nullptr)
		throw NullException();
	
	if ( this != &rhs )
		_Value = rhs.getValue();
	return *this;
}

std::ostream &			operator<<( std::ostream & o, Form const & i )
{
	if (i.getValue())
		o << i.getName() << ", form is signed.";
	else
		o << i.getName() << ", form is unsigned.";
	o << " Value to sign is " << i.getSignGrade();
	o << ". Value to execute is " << i.getExecuteGrade() << std::endl;
	return o;
}

/*
** --------------------------------- EXEPTIONS ----------------------------------
*/

const char * Form::GradeTooHighException::what(void) const throw()
{
	return "Invalid argument: too high grade";
}

const char * Form::GradeTooLowException::what(void) const throw()
{
	return "Invalid argument: too low grade";
}

const char * Form::NullException::what(void) const throw()
{
	return "Error. Argument is NULL";
}

/*
** --------------------------------- GET ----------------------------------
*/

std::string		 				Form::getName(void) const
{
	if (this == nullptr)
		throw NullException();
	return(_Name);
}

bool							Form::getValue(void) const
{
	if (this == nullptr)
		throw NullException();
	return(_Value);
}

int								Form::getSignGrade(void) const
{
	if (this == nullptr)
		throw NullException();
	return(_SignGrade);
}

int								Form::getExecuteGrade() const
{
	if (this == nullptr)
		throw NullException();
	return(_ExecuteGrade);
}


/*
** --------------------------------- METHODS ----------------------------------
*/

void							Form::beSigned(Bureaucrat &person)
{
	if (this == nullptr)
		throw NullException();
	if (person.getGrade() <= _SignGrade)
	{
		if (person.signForm(*this) == true)
			_Value = true;
	}
	else
		throw GradeTooLowException();
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */