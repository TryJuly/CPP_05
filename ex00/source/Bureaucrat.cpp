/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: strieste <strieste@student.42.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/13 14:49:58 by strieste          #+#    #+#             */
/*   Updated: 2026/03/18 09:40:56 by strieste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::~Bureaucrat() { return ; }
Bureaucrat::Bureaucrat(): _name("JuniorIT"), _grade(150) { return ; }
Bureaucrat::Bureaucrat(Bureaucrat const &copy): _name(copy.getName()), _grade(copy.getGrade()) { return ; }

unsigned int const	&Bureaucrat::getGrade() const { return (this->_grade); }
std::string const	&Bureaucrat::getName() const { return(this->_name); }
const char			*Bureaucrat::GradeTooLowException::what() const throw() { return "Grade too low !\n"; }
const char			*Bureaucrat::GradeTooHighException::what() const throw() { return "Grade too High !\n"; }

Bureaucrat::Bureaucrat(std::string& name, unsigned int grade): _name(name)
{
	try
	{
		if (grade > 150)
			throw (Bureaucrat::GradeTooLowException());
		else if (grade < 1)
			throw (Bureaucrat::GradeTooHighException());
		this->_grade = grade;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what();
	}
	return ;
}

void	Bureaucrat::increment( void )
{
	try
	{
		if (this->_grade == 1)
			throw (Bureaucrat::GradeTooHighException());
		this->_grade--;
	}
	catch (Bureaucrat::GradeTooHighException &e)
	{
		std::cerr << e.what();
	}
	return ;
}

void	Bureaucrat::decrement( void )
{
	try
	{
		if (this->_grade == 150)
			throw (Bureaucrat::GradeTooLowException());
		this->_grade++;
	}
	catch (Bureaucrat::GradeTooLowException &e)
	{
		std::cerr << e.what();
	}
	return ;
}

Bureaucrat&	Bureaucrat::operator=(Bureaucrat const &copy)
{
	if (this != &copy)
		this->_grade = copy.getGrade();
	return (*this);
}

std::ostream	&operator<<(std::ostream &out, Bureaucrat const &c)
{
	out << c.getName() << ", bureaucrate grade " << c.getGrade() << "." << std::endl;
	return (out);
}
