/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvivian <pvivian@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/10 20:16:32 by pvivian           #+#    #+#             */
/*   Updated: 2021/01/13 15:24:42 by pvivian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <stdexcept>

# define HIGHEST_GRADE 1
# define LOWEST_GRADE 150

class Bureaucrat
{
private:
	char const *	_name;
	unsigned int	_grade;
	Bureaucrat(void);
	
public:
	Bureaucrat(char const * name, int grade);
	Bureaucrat(Bureaucrat const & person);
	~Bureaucrat(void);
	Bureaucrat & operator=(Bureaucrat const & person);

	class GradeTooHighException : public std::exception
	{
	public:
		GradeTooHighException(void);
		virtual ~GradeTooHighException(void) throw();
		virtual const char* what(void) const throw(); 
	};
	
	class GradeTooLowException : public std::exception
	{
	public:
		GradeTooLowException(void);
		virtual ~GradeTooLowException(void) throw();
		virtual const char* what(void) const throw(); 
	};

	char const * getName(void) const;
	unsigned int getGrade(void) const;

	void incrementGrade(void);
	void decrementGrade(void);
};

std::ostream & operator<<(std::ostream & o, Bureaucrat const & src);

#endif
