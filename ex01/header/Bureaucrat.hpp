/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: strieste <strieste@student.42.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/13 14:43:06 by strieste          #+#    #+#             */
/*   Updated: 2026/03/20 07:05:19 by strieste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <string>
# include <iostream>
# include <exception>
# include "Form.hpp"

class Form;

class Bureaucrat
{
	public:
		Bureaucrat();
		Bureaucrat(const std::string& name, int grade);
		Bureaucrat(Bureaucrat const &copy);
		~Bureaucrat();

		Bureaucrat&	operator=(Bureaucrat const &copy);
		void	incrementGrade( void );
		void	decrementGrade( void );
		void	signForm(Form &form);

		std::string const		&getName() const;
		int						getGrade() const;

		class	GradeTooHighException;
		class	GradeTooLowException;

		private:
		std::string const	_name;
		int		_grade;
		
};

std::ostream	&operator<<(std::ostream &out, Bureaucrat const &c);

class	Bureaucrat::GradeTooHighException: public std::exception{
	public:
		const char	*what() const throw();
};

class	Bureaucrat::GradeTooLowException: public std::exception{
	public:
		const char	*what() const throw();
};

#endif
