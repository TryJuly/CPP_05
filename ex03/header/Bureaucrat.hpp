/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: strieste <strieste@student.42.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/13 14:43:06 by strieste          #+#    #+#             */
/*   Updated: 2026/03/18 11:49:04 by strieste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <string>
# include <iostream>
# include <exception>
# include "AForm.hpp"

class AForm;

class Bureaucrat
{
	public:
		Bureaucrat();
		Bureaucrat(std::string& name, unsigned int grade);
		Bureaucrat(Bureaucrat const &copy);
		~Bureaucrat();

		Bureaucrat&	operator=(Bureaucrat const &copy);
		void	increment( void );
		void	decrement( void );
		void	signForm(AForm &form);
		void	executeForm(AForm const &form);

		std::string const		&getName() const;
		unsigned int const		&getGrade() const;

		class	GradeTooHighException;
		class	GradeTooLowException;

		private:
		std::string const	_name;
		unsigned int	_grade;
		
};

std::ostream	&operator<<(std::ostream &out, Bureaucrat const &c);

class	Bureaucrat::GradeTooLowException: public std::exception
{
	public:
		const char	*what() const throw();
};

class	Bureaucrat::GradeTooHighException: public std::exception
{
	public:
		const char	*what() const throw();
};

#endif
