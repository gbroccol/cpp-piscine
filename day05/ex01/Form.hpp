/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbroccol <gbroccol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/29 15:43:51 by gbroccol          #+#    #+#             */
/*   Updated: 2021/02/05 13:30:20 by gbroccol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include <stdexcept>
# include <string>

# include "Bureaucrat.hpp"

# define LOWEST_GRADE 150
# define HIGHEST_GRADE 1

class Bureaucrat;

class Form
{
	public:

		Form( void );
		Form(std::string name, int sign, int execute);
		Form( Form const & src );
		~Form( void );

		Form &		operator=( Form const & rhs );

		class GradeTooHighException : public std::exception
		{
			public:
				virtual const char* 	what(void) const throw(); 
		};
		
		class GradeTooLowException : public std::exception
		{
			public:
				virtual const char* 	what(void) const throw(); 
		};

		class NullException : public std::exception
		{
			public:
				virtual const char* 	what(void) const throw(); 
		};

		/* get */
		std::string		 				getName(void) const;
		bool							getValue(void) const;
		int								getSignGrade(void) const;
		int								getExecuteGrade(void) const;

		void							beSigned(Bureaucrat &person);

	private:
	
		std::string const			_Name;
		int	const					_SignGrade;
		int	const					_ExecuteGrade;
		bool						_Value;

};

std::ostream &				operator<<( std::ostream & o, Form const & i );

#endif /* ************************************************************ FORM_H */